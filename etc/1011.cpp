#include <bits/stdc++.h>

using namespace std;

long long st, ed;

int TC;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> TC;
  for(int tc = 0 ; tc < TC ; ++tc){
	cin >> st >> ed;
	long long range = ed - st;
	int ans;
	long long cur = 0;
	for(long long i = 1 ;; ++i){
	  long long next = cur + i * 2;
	  if(cur < range && range <= next){
		ans = i*2;
		if((next+cur)/2 >=  range) ans -= 1;
		break;
	  }
	  cur = next;
	}
	cout << ans << endl;
  }
  return 0;
}
