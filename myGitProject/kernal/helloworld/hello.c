#include <linux/module.h>
#include <linux/init.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vijayapradap Murugavel");
MODULE_DESCRIPTION("Hello world my first program over Kernal");

/**
 * @brief This function will be invoked whenever this module loaded in kernel
 */
static int __init my_init(void) {
	printk("hello vijay!\n");
	return 0;
}

/**
 * #brief This function will be invoked whenever this module removed from Kernal
 */
static void __exit my_exit(void) {
	printk("Good bye! Vijay!\n");
}

module_init(my_init);
module_exit(my_exit);
