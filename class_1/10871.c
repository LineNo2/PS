#include <stdio.h>
int main() {
  int total_nums, num_x;
  int temp;
  scanf("%d %d", &total_nums, &num_x);
  for(int i = 0 ; i<total_nums ; i++){
	scanf("%d",&temp);
	if(num_x > temp)
	  printf("%d ",temp);
  }
  return 0;
}
