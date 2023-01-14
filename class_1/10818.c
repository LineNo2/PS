#include <stdio.h>
int main() {
  int num_of_numbers;
  int temp_num;
  int max_num=-987654321, min_num=987654321;
  scanf("%d",&num_of_numbers);
  for(int i = 0 ;i<num_of_numbers ; i++){
	scanf("%d", &temp_num);
	if(min_num > temp_num)
	  min_num = temp_num;
	if(max_num < temp_num)
	  max_num = temp_num;
  }
  printf("%d %d",min_num, max_num);
  return 0;
}

