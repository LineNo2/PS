#include <stdio.h>
int main() { 
  int digits;
  int result_of_sum = 0;
  char temp_num;
  scanf("%d\n",&digits);
  for(int i = 0 ; temp_num = getchar(), temp_num != '\n' ; i++)
	result_of_sum += temp_num - 48;
  printf("%d",result_of_sum);
  return 0;
}

