#include <bits/stdc++.h>

using namespace std;

vector<int> leftarr;
vector<int> rightarr;

int N, S;

int nums[41];
int bit[41];

int leftarr_find(int key){
  return upper_bound(leftarr.begin(), leftarr.end(), key) - lower_bound(leftarr.begin(), leftarr.end(), key);
}

void push_arr(int st, int ed, bool flag){
  int result = 0;
  for(int i = st; i <= ed ; ++i)
	result += bit[i] * nums[i];
  if(flag)
	rightarr.push_back(result);
  else
	leftarr.push_back(result);
}

void dfs(int idx, int st, int ed, bool flag){
  if(idx > ed) { push_arr(st, ed, flag); return; }
  for(int i = 0 ; i < 2 ; ++i){
	bit[idx] = i;
	dfs(idx + 1, st, ed, flag);
  }
}

int main(){
  long long ans = 0;
  cin >> N >> S;
  for(int i = 1 ; i <=N ; ++i)
	cin >> nums[i];
  dfs(1,1,N/2,true);
  dfs(N/2 + 1,N/2 + 1, N, false);
  sort(leftarr.begin(), leftarr.end());
  for(int i = 0 ; i < rightarr.size() ; ++i){
	ans += leftarr_find(S - rightarr[i]);
  }
  if(S == 0){
	cout << ans - 1;
	return 0;
  }
  cout << ans;
  return 0;
}

