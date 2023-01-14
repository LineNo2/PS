#include <stdio.h>
#define MAX 1000

int max(int a, int b){
  return a > b ? a : b;
}

int main(){
  int dp[MAX];
  int arr[MAX];
  int n;
  int ans = 0;
  int temp = 0;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
    scanf("%d", &arr[i]);
	temp = 0;
	for(int j = 0 ; j < i ; ++j){
	  if(arr[i] > arr[j])
		temp = max(temp,dp[j]);
	}
	dp[i] = temp + 1;
	ans = max(dp[i], ans);
  }
  printf("%d",ans);
  return 0;
}
