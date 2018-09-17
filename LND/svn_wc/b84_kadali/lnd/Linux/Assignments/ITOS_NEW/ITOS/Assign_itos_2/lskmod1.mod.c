#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x5634976f, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x13308de9, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x5904bf3a, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xc72f42af, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xc32ced21, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xaab7996e, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x3a7af677, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0xd537fc46, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x2885abfc, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xc7fe5f1d, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "83022CBC9FB37A54CCD2AE1");
