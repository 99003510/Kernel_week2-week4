#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/kfifo.h>
//#include <linux/wait.h>
#include <asm/ioctl.h>

#define IOC_MAGIC 'p'
#define MY_IOCTL_LEN _IO(IOC_MAGIC, 1)
#define MY_IOCTL_AVAIL _IO(IOC_MAGIC, 2)
#define MY_IOCTL_RESET _IO(IOC_MAGIC, 3)

//struct device *pdev;
struct class *pclass;
unsigned char *pbuffer;

#define MAX_SIZE 1024

//struct kfifo kfifo;
dev_t pdevid;
//struct cdev cdev;

int tbuf;
int ret;
typedef struct priv_obj {
    struct cdev cdev;
    struct kfifo kfifo;
    struct device* pdev;
    struct list_head *entry;
}PRIV_OBJ;

LIST_HEAD(mydevlist);

int ndevices=5;
module_param(ndevices,int, S_IRUGO);

