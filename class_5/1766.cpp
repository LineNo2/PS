#include <bits/stdc++.h>
#define MAX_N 32001

using namespace std;

int N, M;

int inorder[MAX_N];

vector<int> Edges[MAX_N];

int main(){
  priority_queue<int> PQ;
  int from, to , cur;
  cin >> N >> M;
  for(int i = 0 ; i < M ; ++i){
	cin >> from >> to;
	++inorder[to];
	Edges[from].push_back(to);
  }
  for(int i = 1 ; i <= N ; ++i){
	if(inorder[i]) continue;
	PQ.push(-i);
  }
  while(!PQ.empty()){
	cur = -PQ.top();
	PQ.pop();
	cout << cur <<" ";
	for(int i = 0 ; i < Edges[cur].size() ; ++i){
	  int next = Edges[cur][i];
	  if(--inorder[next] == 0) PQ.push(-next);
	}
  }
  return 0;
}
