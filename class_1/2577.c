#include <stdio.h>
#include <string.h>
int main() {
  int num_a, num_b, num_c;
  int rate_arr[10]={0,};
  char result_char[10];
  scanf("%d %d %d",&num_a, &num_b, &num_c);
  sprintf(result_char,"%d",num_a*num_b*num_c);
  for(int i = 0 ;i<strlen(result_char);++i){
	++rate_arr[result_char[i]-48];
  }
  for(int i = 0 ; i<10 ; i++){
	printf("%d\n",rate_arr[i]);
  }
  return 0;
}
  
