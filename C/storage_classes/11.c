char *fun()
{
        static char arr[1024];
        return arr;
}

int main()
{
        char *str = "global edge";
        strcpy(fun(), str);
        str = fun();
        strcpy(str, "global edge");
        printf("%s", fun());
        return 0;
}
