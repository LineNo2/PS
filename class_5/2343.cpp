#include <bits/stdc++.h>
#define N_MAX 100001

using namespace std;

int DP[5][5][N_MAX];

int min_(int a,int b){
  if(a == 0) return b;
  return a > b ? b : a;
}

int get_moving_cost(int st, int ed){
  if(st == 0) return 2;
  if(abs(ed-st) == 2) return 4;
  if(st == ed) return 1;
  return 3;
}

int main(){
  int cur, cnt = 0;
  cin >> cur;
  if(cur == 0) {
	cout << 0;
	return 0;
  }
  DP[cur][0][0] = 2;
  DP[0][cur][0] = 2;
  while(1){
	cin >> cur;
	if(cur == 0) break;
	for(int i = 0 ; i<= 4; ++i){
	  for(int j = 0 ; j <= 4 ; ++j){
		if(DP[i][j][cnt] != 0){
		  DP[i][cur][cnt+1] = min_(DP[i][cur][cnt+1], DP[i][j][cnt] + get_moving_cost(j, cur));
		  DP[cur][j][cnt+1] = min_(DP[cur][j][cnt+1], DP[i][j][cnt] + get_moving_cost(i, cur));
		}
	  }
	}
	++cnt;
  }
  int ans = 987654321;
  for(int i = 0 ; i <= 4; ++i){
	for(int j = 0 ; j <= 4;++j){
	  ans = min_(DP[i][j][cnt], ans);
	}
  }
  cout << ans;
  return 0;
}

