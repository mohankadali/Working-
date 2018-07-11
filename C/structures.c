#include<stdio.h>

union telephone
{
  char name[3];
  int number;
};

int main()
{
  union telephone index = {
    .name = "Aoe",
    .number = 12345,
  };
  printf("Name: %s\n", index.name);
  printf("Telephone number: %d\n", index.number);

  return 0;
}
