#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x2a3af2b6, "module_layout" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x50561faf, "kmalloc_caches" },
	{ 0x1fdc7df2, "_mcount" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0x5fe075b6, "__register_chrdev" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x999e8297, "vfree" },
	{ 0xd697e69a, "trace_hardirqs_on" },
	{ 0x63bfcea1, "kthread_create_on_node" },
	{ 0xb3a56b49, "kthread_bind" },
	{ 0xdcb764ad, "memset" },
	{ 0xc5850110, "printk" },
	{ 0x5201db0a, "kthread_stop" },
	{ 0x6b4b2933, "__ioremap" },
	{ 0xef8c648b, "module_put" },
	{ 0xdaca81bf, "cpu_hwcaps" },
	{ 0xf3ecac14, "cpu_hwcap_keys" },
	{ 0x5a62395b, "wake_up_process" },
	{ 0x9929e184, "kmem_cache_alloc_trace" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x37a0cba, "kfree" },
	{ 0xedc03953, "iounmap" },
	{ 0xec3d2e1b, "trace_hardirqs_off" },
	{ 0xc326fb12, "param_ops_ulong" },
	{ 0xb2ead97c, "kimage_vaddr" },
	{ 0x14b89635, "arm64_const_caps_ready" },
	{ 0x6228c21f, "smp_call_function_single" },
	{ 0x2275496a, "try_module_get" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "99BF37D035F231626ACE925");
