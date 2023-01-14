#include <stdio.h>
int main() { 
  int key_num;
  scanf("%d",&key_num);
  printf("%d", key_num%4 == 0 ? key_num % 100 == 0 ? key_num % 400 == 0 ? 1 : 0  : 1 : 0 );
  return 0;
}
