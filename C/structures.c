#include<stdio.h>

union telephone
{
  char name[3];
  int number;
};

int main()
{
  union telephone index = {
    .number = 12345,
    .name = "Aoe"
  };
  printf("Name: %s\n", index.name);
  printf("Telephone number: %d\n", index.number);

  return 0;
}
