#include<stdio.h>
void visit();
int main(){
  int i=0;
  {                    //Opening inner block
   // static int a=5;  //locally declaration
    int a=5;  //locally declaration
XYZ:            //Label of goto statement
    printf("%d  ",a);
    a++;
    i++;
  }                     //closing inner block.   
  visit();
  /* printf("%d",a); Variable a is not visible here but
     it is alive. */
  if(i<5)
    goto XYZ;
  return 0;
}
void visit(){

}
