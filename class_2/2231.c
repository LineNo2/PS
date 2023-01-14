#include <stdio.h>
int return_digits_sum(int n_){
  if(n_/10 == 0) return n_%10;
  return return_digits_sum(n_/10) + n_%10;
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; ++i)
	if( n == return_digits_sum(i) + i ){
	  printf("%d",i);
	  return 0;
	}
  printf("0");
  return 0;
}


