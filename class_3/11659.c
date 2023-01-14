#include <stdio.h>
int main(){
  int n, m;
  int sum[100001] = {0,};
  int temp;
  int temp2;
  scanf("%d %d",&n, &m);
  scanf("%d",&temp);
  sum[1] = temp;
  for(int i = 2 ; i <= n ;++i){
	scanf("%d",&temp);
	sum[i] = sum[i-1] + temp;
  }
  for(int i = 0 ; i < m; ++i){
	scanf("%d %d",&temp, &temp2);
	printf("%d\n",sum[temp2] - sum[temp - 1]);
  }
  return 0;
}

