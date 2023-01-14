#include <stdio.h>
int main(){
  int num_a,num_b;
  scanf("%d %d",&num_a, &num_b);
  printf("%s", num_a == num_b ? "==" : num_a > num_b ? ">" : "<");
  return 0 ;
}

