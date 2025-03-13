#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/ioctl.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vijayapradap M <vijaypradam@gmail.com>");
MODULE_DESCRIPTION("A simple kernel program to create a device file with file ops realtime example");

#define mem_size 512

#define WD_VALUE _IOW('a', 'a', uint32_t *)
#define RD_VALUE _IOR('b', 'b', uint32_t *)

dev_t dev = 0;
static struct class *devClass;
static struct cdev cdevTest;
uint8_t *kernel_buff = NULL;

uint32_t output = 0;

/**
 * @brief This function will be called, when file device file opens
 */
static int devOpen(struct inode *inode, struct file *file) {
    pr_info("File opened successfully\n");
    return 0;
}

/**
 * @brief This function will be called, when file device file opens
 */
static int devClose(struct inode *inode, struct file *file) {
    pr_info("File closed successfully\n");
    return 0;
}

/**
 * @brief This function will be called, when read ops executed
 */
static ssize_t devRead(struct file *fp, char __user *ch, size_t sz, loff_t *loff) {
    pr_info("File read function called\n");

    uint8_t len = strlen(kernel_buff);
    if (*loff >= len)
        return 0;

    if (copy_to_user(ch, kernel_buff, len)) {
        pr_err("failed to read\n");
    }
    pr_info("read operation done\n");
    *loff += len;

    return len;
}

/**
 * @brief This function will be called, when read ops executed
 */
static ssize_t devWrite(struct file *fp, const char __user *ch, size_t sz, loff_t *loff) {
    pr_info("File write function called\n");

    if(copy_from_user(kernel_buff, ch, sz)) {
        pr_err("failed to write\n");
    }
    pr_info("write operation done. Data : %s\n", ch);

    return sz;
}

/**
 * @brief This function will be called, when user initate ops with ioctl callback
 */
static long devIoctl(struct file *fd, unsigned int cmd, unsigned long arg) {
    switch (cmd)
    {
        case WD_VALUE:
            if (copy_from_user(&output, (uint32_t *)arg, sizeof(output))) {
                pr_err("failed to write data\n");
            }
            pr_info("value written successfully : %d\n", output);
            break;
        
        case RD_VALUE:
            if (copy_to_user((uint32_t *)arg, &output, sizeof(output))) {
                pr_err("failed to read the data from kernel space\n");
            }
            pr_info("value read done\n");
            break;
        
        default:
            pr_err("invalid command to execute\n");
            break;
    }
    return 0;
}

/**
 * @brief This structure need to initialized for file operations with callbacks
 */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = devOpen,
    .read = devRead,
    .write = devWrite,
    .release = devClose,
    .unlocked_ioctl = devIoctl
};

/**
 * @brief This function will be invoked, when kernel object inserted with kernel module list
 */
static int moduleInit(void) {
    pr_info("hello kernel, inserting my_ioctl module\n");
    int ret = alloc_chrdev_region(&dev, 0, 1, "my_ioctl");
    if (ret < 0) {
        pr_err("Kernel Module failed to insert...\n");
        return ret;
    }
    pr_info("Major = %d Minor = %d \n",(ret == 0) ? MAJOR(dev) : MAJOR(ret), (ret == 0) ? MINOR(dev) : MINOR(ret));
    
    cdev_init(&cdevTest,&fops);

    if (cdev_add(&cdevTest, dev, 1) < 0) {
        pr_err("unable add the cdev for this device\n");
        goto r_device;
    }
    
    devClass = class_create("my_dev_class");
    if(IS_ERR(devClass)){
        pr_err("Cannot create the struct class for device\n");
        goto r_class;
    }

    if(IS_ERR(device_create(devClass, NULL, dev, NULL, "my_ioctl"))) {
        pr_err("Cannot create the Device\n");
        goto r_device;
    }

    kernel_buff = (uint8_t *)kmalloc(mem_size, GFP_KERNEL);
    if (kernel_buff == NULL) {
        pr_err("kernel memory allocation failed\n");
        goto r_class;
    }

    strcpy(kernel_buff, "Hello_World");

    pr_info("Kernel Module Inserted Successfully...\n");
    return 0;
r_class:
    class_destroy(devClass);
r_device:
    unregister_chrdev_region(dev, 1);
    return -1;
}

/**
 * @brief This function will be invoked, when module removed from kernel module list
 */
static void moduleExit(void) {
    pr_info("bye bye kernel\n");
    kfree(kernel_buff);
    cdev_del(&cdevTest);
    device_destroy(devClass, dev);
    class_destroy(devClass);
    unregister_chrdev_region(dev, 1);
    pr_info("Kernel Module Removed Successfully...\n");
}

module_init(moduleInit);
module_exit(moduleExit);