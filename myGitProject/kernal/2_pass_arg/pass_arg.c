#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vijayapradap M <vijaypradam@gmail.com>");
MODULE_DESCRIPTION("A simple kernel program to pass arg from userspace");

dev_t dev = MKDEV(46, 0);

int val, arr_val[4], cbVal = 0;
char *pVal;

module_param(val, int, S_IWUSR);
module_param(pVal, charp, S_IWUSR);
module_param_array(arr_val, int, NULL, S_IWUSR);

/**
 * @brief This function will be invoked, when module_param_cb triggered from userspace
 */
int notifyParam(const char *cval, const struct kernel_param *kp) {
    int res = param_set_int(cval, kp);
    if (res == 0) {
        printk(KERN_INFO "callback triggered and the value is : %d\n", cbVal);
        return res;
    }
    return res;
}

/**
 * @brief This structure is for getting params from userspace to kernel space
 */
const struct kernel_param_ops my_param_ops = {
    .set = &notifyParam,
    .get = &param_get_int,
};

module_param_cb(cbVal, &my_param_ops, &cbVal, S_IRUGO | S_IWUSR );

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
    printk("hello kernel, inserting my_pass_arg module\n");
    int ret = register_chrdev(MAJOR(dev), "my_pass_arg", &fops);
    if (ret < 0) {
        printk(KERN_ERR "Kernel Module failed to insert...\n");
        return ret;
    }
    printk(KERN_INFO "Major = %d Minor = %d \n",(ret == 0) ? MAJOR(dev) : MAJOR(ret), (ret == 0) ? MINOR(dev) : MINOR(ret));
    printk(KERN_INFO "Passed arguments output:\nval : %d\npVal : %s\narrVal : ", val, pVal);
    for(int i=0; i<4; i++) {
        printk(KERN_INFO "%d ", arr_val[i]);
    }
    printk(KERN_INFO "\nKernel Module Inserted Successfully...\n");
    return 0;
}

/**
 * @brief This function will be invoked, when module removed from kernel module list
 */
static void moduleExit(void) {
    printk(KERN_INFO "bye bye kernel\n");
    unregister_chrdev(MAJOR(dev), "my_pass_arg");
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}

module_init(moduleInit);
module_exit(moduleExit);