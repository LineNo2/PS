#include <stdio.h>
int main(){
  int n;
  int temp;
  int count = 0;
  int int_arr[1010] = {0,};
  scanf("%d",&n);
  for(int i = 2 ; i <= 1000 ; ++i){
	  if(int_arr[i]) continue;
	  int_arr[i] = 2;
	  for(int j = 2 ; j*i <= 1000 ; ++j){
	    int_arr[j*i] = 1;
	  }
  }
  for(int i = 0; i < n ; ++i){
    scanf("%d",&temp);
	  if(int_arr[temp] == 2){
      int_arr[temp] = -1;
	    ++count;
    }
  }
  printf("%d",count);
  return 0;
}
	
	
