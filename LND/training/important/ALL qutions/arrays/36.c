int main()
{
        int a[] = {1,2};
        int *p = malloc(sizeof(int));
        p[1] = 3;
        p = a;
        a = p;
                
}
