#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

static struct gpio buttons[] = {
				{ 17, GPIOF_IN, "BUTTON 1" },
				{ 18, GPIOF_IN, "BUTTON 2" },
};

static int button_irqs[] = { -1, -1 };


static irqreturn_t button_isr(int irq, void *data)
{
				printk(KERN_NOTICE "Interrupt...gpio value: %d\n", gpio_get_value(buttons[0].gpio));

				return IRQ_HANDLED;
}


static int __init pikeybrd_init(void)
{
				int ret = 0;
				ret     = gpio_request_array(buttons, ARRAY_SIZE(buttons));

				if (ret) {
								printk(KERN_ERR "Unable to request GPIOs for BUTTONs: %d\n", ret);
								return 0;
				}

				ret = gpio_to_irq(buttons[0].gpio);

				if(ret < 0) {
								printk(KERN_ERR "Unable to request IRQ: %d\n", ret);
								goto fail;
				}

				button_irqs[0] = ret;

				ret = request_irq(button_irqs[0], button_isr, IRQF_TRIGGER_RISING | IRQF_DISABLED, "pikeybrd#button1", NULL);

				if(ret) {
								printk(KERN_ERR "Unable to request IRQ: %d\n", ret);
								goto fail1;
				}

				return 0;

fail1:
				free_irq(button_irqs[0], NULL);
fail:
				gpio_free_array(buttons, ARRAY_SIZE(buttons));

				return ret;
}

static void __exit pikeybrd_exit(void)
{
				gpio_set_value(buttons[0].gpio, 0);
				free_irq(button_irqs[0], NULL);
				gpio_free_array(buttons, ARRAY_SIZE(buttons));
}

MODULE_LICENSE("GPL");

module_init(pikeybrd_init);
module_exit(pikeybrd_exit);

