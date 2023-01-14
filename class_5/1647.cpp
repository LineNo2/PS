#include <bits/stdc++.h>
#define MAX_NODE 100001
#define MAX_EDGE 1000001

using namespace std;

typedef struct Edge{
  int from;
  int to;
  int cost;
  bool operator < (const Edge &e) const{
	return cost > e.cost;
  }
}Edge;

int N, M;

int Parent[MAX_NODE];

int find(int node){
  if(node == Parent[node]) return node;
  return Parent[node] = find(Parent[node]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  Parent[b] = a;
  return;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int from, to, cost;
  int ans =0 ;
  int last_cost;
  priority_queue<Edge> PQ;
  cin >> N >> M;
  for(int i = 1 ; i <= N ; ++i){
    Parent[i] = i;
  }
  for(int i = 0 ; i < M ; ++i){
	cin >> from >> to >> cost;
	PQ.push({.from = from, .to = to, .cost = cost});
  }
  while(!PQ.empty()){
	from = PQ.top().from;
	to = PQ.top().to;
	cost = PQ.top().cost;
  PQ.pop();
	if(find(from) == find(to)) continue;
	ans += cost;
	last_cost = cost;
	merge(from,to);
  }
  cout << ans - last_cost;
  return 0;
}

