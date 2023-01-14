#include <bits/stdc++.h>
#define N_MAX 1001

using namespace std;

int N;

int Values[N_MAX][3];

int DP[N_MAX][3];

int main(){
  int cur_value;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < 3 ; ++j){
	  cin >> Values[i][j];
	}
  }
  int ans = (int)1e9;
  for(int c = 0 ; c < 3; ++c){
	for(int i = 0 ; i < 3; ++i)
	  DP[0][i] = i != c ? (int)1e9 : Values[0][i];
	for(int i = 1 ;i < N ; ++i){
	  for(int j = 0 ; j <3 ; ++j){
		DP[i][j] = min(DP[i-1][(j+1)%3], DP[i-1][(j+2)%3]) + Values[i][j];
	  }
	}
	for(int i = 0 ; i < 3; ++i){
	  if(i == c) continue;
	  ans = min(ans, DP[N-1][i]);
	}
  }
  cout << ans;
  return 0;
}
