#include <bits/stdc++.h>
#define N_MAX 100001

using namespace std;

int N, K;

int Arr[N_MAX];
int Sum[N_MAX];

int circle_partial_sum(int st, int ed){
  if( ed < N ) return Sum[ed-1] - Sum[st-1];
  return Sum[N-1] - Sum[st-1] + Sum[ed-N-1];
}

int main(){
  cin >> N >> K;
  cin >> Arr[0];
  Sum[0] = Arr[0];
  for(int i = 1 ; i < N ; ++i){
	cin >> Arr[i];
	Sum[i] = Sum[i-1] + Arr[i];
  }
  int ans = 0;
  for(int i = 0 ; i < N ; ++i){
	ans = max(circle_partial_sum(i, i + K), ans);
  }
  cout << ans;
  return 0;
}
