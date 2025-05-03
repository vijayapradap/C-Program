## 📄 Overview of `pass_arg.c`

This kernel module illustrates:

* **Defining module parameters** using macros like `module_param` and `module_param_array`.
* **Initializing** and **cleaning up** the module with `init_module` and `cleanup_module` functions.
* **Logging** parameter values using `printk`.

---

## 🧩 Step-by-Step Breakdown

### 1. **Including Necessary Headers**

```c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
```

* `linux/init.h`: Contains macros for module initialization and cleanup.
* `linux/module.h`: Essential for all kernel modules; includes module-related macros and functions.
* `linux/kernel.h`: Provides kernel-level functions like `printk`.

### 2. **Defining Module Parameters**

```c
static char *myname = "default";
static int myint = 0;
static int myarray[5] = {0, 1, 2, 3, 4};
static int arr_argc = 0;
```

* `myname`: A string parameter with a default value "default".
* `myint`: An integer parameter initialized to 0.
* `myarray`: An integer array with default values.
* `arr_argc`: Tracks the number of elements initialized in `myarray`.

### 3. **Registering Module Parameters**

```c
module_param(myint, int, 0);
MODULE_PARM_DESC(myint, "An integer");

module_param(myname, charp, 0000);
MODULE_PARM_DESC(myname, "A character string");

module_param_array(myarray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myarray, "An array of integers");
```

* `module_param`: Registers a single parameter.

  * Syntax: `module_param(name, type, permissions)`

    * `name`: Variable name.
    * `type`: Data type (`int`, `charp`, etc.).
    * `permissions`: File permissions for `/sys/module/<module_name>/parameters/<param_name>`.
* `module_param_array`: Registers an array parameter.

  * Syntax: `module_param_array(name, type, num, permissions)`

    * `num`: Pointer to an integer that stores the number of elements initialized.
* `MODULE_PARM_DESC`: Provides a description for each parameter, useful for documentation and tools like `modinfo`.

### 4. **Module Initialization Function**

```c
static int __init pass_arg_init(void)
{
    int i;
    printk(KERN_INFO "Module initialized with name: %s\n", myname);
    printk(KERN_INFO "Integer value: %d\n", myint);
    for (i = 0; i < (sizeof myarray / sizeof myarray[0]); i++)
        printk(KERN_INFO "myarray[%d] = %d\n", i, myarray[i]);
    printk(KERN_INFO "Number of elements initialized: %d\n", arr_argc);
    return 0;
}
```

* `__init`: Macro indicating that the function is used only during initialization.
* `printk`: Kernel-space equivalent of `printf`; logs messages to the kernel log buffer.
* The function logs the values of the parameters upon module insertion.

### 5. **Module Cleanup Function**

```c
static void __exit pass_arg_exit(void)
{
    printk(KERN_INFO "Module exiting.\n");
}
```

* `__exit`: Macro indicating that the function is used only during module removal.
* Logs a message when the module is removed.

### 6. **Specifying Initialization and Cleanup Functions**

```c
module_init(pass_arg_init);
module_exit(pass_arg_exit);
```

* `module_init`: Specifies the function to be called at module insertion.
* `module_exit`: Specifies the function to be called at module removal.

### 7. **Module Metadata**

```c
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple module demonstrating parameter passing.");
```

* `MODULE_LICENSE`: Specifies the license; "GPL" allows the module to access all kernel symbols.
* `MODULE_AUTHOR`: Credits the module's author.
* `MODULE_DESCRIPTION`: Provides a brief description of the module.

---

## 🛠️ Building and Using the Module

### 1. **Compiling the Module**

Create a `Makefile`:

```make
obj-m += pass_arg.o

all:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

* `obj-m`: Lists the object files to be built as loadable kernel modules.
* `make -C`: Invokes the kernel build system.

Compile with:

```bash
make
```

### 2. **Inserting the Module with Parameters**

```bash
sudo insmod pass_arg.ko myint=42 myname="KernelModule" myarray=10,20,30
```

* `insmod`: Inserts the module into the kernel.
* Parameters are passed directly in the command.

### 3. **Viewing Kernel Logs**

```bash
dmesg | tail
```

* `dmesg`: Displays kernel log messages.
* `tail`: Shows the most recent entries, including those from `printk`.

### 4. **Removing the Module**

```bash
sudo rmmod pass_arg
```

* `rmmod`: Removes the module from the kernel.

---

## 📁 Inspecting Module Parameters via Sysfs

After inserting the module, parameters can be viewed and modified (if permissions allow) via the sysfs interface:

```bash
cat /sys/module/pass_arg/parameters/myint
cat /sys/module/pass_arg/parameters/myname
cat /sys/module/pass_arg/parameters/myarray
```

* These files reflect the current values of the module parameters.

---

## 🧠 Summary

* **Purpose**: Demonstrates how to pass parameters to a kernel module at load time.
* **Key Concepts**:

  * Using `module_param` and `module_param_array` to define parameters.
  * Accessing and logging parameter values in the initialization function.
  * Cleaning up with a designated exit function.
* **Practical Use**: Allows for dynamic configuration of modules without altering source code, enhancing flexibility and reusability.

---
