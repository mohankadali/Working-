/*
 * Tiny TTY driver
 *
 * Copyright (C) 2002-2004 Greg Kroah-Hartman (greg@kroah.com)
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, version 2 of the License.
 *
 * This driver shows how to create a minimal tty driver.  It does not rely on
 * any backing hardware, but creates a timer that emulates data being received
 * from some kind of hardware.
 */


#include <linux/config.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/wait.h>
#include <linux/tty.h>
#include <linux/tty_driver.h>
#include <linux/tty_flip.h>
#include <linux/serial.h>
#include <asm/uaccess.h>


#define DRIVER_VERSION "v2.0"
#define DRIVER_AUTHOR "Greg Kroah-Hartman <greg@kroah.com>"
#define DRIVER_DESC "Tiny TTY driver"

/* Module information */
MODULE_AUTHOR( DRIVER_AUTHOR );
MODULE_DESCRIPTION( DRIVER_DESC );
MODULE_LICENSE("GPL");

#define DELAY_TIME		HZ * 2	/* 2 seconds per character */
#define MOHAN_DATA_CHARACTER	't'

#define MOHAN_TTY_MAJOR		240	/* experimental range */
#define MOHAN_TTY_MINORS		4	/* only have 4 devices */

struct mohan_serial {
	struct tty_struct	*tty;		/* pointer to the tty for this device */
	int			open_count;	/* number of times this port has been opened */
	struct semaphore	sem;		/* locks this structure */
	struct timer_list	*timer;

	/* for tiocmget and tiocmset functions */
	int			msr;		/* MSR shadow */
	int			mcr;		/* MCR shadow */

	/* for ioctl fun */
	struct serial_struct	serial;
	wait_queue_head_t	wait;
	struct async_icount	icount;
};

static struct mohan_serial *mohan_table[MOHAN_TTY_MINORS];	/* initially all NULL */


static void mohan_timer(unsigned long timer_data)
{
	struct mohan_serial *mohan = (struct mohan_serial *)timer_data;
	struct tty_struct *tty;
	int i;
	char data[1] = {MOHAN_DATA_CHARACTER};
	int data_size = 1;

	if (!mohan)
		return;

	tty = mohan->tty;

	/* send the data to the tty layer for users to read.  This doesn't
	 * actually push the data through unless tty->low_latency is set */
	for (i = 0; i < data_size; ++i) {
		if (tty->flip.count >= TTY_FLIPBUF_SIZE)
			tty_flip_buffer_push(tty);
		tty_insert_flip_char(tty, data[i], TTY_NORMAL);
	}
	tty_flip_buffer_push(tty);

	/* resubmit the timer again */
	mohan->timer->expires = jiffies + DELAY_TIME;
	add_timer(mohan->timer);
}

static int mohan_open(struct tty_struct *tty, struct file *file)
{
	struct mohan_serial *mohan;
	struct timer_list *timer;
	int index;

	/* initialize the pointer in case something fails */
	tty->driver_data = NULL;

	/* get the serial object associated with this tty pointer */
	index = tty->index;
	mohan = mohan_table[index];
	if (mohan == NULL) {
		/* first time accessing this device, let's create it */
		mohan = kmalloc(sizeof(*mohan), GFP_KERNEL);
		if (!mohan)
			return -ENOMEM;

		init_MUTEX(&mohan->sem);
		mohan->open_count = 0;
		mohan->timer = NULL;

		mohan_table[index] = mohan;
	}

	down(&mohan->sem);

	/* save our structure within the tty structure */
	tty->driver_data = mohan;
	mohan->tty = tty;

	++mohan->open_count;
	if (mohan->open_count == 1) {
		/* this is the first time this port is opened */
		/* do any hardware initialization needed here */

		/* create our timer and submit it */
		if (!mohan->timer) {
			timer = kmalloc(sizeof(*timer), GFP_KERNEL);
			if (!timer) {
				up(&mohan->sem);
				return -ENOMEM;
			}
			mohan->timer = timer;
		}
		mohan->timer->data = (unsigned long )mohan;
		mohan->timer->expires = jiffies + DELAY_TIME;
		mohan->timer->function = mohan_timer;
		add_timer(mohan->timer);
	}

	up(&mohan->sem);
	return 0;
}

