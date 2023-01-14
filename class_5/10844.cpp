#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

int N;

int DP[10][101];

int main(){
  cin >> N;
  for(int i = 1 ; i< 10 ; ++i)
	DP[i][0] = 1;
  for(int i = 1 ; i < N ; ++i){
	for(int j = 0 ; j < 10 ; ++j){
	  if( j != 0 ) DP[j][i] = (DP[j][i] + DP[j-1][i-1]) % MOD;
	  if( j != 9 ) DP[j][i] = (DP[j][i] + DP[j+1][i-1]) % MOD;
	}
  }
  long long ans = 0;
  for(int i = 0 ; i < 10 ; ++i){
	ans = (ans + DP[i][N-1]) % MOD;
  }
  cout << ans;
  return 0;
}
