#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef struct Dice{
  int n;
  int s;
}Dice;

long long fast_pow(int n, int k){
  if(k == 1) return n % MOD;
  if(k % 2 == 0) {
	long long temp = fast_pow(n, k/2) % MOD;
	return (temp * temp) % MOD;
  }
  else{
	long long temp = fast_pow(n, (k-1)/2) % MOD;
	return ( ( (temp * temp) % MOD ) * (n % MOD) ) % MOD;
  }
}


int M;

long long sum = 0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, s;
  cin >> M;
  for(int i = 0 ; i < M ; ++i){
	cin >> n >> s;
	sum += ( s * fast_pow(n, MOD - 2) ) % MOD;
  sum %= MOD;
  }
  cout << sum;
  return 0;
}
