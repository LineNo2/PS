#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

int N;

int DP[10][101][1 << 10];

int main(){
  cin >> N;
  for(int i = 1 ; i< 10 ; ++i)
	DP[i][0][1<<i] = 1;
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < 10 ; ++j){
		for(int bit = 0 ; bit < (1 << 10) ; ++bit){
		if(!DP[j][i][bit]) continue;		
		int next_bit;
	  if( j != 0 ) {
			next_bit = bit | (1 << (j-1));
			DP[j-1][i+1][next_bit] = (DP[j-1][i+1][next_bit] + DP[j][i][bit]) % MOD;
		}
	  if( j != 9 ) {
			next_bit = bit | (1 << (j+1));
			DP[j+1][i+1][next_bit] = (DP[j+1][i+1][next_bit] + DP[j][i][bit]) % MOD;
		}
	}
  }
	}
  long long ans = 0;
  for(int i = 0 ; i < 10 ; ++i){
	ans = (ans + DP[i][N-1][(1<<10)-1]) % MOD;
  }
  cout << ans;
  return 0;
}
