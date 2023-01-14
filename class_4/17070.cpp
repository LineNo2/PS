#include <iostream>
#include <algorithm>
#define N_MAX 16

using namespace std;

int N;

int map[N_MAX][N_MAX];
int dp[3][N_MAX][N_MAX];

int main(){
  cin >> N;
  for(int i = 0 ; i < N ;++i) 
	for(int j = 0 ; j < N ;++j) 
	  cin >> map[i][j];
  dp[0][0][1] = 1;
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j< N; ++j){
	  if(map[i][j]) continue;
	  if( j > 0 && map[i][j-1] == 0){
		dp[0][i][j] += dp[0][i][j-1];
		dp[0][i][j] += dp[2][i][j-1];
	  }
	  if( i > 0 && map[i-1][j] == 0){
		dp[1][i][j] += dp[1][i-1][j];
		dp[1][i][j] += dp[2][i-1][j];
	  }
    if(map[i][j]) continue;
	  if( i > 0 && j > 0 && map[i][j-1] == 0 && map[i-1][j] == 0){
		dp[2][i][j] += dp[2][i-1][j-1];
		dp[2][i][j] += dp[1][i-1][j-1];
		dp[2][i][j] += dp[0][i-1][j-1];
	  }
	}
  }
  cout << dp[0][N-1][N-1] + dp[1][N-1][N-1] + dp[2][N-1][N-1];
  return 0;
}
  
