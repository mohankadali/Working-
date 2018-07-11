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
	{ 0x195c2787, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xcddef5d9, __VMLINUX_SYMBOL_STR(spi_bus_type) },
	{ 0x6bc3fbc0, __VMLINUX_SYMBOL_STR(__unregister_chrdev) },
	{ 0xda557946, __VMLINUX_SYMBOL_STR(driver_unregister) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x396a0e1f, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xd5f508b9, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xb8f26d5b, __VMLINUX_SYMBOL_STR(driver_register) },
	{ 0x1bdf2d9a, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x733bbb51, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0xbaaf0a39, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x6362158b, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xd3ceec67, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x62b3fa97, __VMLINUX_SYMBOL_STR(put_device) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "0DAA7E9AD80178C666F3633");