static void do_close(struct mohan_serial *mohan)
{
	down(&mohan->sem);

	if (!mohan->open_count) {
		/* port was never opened */
		goto exit;
	}

	--mohan->open_count;
	if (mohan->open_count <= 0) {
		/* The port is being closed by the last user. */
		/* Do any hardware specific stuff here */

		/* shut down our timer */
		del_timer(mohan->timer);
	}
exit:
	up(&mohan->sem);
}

static void mohan_close(struct tty_struct *tty, struct file *file)
{
	struct mohan_serial *mohan = tty->driver_data;

	if (mohan)
		do_close(mohan);
}	

static int mohan_write(struct tty_struct *tty, 
		      const unsigned char *buffer, int count)
{
	struct mohan_serial *mohan = tty->driver_data;
	int i;
	int retval = -EINVAL;

	if (!mohan)
		return -ENODEV;

	down(&mohan->sem);

	if (!mohan->open_count)
		/* port was not opened */
		goto exit;

	/* fake sending the data out a hardware port by
	 * writing it to the kernel debug log.
	 */
	printk(KERN_DEBUG "%s - ", __FUNCTION__);
	for (i = 0; i < count; ++i)
		printk("%02x ", buffer[i]);
	printk("\n");
		
exit:
	up(&mohan->sem);
	return retval;
}

static int mohan_write_room(struct tty_struct *tty) 
{
	struct mohan_serial *mohan = tty->driver_data;
	int room = -EINVAL;

	if (!mohan)
		return -ENODEV;

	down(&mohan->sem);
	
	if (!mohan->open_count) {
		/* port was not opened */
		goto exit;
	}

	/* calculate how much room is left in the device */
	room = 255;

exit:
	up(&mohan->sem);
	return room;
}

#define RELEVANT_IFLAG(iflag) ((iflag) & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK))

static void mohan_set_termios(struct tty_struct *tty, struct termios *old_termios)
{
	unsigned int cflag;

	cflag = tty->termios->c_cflag;

	/* check that they really want us to change something */
	if (old_termios) {
		if ((cflag == old_termios->c_cflag) &&
		    (RELEVANT_IFLAG(tty->termios->c_iflag) == 
		     RELEVANT_IFLAG(old_termios->c_iflag))) {
			printk(KERN_DEBUG " - nothing to change...\n");
			return;
		}
	}

	/* get the byte size */
	switch (cflag & CSIZE) {
		case CS5:
			printk(KERN_DEBUG " - data bits = 5\n");
			break;
		case CS6:
			printk(KERN_DEBUG " - data bits = 6\n");
			break;
		case CS7:
			printk(KERN_DEBUG " - data bits = 7\n");
			break;
		default:
		case CS8:
			printk(KERN_DEBUG " - data bits = 8\n");
			break;
	}
	
	/* determine the parity */
	if (cflag & PARENB)
		if (cflag & PARODD)
			printk(KERN_DEBUG " - parity = odd\n");
		else
			printk(KERN_DEBUG " - parity = even\n");
	else
		printk(KERN_DEBUG " - parity = none\n");

	/* figure out the stop bits requested */
	if (cflag & CSTOPB)
		printk(KERN_DEBUG " - stop bits = 2\n");
	else
		printk(KERN_DEBUG " - stop bits = 1\n");

	/* figure out the hardware flow control settings */
	if (cflag & CRTSCTS)
		printk(KERN_DEBUG " - RTS/CTS is enabled\n");
	else
		printk(KERN_DEBUG " - RTS/CTS is disabled\n");
	
	/* determine software flow control */
	/* if we are implementing XON/XOFF, set the start and 
	 * stop character in the device */
	if (I_IXOFF(tty) || I_IXON(tty)) {
		unsigned char stop_char  = STOP_CHAR(tty);
		unsigned char start_char = START_CHAR(tty);

		/* if we are implementing INBOUND XON/XOFF */
		if (I_IXOFF(tty))
			printk(KERN_DEBUG " - INBOUND XON/XOFF is enabled, "
				"XON = %2x, XOFF = %2x", start_char, stop_char);
		else
			printk(KERN_DEBUG" - INBOUND XON/XOFF is disabled");

		/* if we are implementing OUTBOUND XON/XOFF */
		if (I_IXON(tty))
			printk(KERN_DEBUG" - OUTBOUND XON/XOFF is enabled, "
				"XON = %2x, XOFF = %2x", start_char, stop_char);
		else
			printk(KERN_DEBUG" - OUTBOUND XON/XOFF is disabled");
	}

	/* get the baud rate wanted */
	printk(KERN_DEBUG " - baud rate = %d", tty_get_baud_rate(tty));
}

