struct st{
char reason;
enum {
SCAN,
AUTH,
ASSOC,
CONNECT,
RUN,
} state:8;
};

int main() {
struct st p;;
printf("%d\n", sizeof(p));
} 
