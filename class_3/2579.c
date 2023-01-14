#include <stdio.h>
int max(int a, int b){
  if(a > b) return a;
  return b;
}
int main(){
  int n;
  int val[310];
  int d[310] = {0,}, is_three[310] = {0,};
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; ++i)
	scanf("%d", &val[i]);
  d[0] = 0;
  d[1] = val[1];
  d[2] = val[1] + val[2];
  for(int i = 3 ; i <= n ; ++i){
	d[i] = max(val[i-1] + d[i-3] + val[i], d[i-2] + val[i]);
  }
  printf("%d",d[n]);
 return 0;
}

  
