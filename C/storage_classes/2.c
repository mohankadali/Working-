 int main()
{
        static int i=5;
        if (--i){
                printf("%d ",i);
                main();
        }
}
