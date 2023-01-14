#include <stdio.h>

int main(){
  int n;
  int count = 0;
  scanf("%d",&n);
  if(n == 0){
	printf("0");
	return 0;
  }
  for(int i = 5 ; i <= n ; i*=5){
	for(int j = i ; j <= n; j += i){
	  ++count;
	}
  }
  printf("%d", count);
  return 0;
}
