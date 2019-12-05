#ifndef SPI_H
#define SPI_H

#include <linux/types.h>

struct spi_msg {
				unsigned char addr;	/* slave address        */
				unsigned char flags;
#define SPI_M_RD	0x01
#define SPI_M_WR	0x02	/**< Write mode flag */
#define SPI_M_CSREL	0x04	/**< CS release level at end of the frame  */
#define SPI_M_CS	0x08	/**< CS active level at begining of frame ( default low ) */
#define SPI_M_CPOL	0x10	/**< Clock polarity */
#define SPI_M_CPHA	0x20	/**< Clock Phase */
#define SPI_M_NOADDR	0x80

				unsigned short len;	/* msg length           */
				unsigned char *buf;	/* pointer to msg data  */
				unsigned long clock;
};


#define SPI_MAJOR	98

extern struct bus_type spi_bus_type;

struct spi_driver1 {
				struct spi_ops *ops;
				struct module *owner;
				struct device_driver driver;
				unsigned int minor;
//				spi_ids_t *supported_ids;
};
/*
 * A driver is capable of handling one or more physical devices present on
 * SPI adapters.
 */
//struct spi_driver;

struct spi_ops {
				int (*open) (struct spi_driver1 *);
				int (*command) (struct spi_driver1 *, int cmd, void *arg);
				void (*close) (struct spi_driver1 *);
};

typedef char *spi_ids_t[];
#define SPI_ID_ANY     "* ANY *"
#define SPI_IDS_TABLE_BEGIN static spi_ids_t spi_devices_supported = {
#define SPI_IDS_TABLE_END ,NULL };
#define SPI_IDS &spi_devices_supported




struct spi_adapter;

#define SELECT   	0x01
#define UNSELECT 	0x02
#define BEFORE_READ 	0x03
#define BEFORE_WRITE	0x04
#define AFTER_READ	0x05
#define AFTER_WRITE	0x06

struct spi_algorithm {
				/* textual description */
				char name[32];

				/* perform bus transactions */
				int (*xfer) (struct spi_adapter *, struct spi_msg msgs[], int num);
				int (*chip_cs) (int, void *context);
};

/*
 * spi_adapter is the structure used to identify a physical SPI device along
 * with the access algorithms necessary to access it.
 */
struct spi_adapter {
				/*
				 * This name is used to uniquely identify the adapter.
				 * It should be the same as the module name.
				 */
				char name[32];

				/* the algorithm to access the device */
				struct spi_algorithm *algo;

				/* algorithm-specific data            */
				void *algo_data;

				/* private data                       */
				void *private_data;

				/*  This may be NULL, or should point to the module structure */
				struct module *owner;

				struct semaphore lock;

				void (*select) (struct spi_adapter * this, int onoff);

				/* The alternative way to allocate/free memory. */
				void *(*alloc) (size_t, int);
				void (*free) (const void *);

				/*
				 * Copy data from/to user in case the alternative
				 * alloc/free functions are used.
				 */
				unsigned long (*copy_from_user) (void *to, const void *from_user,
												unsigned long len);
				unsigned long (*copy_to_user) (void *to_user, const void *from,
												unsigned long len);

				struct device dev;
};

extern int spi_add_adapter(struct spi_adapter *);
extern void spi_del_adapter(struct spi_adapter *);

extern int spi_transfer(struct spi_adapter *, struct spi_msg msgs[], int);
//extern int spi_write(struct spi_adapter *, int, const char *, int);
//extern int spi_read(struct spi_adapter *, int, char *, int);

static inline int spi_add_driver(struct spi_driver *driver)
{
				return driver_register(&driver->driver);
}

static inline void spi_del_driver(struct spi_driver *driver)
{
				driver_unregister(&driver->driver);
}

typedef struct {
				unsigned int minor;
				void *private_data;
} spidev_driver_data_t;

static inline void *spi_get_adapdata(struct spi_adapter *dev)
{
				spidev_driver_data_t *dd;

				dd = (spidev_driver_data_t *) dev_get_drvdata(&dev->dev);
				return dd ? dd->private_data : NULL;
}

static inline void spi_set_adapdata(struct spi_adapter *dev, void *data)
{
				spidev_driver_data_t *dd;

				dd = (spidev_driver_data_t *) dev_get_drvdata(&dev->dev);
				if (dd) {
								dd->private_data = data;
				}
}

/**
 * spi_command - send a command to a SPI device driver
 * @client: registered client structure
 * @cmd: device driver command
 * @arg: device driver arguments
 *
 * Ask the SPI device driver to perform some function.  Further information
 * should be sought from the device driver in question.
 *
 * Returns negative error code on failure.
 */
static inline int spi_command(struct spi_driver1 *clnt, int cmd, void *arg)
{
				struct spi_ops *ops = clnt->ops;
				int ret = -EINVAL;

				if (ops && ops->command)
								ret = ops->command(clnt, cmd, arg);

				return ret;
}

static inline int spi_open(struct spi_driver1 *clnt)
{
				struct spi_ops *ops = clnt->ops;
				int ret = 0;

				if (ops && ops->open)
								ret = ops->open(clnt);
				return ret;
}

static inline void spi_close(struct spi_driver1 *clnt)
{
				struct spi_ops *ops = clnt->ops;
				if (ops && ops->close)
								ops->close(clnt);
}

#endif				/* SPI_H */

