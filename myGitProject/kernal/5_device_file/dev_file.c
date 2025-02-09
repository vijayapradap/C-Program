#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/err.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vijayapradap M <vijaypradam@gmail.com>");
MODULE_DESCRIPTION("A simple kernel program to create a device file");

dev_t dev = 0;
static struct class *devClass;

/**
 * @brief This function will be invoked, when kernel object inserted with kernel module list
 */
static int moduleInit(void) {
    pr_info("hello kernel, inserting my_dev_nr module\n");
    int ret = alloc_chrdev_region(&dev, 0, 1, "my_dev_file");
    if (ret < 0) {
        pr_err("Kernel Module failed to insert...\n");
        return ret;
    }
    pr_info("Major = %d Minor = %d \n",(ret == 0) ? MAJOR(dev) : MAJOR(ret), (ret == 0) ? MINOR(dev) : MINOR(ret));
    
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
    device_destroy(devClass, dev);
    class_destroy(devClass);
    unregister_chrdev_region(dev, 1);
    pr_info("Kernel Module Removed Successfully...\n");
}

module_init(moduleInit);
module_exit(moduleExit);