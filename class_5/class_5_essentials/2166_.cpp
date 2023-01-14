#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
  long long  x0,y0;
  long long  x1, y1, x, y;
  long double ans = 0;
  cin >> N >> x >> y;
  x0 = x; y0 = y;
  x1 = x; y1 = y;
  for(int i = 1 ; i < N ; ++i){
	cin >> x >> y ;
	ans += x1 * y;
	ans -= x * y1;
	x1 = x;
	y1 = y;
  } 
  ans += x * y0;
  ans -= y * x0;
  printf("%.1Lf",abs(ans)/2.0);
  return 0;
}

