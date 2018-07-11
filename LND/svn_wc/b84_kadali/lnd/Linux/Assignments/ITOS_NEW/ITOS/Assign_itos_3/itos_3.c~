#include <stdio.h>
struct link {
        struct link *next;
        struct link *prev;
};
struct task {
        long state;
        int pid;
        int flags;
        int prio;
        unsigned char fpu_counter;
        struct link tasks;
        char rcu_read;
        int tgid;
        char comm[16];
        unsigned int rt_prio;
};

#define getadd(type, ptr1, nextaddr) \
        ptr1 = (char*)(nextaddr) - ((unsigned int)&(((type *)0)->tasks.next))

int main(void)
{

struct task t;
t.state = 10;
struct task *ptr = NULL;
getadd(struct task, ptr, &(t.tasks.next));
printf("%p\n",ptr);
printf("%ld",ptr->state);
return 0;
}
