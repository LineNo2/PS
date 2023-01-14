#include <stdio.h>
int main(){
  int num_hr, num_min;
  scanf("%d %d",&num_hr, &num_min);
  printf("%d %d",num_min >= 45 ? num_hr : num_hr == 0 ? 23 : num_hr - 1, num_min >= 45 ? num_min - 45 : 15 + num_min);
  return 0;
}
