#include <bits/stdc++.h>
#define MAX_N 2001
#define endl '\n'

using namespace std;

int N, M;
int Nums[MAX_N];
bool DP[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  int right, left;
  cin >> N;
  for(int i = 1; i <= N ; ++i){
	DP[i][i] = true;
	cin >> Nums[i];
	if(i > 1 && Nums[i] == Nums[i-1])
		DP[i-1][i] = true;
	
	}
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1; j <= N ; ++j){
			left = j;
			right = i + j;
			if(left < 1 || right > N) continue;
			if(Nums[left] != Nums[right]) continue;
			if(!DP[left+1][right-1]) continue;
			DP[left][right] = true;
		}
	}
  cin >> M;
  for(int i = 0 ; i < M ; ++i){
	cin >> left >> right;
	cout << DP[left][right] << endl;
  }
  return 0;
}
