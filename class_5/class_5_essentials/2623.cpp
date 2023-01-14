#include <bits/stdc++.h>
#define MAX_N 1001
#define endl "\n"
using namespace std;

int N, M;

vector<int> orders[MAX_N];

int inorder[MAX_N];
int program_order[MAX_N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int cnt, from, to;
  cin >> N >> M;
  for(int i = 0 ; i < M ; ++i){
	cin >> cnt >> from;
	for(int j = 1 ; j < cnt ; ++j){
	  cin >> to;
	  orders[from].push_back(to);
	  ++inorder[to];
	  from = to;
	}
  }
  queue<int> Q;
  for(int i = 1 ; i <= N ; ++i){
	if(inorder[i] == 0) Q.push(i);
  }
  int idx = 1;
  while(!Q.empty()){
	int cur = Q.front();
	Q.pop();
	program_order[idx++] = cur;
	for(int i = 0 ; i < orders[cur].size(); ++i){
	  int next = orders[cur][i];
	  if(--inorder[next] == 0) Q.push(next);
	}
  }
  if(program_order[N] == 0){
	cout << 0;
	return 0;
  }
  for(int i = 1 ; i <= N ; ++i)
	cout << program_order[i] <<endl;
  return 0;
}


