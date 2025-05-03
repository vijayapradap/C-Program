## 🔧 **Introduction**

* **What is a Kernel Module?**
  A kernel module is code that can be loaded and unloaded into the kernel at runtime. It extends the kernel’s functionality without rebooting the system.

* **Why Use Modules?**

  * Modularity: Code can be isolated and reused.
  * Flexibility: You don’t need to rebuild the entire kernel.
  * Memory efficiency: Load only when needed.

* **Typical Use Cases:**
  Device drivers, filesystem drivers, and network protocol implementations.

## 🛠️ **Hello World**

This chapter walks through the creation, loading, and unloading of a basic kernel module.

### ✅ **Hello World Module**

* The module includes two key functions:

  * `init_module()` or `module_init()` – Called when the module is loaded.
  * `cleanup_module()` or `module_exit()` – Called when the module is removed.

* These functions must be declared using macros:

  ```c
  module_init(my_init);
  module_exit(my_exit);
  ```

* Example of simple print to kernel log:

  ```c
  printk(KERN_INFO "Hello, world\n");
  ```

### ✅ **Compiling Modules**

* Use a **Makefile** with kernel build system support:

  ```make
  obj-m += hello.o
  all:
      make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
  clean:
      make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
  ```

* Compilation creates a `.ko` file (kernel object).

### ✅ **Loading and Unloading Modules**

* Use commands:

  * `insmod hello.ko` – Load module.
  * `rmmod hello` – Remove module.
  * `dmesg` – View kernel log messages (e.g., printk output).
* Root privileges are typically required.

### ✅ **License and Author Information**

* It's important to specify metadata:

  ```c
  MODULE_LICENSE("GPL");
  MODULE_AUTHOR("Your Name");
  MODULE_DESCRIPTION("A simple Hello World module");
  ```
* **GPL license** ensures no "taint" in the kernel if you use symbols exported by the GPL-only infrastructure.

### ✅ **Using Kernel Symbols**

* Kernel modules can access functions and variables exposed by the kernel through **exported symbols**.

* You can view available symbols:

  * `cat /proc/kallsyms`
  * Or use tools like `nm` on compiled modules.

* **Exporting symbols** from your own module (for others to use):

  ```c
  EXPORT_SYMBOL(your_function);
  EXPORT_SYMBOL_GPL(only_for_gpl_users);
  ```

## 🔍 **Deeper Module Management – Key Takeaways**

1. **Lifecycle Control:** Modules can be dynamically loaded/unloaded at runtime without rebooting.
2. **Module Entry/Exit:** Always define clear `init` and `exit` functions using macros.
3. **Safe Kernel Integration:** Always use `MODULE_LICENSE` to avoid kernel taint.
4. **Symbol Visibility:** Use `EXPORT_SYMBOL[_GPL]` to allow module interdependency.
5. **Kernel Logs for Debugging:** `printk` is the main way to log module behavior; check with `dmesg`.

## ⚙️ **Practical Module Management Tools**

### 📁 `/proc/modules`

* Displays loaded modules.
* Output includes:

  * Name
  * Size
  * Usage count
  * Dependencies
* Equivalent to `lsmod`.

### 🧩 `/etc/modprobe.conf` and `/etc/modprobe.d/`

* Configuration files for **modprobe** tool.
* Used to:

  * Set module options.
  * Define aliases.
  * Blacklist specific modules.
  * Auto-load dependent modules.

**Example:**

```conf
options mydriver debug=1
alias netcard e1000
blacklist nouveau
```

### 🔄 `depmod -a`

* Scans modules and builds:

  * `modules.dep` – lists dependencies.
  * `modules.alias` – alias mappings.
* Required when:

  * Adding new modules to `/lib/modules/$(uname -r)/`.
  * Using `modprobe` to auto-load modules with dependencies.

**Usage:**

```bash
sudo depmod -a
```

### 🧠 Difference Between `insmod` and `modprobe`

| Command    | Behavior                                                |
| ---------- | ------------------------------------------------------- |
| `insmod`   | Loads a module directly (no dependencies)               |
| `modprobe` | Loads a module **with dependencies**, uses config files |
| `depmod`   | Prepares module dependency info for `modprobe`          |

## ✅ Quick Recap: Must-Know Points

| Topic                      | Summary                                        |
| -------------------------- | ---------------------------------------------- |
| `init/exit`                | Entry and exit points of a module              |
| `printk()`                 | Kernel log printing                            |
| `insmod/rmmod`             | Manual module load/unload                      |
| `lsmod` or `/proc/modules` | View currently loaded modules                  |
| `MODULE_LICENSE`           | Avoids kernel taint for open-source compliance |
| `EXPORT_SYMBOL[_GPL]`      | Make functions/vars usable by other modules    |
| `modprobe.conf`            | Customize module behavior                      |
| `depmod`                   | Builds dependency map for module auto-loading  |

