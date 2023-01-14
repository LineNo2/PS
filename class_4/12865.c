#include <stdio.h>

typedef struct Thing{
  int weight;
  int value;
}Thing;

int max(int a, int b){
  return a > b ? a : b;
}

int n, k;
int dp[100][100001];
Thing things[100];

int main() {
  scanf("%d %d",&n, &k);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d %d",&things[i].weight, &things[i].value);
  }
  for(int i = 0 ; i <= k ; ++i){
	if(i < things[0].weight) dp[0][i] = 0;
	else dp[0][i] = things[0].value;
  }
  for(int i = 1 ; i < n ; ++i){
	for(int j = 0 ; j <= k ; ++j){
	  if(j < things[i].weight) dp[i][j] = dp[i-1][j];
	  else dp[i][j] = max(dp[i-1][j], dp[i-1][j - things[i].weight] + things[i].value);
	}
  }
  printf("%d",dp[n-1][k]);
  return 0;
}
  
