#include <bits/stdc++.h>
#define N_MAX 4000001

using namespace std;

int N;

long long Prime[N_MAX];

bool Number[N_MAX];

int main(){
  int ans = 0;
  cin >> N;
  for(int i = 2 ; i < N_MAX; ++i){
	if(Number[i]) continue;
	for(int j = i * 2 ; j < N_MAX ; j += i){
	  Number[j] = true;
	}
  }
  Prime[0] = 0;
  int prime_cnt = 1;
  for(int i = 2; i < N_MAX ; ++i){
	if(Number[i]) continue;
	Prime[prime_cnt] += Prime[prime_cnt-1] + i;
	++prime_cnt;
  }
  for(int i = 0, j = 1 ; i <= prime_cnt ; ++i){
	for(; j <= prime_cnt ; ++j){
	  if(Prime[j] - Prime[i] >= N){
		if(Prime[j] - Prime[i] == N) ++ans;
		break;
	  }
	}
  }
  cout << ans;
  return 0;
}
