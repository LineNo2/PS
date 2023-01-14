#include <stdio.h>
int main(){
  int num_cases;
  int temp_1, temp_2;
  scanf("%d",&num_cases);
  for(int i = 0 ; i <num_cases; i++){
	scanf("%d %d", &temp_1, &temp_2);
	printf("%d\n",temp_1+temp_2);
  }
  return 0;
}