/* Our fake UART values */
#define MCR_DTR		0x01
#define MCR_RTS		0x02
#define MCR_LOOP	0x04
#define MSR_CTS		0x08
#define MSR_CD		0x10
#define MSR_RI		0x20
#define MSR_DSR		0x40

static int mohan_tiocmget(struct tty_struct *tty, struct file *file)
{
	struct mohan_serial *mohan = tty->driver_data;

	unsigned int result = 0;
	unsigned int msr = mohan->msr;
	unsigned int mcr = mohan->mcr;

	result = ((mcr & MCR_DTR)  ? TIOCM_DTR  : 0) |	/* DTR is set */
             ((mcr & MCR_RTS)  ? TIOCM_RTS  : 0) |	/* RTS is set */
             ((mcr & MCR_LOOP) ? TIOCM_LOOP : 0) |	/* LOOP is set */
             ((msr & MSR_CTS)  ? TIOCM_CTS  : 0) |	/* CTS is set */
             ((msr & MSR_CD)   ? TIOCM_CAR  : 0) |	/* Carrier detect is set*/
             ((msr & MSR_RI)   ? TIOCM_RI   : 0) |	/* Ring Indicator is set */
             ((msr & MSR_DSR)  ? TIOCM_DSR  : 0);	/* DSR is set */

	return result;
}

static int mohan_tiocmset(struct tty_struct *tty, struct file *file,
                         unsigned int set, unsigned int clear)
{
	struct mohan_serial *mohan = tty->driver_data;
	unsigned int mcr = mohan->mcr;

	if (set & TIOCM_RTS)
		mcr |= MCR_RTS;
	if (set & TIOCM_DTR)
		mcr |= MCR_RTS;

	if (clear & TIOCM_RTS)
		mcr &= ~MCR_RTS;
	if (clear & TIOCM_DTR)
		mcr &= ~MCR_RTS;

	/* set the new MCR value in the device */
	mohan->mcr = mcr;
	return 0;
}

static int mohan_read_proc(char *page, char **start, off_t off, int count,
                          int *eof, void *data)
{
	struct mohan_serial *mohan;
	off_t begin = 0;
	int length = 0;
	int i;

	length += sprintf(page, "mohanserinfo:1.0 driver:%s\n", DRIVER_VERSION);
	for (i = 0; i < MOHAN_TTY_MINORS && length < PAGE_SIZE; ++i) {
		mohan = mohan_table[i];
		if (mohan == NULL)
			continue;

		length += sprintf(page+length, "%d\n", i);
		if ((length + begin) > (off + count))
			goto done;
		if ((length + begin) < off) {
			begin += length;
			length = 0;
		}
	}
	*eof = 1;
done:
	if (off >= (length + begin))
		return 0;
	*start = page + (off-begin);
	return (count < begin+length-off) ? count : begin + length-off;
}

