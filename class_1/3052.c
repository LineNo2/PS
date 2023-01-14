#include <stdio.h>
int main(){
  int temp_num;
  int exist_arr[42]={0,}, total_exist=0;;
  for(int i = 0 ; i< 10 ; ++i){
	scanf("%d",&temp_num);
	exist_arr[temp_num%42] = 1;
  }
  for(int i = 0 ; i < 42; i++){
	total_exist += exist_arr[i];
  }
  printf("%d",total_exist);
  return 0;
}

