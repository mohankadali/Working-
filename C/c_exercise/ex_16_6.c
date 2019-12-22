int fun1(){
printf("fun1");
return 0;
}
int fun2(){
printf("fun2");
return 0;
}
int fun3(){
printf("fun3");
return 0;
}


int main() {
printf("%d", fun1() + fun2() * fun3());
}
