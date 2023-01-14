#include <stdio.h>
int main(){
  int n;
  int d[1001];
  d[1] = 1;
  d[2] = 3;
  for(int i = 3 ;  i <= 1000; ++i){
	d[i] = (2*d[i-2] + d[i-1])%10007;
  }
  scanf("%d",&n);
  printf("%d",d[n]);
  return 0;
}

