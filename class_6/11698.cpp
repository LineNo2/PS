#include <bits/stdc++.h>

using namespace std;

long long N;

int main(){
  cin >> N;
  long long  ans = 1, num = N;
  for(int i = 2 ; i*i <= N; ++i){
	if(num % i == 0){
	  int count = 0;
	  while(num % i == 0){
		++count;
		num /= i;
	  }
	  ans *= ((long long)pow(i, count - 1) * ( i - 1 ));
	}
  }
  if(num > 1) ans *= (num - 1);
  cout << ans;
  return 0;
}
