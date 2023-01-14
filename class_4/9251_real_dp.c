#include <stdio.h>
#include <string.h>
#define MAX 1000

int dp[MAX][MAX];

int max(int a, int b){
  return a > b ? a : b;
}

int main(){
  char s1[MAX], s2[MAX];
  int s1_len, s2_len;
  scanf("%s\n%s",s1 + 1, s2 + 1);
  s1_len = strlen(s1 + 1);
  s2_len = strlen(s2 + 1);
  for(int i = 1 ; i <= s1_len ; ++i){
	for(int j = 1 ; j <= s2_len ; ++j){
	  if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
	  else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	}
  }
  printf("%d",dp[s1_len][s2_len]);
  return 0;
}
