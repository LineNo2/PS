#include <stdio.h>
int main(){
  int a,b;
  a = 0;
  b = 1;
  printf("%d %d %d %d", a^b, ~a^b, ~a, ~b);
  return 0;
}
