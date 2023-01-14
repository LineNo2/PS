#include <bits/stdc++.h>
#define N_MAX 1000001

using namespace std;

int N;

int DP[N_MAX];
int Trace[N_MAX];

void DFS(int n){
  cout << n <<" ";
  if(n != 1) DFS(Trace[n]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int cur;
  queue<int> Q;
  cin >> N;
  Q.push(1);
  while(!Q.empty()){
	cur = Q.front();
	Q.pop();
	if(cur == N) break;
	int next = cur*3;
	if(next < N_MAX && DP[next] == 0){
	  Trace[next] = cur;
	  DP[next] = DP[cur] + 1;
	  Q.push(next);
	}
	next = cur*2;
	if(next <= N_MAX  && DP[next] == 0){
	  Trace[next] = cur;
	  DP[next] = DP[cur] + 1;
	  Q.push(next);
	}
	next = cur + 1;
	if(next <= N_MAX  && DP[next] == 0){
	  Trace[next] = cur;
	  DP[next] = DP[cur] + 1;
	  Q.push(next);
	}
  }
  cout << DP[N] << endl;
  DFS(N);
  return 0;
}


