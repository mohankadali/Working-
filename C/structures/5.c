struct exp{ 
    int a; 
    int b; 
    int c; 
}; 
int fun(struct exp *s1) 
{ 
    printf("%d",s1->a); 
    printf("%d",s1->b); 
    printf("%d",(*s1).c); 
} 
int main() 
{ 
    struct exp s1; 
    s1.a=10; 
    s1.b=20; 
    s1.c=30; 
    fun(&s1); 
}
