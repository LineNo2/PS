#include <bits/stdc++.h>
#define MAX_N 1001

using namespace std;

int T;
int N, M;

int A[MAX_N], B[MAX_N];
vector<int> A_sum, B_sum;

int main(){
  int temp;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  cin >> N;
  for(int i = 1 ; i <= N ; ++i){
	cin >> temp;
	A[i] = A[i-1] + temp;
  }
  cin >> M;
  for(int i = 1 ; i <= M ; ++i){
	cin >> temp;
	B[i] = B[i-1] + temp;
  }\
  for(int i = 0 ; i <= N ; ++i){
	for(int j = i + 1 ; j <= N ;++j){
	  A_sum.push_back(A[j] - A[i]);
    }
  }
  sort(A_sum.begin(), A_sum.end());
  for(int i = 0; i <= M ; ++i){
	for(int j = i + 1 ; j <= M ; ++j){
	  B_sum.push_back(B[j] - B[i]);
	}
  }
  sort(B_sum.begin(), B_sum.end());
  long long former_num = 1 << 30 - 1, former_result, ans = 0;
  for(int i = 0 ; i < A_sum.size(); ++i){
	if(former_num == A_sum[i]) ans += former_result;
	else{
	  former_num = A_sum[i];
	  former_result = upper_bound(B_sum.begin(), B_sum.end(), T - former_num) 
    - lower_bound(B_sum.begin(), B_sum.end(), T - former_num);
	  ans += former_result;
	}
  }
  cout << ans;
  return 0;
}
