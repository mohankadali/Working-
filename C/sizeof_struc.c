struct st {
  int a;
  int b;
  int c;
}*p;

int main()
{
printf("%d\n",sizeof(p));
printf("%d\n",sizeof(*p));
}

