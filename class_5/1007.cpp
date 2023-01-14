#include <bits/stdc++.h>
#define MAX_N 21
using namespace std;

int TC;

int N;
long long x[MAX_N], y[MAX_N];
int operators[MAX_N];

double ans;

double calVectorMatching(){
  long long x_val = 0, y_val = 0;
  for(int i = 0 ; i < N ; ++i){
	x_val += operators[i] * x[i];
	y_val += operators[i] * y[i];
  }
  return sqrt(x_val*x_val + y_val*y_val);
}

void DFS(int num_of_plus, int idx){
  if(idx == N){
		if(num_of_plus == 0)
	    ans = min(ans, calVectorMatching());
	return ;
  }
	// if(num_of_plus == 0){
	// 	operators[idx] = 1;
	// 	DFS(0, idx + 1);
	// }
  // else if(num_of_plus > idx){
	  operators[idx] = 1;
	  DFS(num_of_plus, idx + 1);
		operators[idx] = -1;
		DFS(num_of_plus - 1, idx + 1);
  // }
	// else{
	//   operators[idx] = -1;
	//   DFS(num_of_plus - 1, idx + 1);
	// }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(8);
  cin >> TC;
  for(int c = 0 ; c < TC ; ++c){
	cin >> N;
	ans = 987654321;
	memset(operators, 0, sizeof(operators));
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	for(int i = 0 ; i < N ; ++i)
	  cin >> x[i] >> y[i];
	DFS(N/2, 0);
	cout << fixed << ans << endl;
  }
  return 0;
}