#define mohan_ioctl mohan_ioctl_tiocgserial
static int mohan_ioctl(struct tty_struct *tty, struct file *file,
                      unsigned int cmd, unsigned long arg)
{
	struct mohan_serial *mohan = tty->driver_data;

	if (cmd == TIOCGSERIAL) {
		struct serial_struct tmp;

		if (!arg)
			return -EFAULT;

		memset(&tmp, 0, sizeof(tmp));

		tmp.type		= mohan->serial.type;
		tmp.line		= mohan->serial.line;
		tmp.port		= mohan->serial.port;
		tmp.irq			= mohan->serial.irq;
		tmp.flags		= ASYNC_SKIP_TEST | ASYNC_AUTO_IRQ;
		tmp.xmit_fifo_size	= mohan->serial.xmit_fifo_size;
		tmp.baud_base		= mohan->serial.baud_base;
		tmp.close_delay		= 5*HZ;
		tmp.closing_wait	= 30*HZ;
		tmp.custom_divisor	= mohan->serial.custom_divisor;
		tmp.hub6		= mohan->serial.hub6;
		tmp.io_type		= mohan->serial.io_type;

		if (copy_to_user((void __user *)arg, &tmp, sizeof(struct serial_struct)))
			return -EFAULT;
		return 0;
	}
	return -ENOIOCTLCMD;
}
#undef mohan_ioctl

#define mohan_ioctl mohan_ioctl_tiocmiwait
static int mohan_ioctl(struct tty_struct *tty, struct file *file,
                      unsigned int cmd, unsigned long arg)
{
	struct mohan_serial *mohan = tty->driver_data;

	if (cmd == TIOCMIWAIT) {
		DECLARE_WAITQUEUE(wait, current);
		struct async_icount cnow;
		struct async_icount cprev;

		cprev = mohan->icount;
		while (1) {
			add_wait_queue(&mohan->wait, &wait);
			set_current_state(TASK_INTERRUPTIBLE);
			schedule();
			remove_wait_queue(&mohan->wait, &wait);

			/* see if a signal woke us up */
			if (signal_pending(current))
				return -ERESTARTSYS;

			cnow = mohan->icount;
			if (cnow.rng == cprev.rng && cnow.dsr == cprev.dsr &&
			    cnow.dcd == cprev.dcd && cnow.cts == cprev.cts)
				return -EIO; /* no change => error */
			if (((arg & TIOCM_RNG) && (cnow.rng != cprev.rng)) ||
			    ((arg & TIOCM_DSR) && (cnow.dsr != cprev.dsr)) ||
			    ((arg & TIOCM_CD)  && (cnow.dcd != cprev.dcd)) ||
			    ((arg & TIOCM_CTS) && (cnow.cts != cprev.cts)) ) {
				return 0;
			}
			cprev = cnow;
		}

	}
	return -ENOIOCTLCMD;
}
#undef mohan_ioctl

#define mohan_ioctl mohan_ioctl_tiocgicount
static int mohan_ioctl(struct tty_struct *tty, struct file *file,
                      unsigned int cmd, unsigned long arg)
{
	struct mohan_serial *mohan = tty->driver_data;

	if (cmd == TIOCGICOUNT) {
		struct async_icount cnow = mohan->icount;
		struct serial_icounter_struct icount;

		icount.cts	= cnow.cts;
		icount.dsr	= cnow.dsr;
		icount.rng	= cnow.rng;
		icount.dcd	= cnow.dcd;
		icount.rx	= cnow.rx;
		icount.tx	= cnow.tx;
		icount.frame	= cnow.frame;
		icount.overrun	= cnow.overrun;
		icount.parity	= cnow.parity;
		icount.brk	= cnow.brk;
		icount.buf_overrun = cnow.buf_overrun;

		if (copy_to_user((void __user *)arg, &icount, sizeof(icount)))
			return -EFAULT;
		return 0;
	}
	return -ENOIOCTLCMD;
}
#undef mohan_ioctl

