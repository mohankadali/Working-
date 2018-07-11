#include<linux/sched.h>
#include <linux/syscalls.h>
#include<linux/init.h>
#include<linux/kernel.h>

asmlinkage long sys_my_syscall(void){

printk("\nsuccessful\n");

return 0;
}
