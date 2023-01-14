#include <bits/stdc++.h>
#define N_MAX 1000001

using namespace std;

int N;
int Arr[N_MAX];

int main(){
  int ans = 0;
  int left_right_min;
  cin >> N >> Arr[0];
  if(N == 1) {cout << Arr[0]; return 0;} 
  cin >> Arr[1];
  if(N == 2) {
    cout << max(Arr[0],Arr[1]);
    return 0;
  }
  ans = max(Arr[0], Arr[1]);
  for(int i = 1; i < N-1 ; ++i){
	cin >> Arr[i+1];
	left_right_min = min(Arr[i-1], Arr[i+1]);
	ans = max(Arr[i] + left_right_min, ans);
  ans = max(Arr[i+1],ans);
  }
  cout << ans;
  return 0;
}
