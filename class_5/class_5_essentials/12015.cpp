#include <bits/stdc++.h>
#define N_MAX 1000001
using namespace std;

int N;
int Arr[N_MAX];
int DP[N_MAX];

int DP_Arr[N_MAX];

int Trace[N_MAX];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int p;
  int ans = 1;
  cin >> N;
  cin >> Arr[0];
  DP[0] = 1;
  DP_Arr[1] = Arr[0];
  for(int i = 1 ; i < N ; ++i){
	cin >> Arr[i];
	p = lower_bound(DP_Arr + 1, DP_Arr + ans + 1, Arr[i]) - DP_Arr;
  if(p == ans + 1) ++ans;
	DP[i] = p;
	DP_Arr[p] = Arr[i];
  }
  cout << ans << endl;
  for(int i = 1 ; i <= ans; ++i)
  cout << DP_Arr[i] <<" ";
  return 0;
}


