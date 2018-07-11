void dump5(char *str);
int main()
{
  char s[5]={'s','a','\0','c','h'};
  char membuff[5]; 
  char strbuff[5];
  memset(membuff, 0, 5); // init both buffers to nulls
  memset(strbuff, 0, 5);
  strcpy(strbuff,s);
  memcpy(membuff,s,5);
  dump5(membuff); // show what happened
  dump5(strbuff);
  return 0;
}
void dump5(char *str)
{
  char *p = str;
int n; 
 for (n = 0; n < 5; ++n)
  {
    printf("%2.2x ", *p);
    ++p;
  }
  printf("\tnext\n");
  p = str;
  for (n = 0; n < 5; ++n)
  {
    printf("%c", *p ? *p : ' ');
    ++p;
  }
  printf("\n", str);
}
