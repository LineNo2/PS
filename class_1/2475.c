#include <stdio.h>

int sqaure(int number){
  return number*number;
}
int main(){
  int total_sqaure_sum = 0;
  int temp;
  for(int i = 0 ; i < 5; i++){
	scanf("%d", &temp);
	total_sqaure_sum += sqaure(temp);
  }
  printf("%d", total_sqaure_sum%10);
  return 0;
}
