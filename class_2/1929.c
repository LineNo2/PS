#include <stdio.h>
int main(){
  int st, end;
  int int_arr[1000010] = {0,};
  scanf("%d %d",&st, &end);
  for(int i = 2 ; i <= end ; ++i){
	if(int_arr[i]) continue;
	int_arr[i] = 2;
	for(int j = 2 ; j*i <= end ; j++){
	  int_arr[j*i] = 1;
	}
  }
  for(int i = st; i <= end ; ++i){
	if(int_arr[i] == 2)
	  printf("%d\n", i);
  }
  return 0;
}
	
	
