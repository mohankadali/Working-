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
	{ 0xeeb4c866, __VMLINUX_SYMBOL_STR(param_ops_short) },
	{ 0x90d51b20, __VMLINUX_SYMBOL_STR(param_ops_long) },
	{ 0x69d178ca, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xbe575e4, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x14220b9b, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "FA97AB60B62D730DB2FE217");
