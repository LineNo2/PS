#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int max(int a, int b){
  return a > b ? a : b;
}

int N, A[MAX];
int d_des[MAX];
int d_asc[MAX];

int ans = 1;

int main(){
  cin >> N;
  for(int i = 0 ; i < N ; ++i)
	cin >> A[i];
  for(int i = 0 ; i < N ; ++i){
	d_asc[i] = 0;
	for(int j = 0 ; j < i ; ++j){
	  if(A[i] > A[j]){
		d_asc[i] = max(d_asc[i], d_asc[j]);
	  }
	}
	++d_asc[i];
  }
  for(int i = N - 1 ; i >= 0 ; --i){
	d_des[i] = 0;
	for(int j = N - 1 ; j > i ; --j){
	  if(A[i] > A[j]){
		d_des[i] = max(d_des[i], d_des[j]);
	  }
	}
	++d_des[i];
	ans = max(ans, d_asc[i] + d_des[i] - 1);
  }
  cout << ans;
  return 0;
}

