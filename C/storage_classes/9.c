int main()
{
        extern int i;
        printf("%d ", i);
        {
                int i = 10;
                printf("%d ", i);
        } 
}
i = 909;


