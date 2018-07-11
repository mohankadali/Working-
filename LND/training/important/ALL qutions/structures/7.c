int main ( )
{
    union a
    {
        int a;
        int b;
    }a;
    a.a = 10;
    a.b = 5;
    printf ( "%d%d\n", a.a, a.b );
}
