#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vijayapradap M <vijaypradam@gmail.com>");
MODULE_DESCRIPTION("A simple kernel program to register a module with device number");

dev_t dev = MKDEV(46, 0);

/**
 * @brief This function will be called, when the module opens the file
 */
static int deviceOpen(struct inode *device_file, struct file *instance) {
    printk(KERN_INFO "device opened successfully\n");
    return 0;
}

/**
 * @brief This function will be called, when the modules closes the file
 */
static int deviceClose(struct inode *device_file, struct file *instance) {
    printk(KERN_INFO "device closed successfully\n");
    return 0;
}

/**
 * @brief File operation structure for function callback initialization
 */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = deviceOpen,
    .release = deviceClose
};

/**
 * @brief This function will be invoked, when kernel object inserted with kernel module list
 */
static int moduleInit(void) {
    printk("hello kernel, inserting my_dev_nr module\n");
    int ret = register_chrdev(MAJOR(dev), "my_dev_nr", &fops);
    if (ret < 0) {
        printk(KERN_ERR "Kernel Module failed to insert...\n");
        return ret;
    }
    printk(KERN_INFO "Major = %d Minor = %d \n",(ret == 0) ? MAJOR(dev) : MAJOR(ret), (ret == 0) ? MINOR(dev) : MINOR(ret));
    printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
    return 0;
}

/**
 * @brief This function will be invoked, when module removed from kernel module list
 */
static void moduleExit(void) {
    printk(KERN_INFO "bye bye kernel\n");
    unregister_chrdev(MAJOR(dev), "my_dev_nr");
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}

module_init(moduleInit);
module_exit(moduleExit);