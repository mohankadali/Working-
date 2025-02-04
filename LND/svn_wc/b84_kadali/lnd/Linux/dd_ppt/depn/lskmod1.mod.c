#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xcb6bf7a7, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xa2b6fdcb, __VMLINUX_SYMBOL_STR(myRelease) },
	{ 0xeeb95ef1, __VMLINUX_SYMBOL_STR(myOpen) },
	{ 0x48077bdf, __VMLINUX_SYMBOL_STR(myioctl) },
	{ 0x69d178ca, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x43d607dc, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xc38529c9, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x52adb358, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x2484fd5c, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x6a95178d, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x377c4fd3, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x46e51e50, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x603c239a, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=lskreal,lskopen,lskmod";


MODULE_INFO(srcversion, "0FD0AE11AEE911208943A7F");
