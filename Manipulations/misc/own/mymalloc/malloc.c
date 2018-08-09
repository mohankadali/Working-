#include<stdio.h>
#include<stddef.h>
char memory[20000]={};
struct block{
        size_t size;
        struct block *next;
};
struct block *freelist=(void*)memory;
void *mymalloc(size_t bytes)
{
        struct block *curr,*prev;
        void *result;
        if(!(freelist->size))
        {
                freelist->size=20000-sizeof(struct block);
                freelist->next=NULL;

                printf("Memory initialized\n");
        }
        curr=freelist;
        while( ((curr->size)<bytes) || ((curr->next)!=NULL) )
        {
                printf("bytes:%d\n",bytes);
                printf("curr->size:%d\n",curr->size);
                prev=curr;
                curr=curr->next;
                printf("One block checked\n");
        }
        return result=(void*)(++curr);        
}
int main()
{
        int *r=(int)mymalloc(1000*sizeof(int));
        //int *r = malloc(10);  
        r[1] = 100;
        printf("%d\n",r[1]);        
        int *p=(int)mymalloc(20000);
        p[1] = 10;
        printf("%d\n",p[1]);        
        printf("Allocation and deallocation is done successfully!\n");
        return 0;
}
