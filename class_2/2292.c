#include <stdio.h>
int main(){
  int n;
  scanf("%d",&n);
  n -= 1;
  for(int i = 0 ;;++i){
	n -= i*6;
	if( n <= 0 ){
	  printf("%d",i + 1);
	  return 0;
	}
  }
  return 0;
}


