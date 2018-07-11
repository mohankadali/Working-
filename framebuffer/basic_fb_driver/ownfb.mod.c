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
	{ 0x133cd565, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xd98dda9b, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xf5c5b05a, __VMLINUX_SYMBOL_STR(cfb_imageblit) },
	{ 0xf9313ba6, __VMLINUX_SYMBOL_STR(cfb_copyarea) },
	{ 0x3dd0eaed, __VMLINUX_SYMBOL_STR(cfb_fillrect) },
	{ 0x7406cfb8, __VMLINUX_SYMBOL_STR(pci_unregister_driver) },
	{ 0x3db45f87, __VMLINUX_SYMBOL_STR(__pci_register_driver) },
	{ 0xd0a5ea58, __VMLINUX_SYMBOL_STR(register_framebuffer) },
	{ 0x7a890c8, __VMLINUX_SYMBOL_STR(fb_alloc_cmap) },
	{ 0xc34b019c, __VMLINUX_SYMBOL_STR(framebuffer_alloc) },
	{ 0x3313c656, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x9347d1d9, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x520ec809, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x254874c3, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xf091f8d, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x1ca03155, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xdc27246b, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xb927b112, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x759d035d, __VMLINUX_SYMBOL_STR(framebuffer_release) },
	{ 0xedc03953, __VMLINUX_SYMBOL_STR(iounmap) },
	{ 0x98b71c6, __VMLINUX_SYMBOL_STR(fb_dealloc_cmap) },
	{ 0x9568d445, __VMLINUX_SYMBOL_STR(unregister_framebuffer) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("pci:v00008086d00003577sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "0FB444286AC082667958904");
