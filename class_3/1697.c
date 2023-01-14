#include <stdio.h>
#include <string.h>

int return_min(int a, int b){
  if( a > b) return b;
  return a;
}

int main(){
  int n, k;
  int pos_val[100010];
  scanf("%d %d",&n, &k);
  for(int i = 0 ; i < 100010; ++i)
	pos_val[i] = 987654321;
  for(int  i = 0 ; i <= n ; ++i){
	pos_val[i] = n - i;
  }
  for(int i = n + 1 ; i <= 100000 ; ++i){
	if( i % 2 == 0 ){
	  pos_val[i] = return_min( pos_val[i/2], return_min( pos_val[i-1] , pos_val[i+1])) + 1;
	}
	else
	  pos_val[i] = return_min( return_min( pos_val[i/2], pos_val[(i+1)/2] ) + 1 , return_min( pos_val[i-1] , pos_val[i+1])) + 1;
  }
  printf("%d",pos_val[k]);
  return 0;
}

