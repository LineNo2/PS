#include <bits/stdc++.h>
#define N_MAX 1000001
using namespace std;

int N;
int Arr[N_MAX];
int DP[N_MAX];

int DP_Arr[N_MAX];
vector<pair<int,int>> DP_Nums[N_MAX];//first -> num ,second -> idx

int Trace[N_MAX];

void DFS(int cur, int former_idx){
  if(cur == 0) return;
  for(int i = DP_Nums[cur].size() - 1 ; i >= 0  ;--i){
    if(former_idx < DP_Nums[cur][i].second) continue;
    DFS(cur-1, DP_Nums[cur][i].second );
    cout << DP_Nums[cur][i].first <<" ";
    return;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int p;
  int ans = 1;
  cin >> N;
  cin >> Arr[0];
  DP[0] = 1;
  DP_Nums[1].push_back(make_pair(Arr[0],0));
  DP_Arr[1] = Arr[0];
  for(int i = 1 ; i < N ; ++i){
	cin >> Arr[i];
	p = lower_bound(DP_Arr + 1, DP_Arr + ans + 1, Arr[i]) - DP_Arr;
  if(p == ans + 1) ++ans;
	DP[i] = p;
	DP_Arr[p] = Arr[i];
  DP_Nums[p].push_back(make_pair(Arr[i],i));
  }
  cout << ans << endl;
  DFS(ans, DP_Nums[ans][DP_Nums[ans].size() - 1].second);
  return 0;
}

