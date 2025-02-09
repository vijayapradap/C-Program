#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vijayapradap M <vijaypradam@gmail.com>");
MODULE_DESCRIPTION("A simple hello kernel program");

static int moduleInit(void) {
    printk("hello kernel\n");
    return 0;
}

static void moduleExit(void) {
    printk("bye bye kernel\n");
}

module_init(moduleInit);
module_exit(moduleExit);