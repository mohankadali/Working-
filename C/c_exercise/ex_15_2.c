#include <stdio.h>
struct st{
	char reason;
	enum {
		SCAN,
		AUTH,
		ASSOC,
		CONNECT = 767,
		RUN,
	} state:8;
};

int main() {
	struct st p = { 0, RUN};
	printf("%d\n", p.state);
}
