#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vijayapradap M <vijaypradam@gmail.com>");
MODULE_DESCRIPTION("A simple kernel program to create a device file with file ops");

dev_t dev = 0;
static struct class *devClass;
static struct cdev cdevTest;

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
    return 0;
}

/**
 * @brief This function will be called, when read ops executed
 */
static ssize_t devWrite(struct file *fp, const char __user *ch, size_t sz, loff_t *loff) {
    pr_info("File write function called\n");
    return sz;
}

/**
 * This structure need to initialized for file operations with callbacks
 */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = devOpen,
    .read = devRead,
    .write = devWrite,
    .release = devClose
};

/**
 * @brief This function will be invoked, when kernel object inserted with kernel module list
 */
static int moduleInit(void) {
    pr_info("hello kernel, inserting my_dev_file module\n");
    int ret = alloc_chrdev_region(&dev, 0, 1, "my_dev_file");
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

    if(IS_ERR(device_create(devClass, NULL, dev, NULL, "my_dev_file"))){
        pr_err("Cannot create the Device\n");
        goto r_device;
    }

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
    cdev_del(&cdevTest);
    device_destroy(devClass, dev);
    class_destroy(devClass);
    unregister_chrdev_region(dev, 1);
    pr_info("Kernel Module Removed Successfully...\n");
}

module_init(moduleInit);
module_exit(moduleExit);