/* the real mohan_ioctl function.  The above is done to get the small functions in the book */
static int mohan_ioctl(struct tty_struct *tty, struct file *file,
                      unsigned int cmd, unsigned long arg)
{
	switch (cmd) {
	case TIOCGSERIAL:
		return mohan_ioctl_tiocgserial(tty, file, cmd, arg);
	case TIOCMIWAIT:
		return mohan_ioctl_tiocmiwait(tty, file, cmd, arg);
	case TIOCGICOUNT:
		return mohan_ioctl_tiocgicount(tty, file, cmd, arg);
	}

	return -ENOIOCTLCMD;
}

static struct tty_operations serial_ops = {
	.open = mohan_open,
	.close = mohan_close,
	.write = mohan_write,
	.write_room = mohan_write_room,
	.set_termios = mohan_set_termios,
};

static struct tty_driver *mohan_tty_driver;

static int __init mohan_init(void)
{
	int retval;
	int i;

	/* allocate the tty driver */
	mohan_tty_driver = alloc_tty_driver(MOHAN_TTY_MINORS);
	if (!mohan_tty_driver)
		return -ENOMEM;

	/* initialize the tty driver */
	mohan_tty_driver->owner = THIS_MODULE;
	mohan_tty_driver->driver_name = "mohan_tty";
	mohan_tty_driver->name = "ttty";
	mohan_tty_driver->devfs_name = "tts/ttty%d";
	mohan_tty_driver->major = MOHAN_TTY_MAJOR,
	mohan_tty_driver->type = TTY_DRIVER_TYPE_SERIAL,
	mohan_tty_driver->subtype = SERIAL_TYPE_NORMAL,
	mohan_tty_driver->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_NO_DEVFS,
	mohan_tty_driver->init_termios = tty_std_termios;
	mohan_tty_driver->init_termios.c_cflag = B9600 | CS8 | CREAD | HUPCL | CLOCAL;
	tty_set_operations(mohan_tty_driver, &serial_ops);

	/* hack to make the book purty, yet still use these functions in the
	 * real driver.  They really should be set up in the serial_ops
	 * structure above... */
	mohan_tty_driver->read_proc = mohan_read_proc;
    mohan_tty_driver->tiocmget = mohan_tiocmget;
	mohan_tty_driver->tiocmset = mohan_tiocmset;
	mohan_tty_driver->ioctl = mohan_ioctl;

	/* register the tty driver */
	retval = tty_register_driver(mohan_tty_driver);
	if (retval) {
		printk(KERN_ERR "failed to register mohan tty driver");
		put_tty_driver(mohan_tty_driver);
		return retval;
	}

	for (i = 0; i < MOHAN_TTY_MINORS; ++i)
		tty_register_device(mohan_tty_driver, i, NULL);

	printk(KERN_INFO DRIVER_DESC " " DRIVER_VERSION);
	return retval;
}

static void __exit mohan_exit(void)
{
	struct mohan_serial *mohan;
	int i;

	for (i = 0; i < MOHAN_TTY_MINORS; ++i)
		tty_unregister_device(mohan_tty_driver, i);
	tty_unregister_driver(mohan_tty_driver);

	/* shut down all of the timers and free the memory */
	for (i = 0; i < MOHAN_TTY_MINORS; ++i) {
		mohan = mohan_table[i];
		if (mohan) {
			/* close the port */
			while (mohan->open_count)
				do_close(mohan);

			/* shut down our timer and free the memory */
			del_timer(mohan->timer);
			kfree(mohan->timer);
			kfree(mohan);
			mohan_table[i] = NULL;
		}
	}
}

module_init(mohan_init);
module_exit(mohan_exit);
