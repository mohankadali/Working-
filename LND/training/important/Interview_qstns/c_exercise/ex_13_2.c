#include <stdio.h>
struct st{
	int i:8;
	int j:6;
	char ch;
};

int main()
{
	struct st ps = {1,2,3};

	printf("%p  %p\n", &ps.i, &ps.j);
}
