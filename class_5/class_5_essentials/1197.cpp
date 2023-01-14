#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define MAX_NODE 10001
#define MAX_EDGE 100001

using namespace std;

typedef struct Edge{
  int from;
  int to;
  int dist;
  bool operator<(const struct Edge& E)const{
	return dist > E.dist;
  }
}Edge;

int V, E;

vector<Edge> edges;

int parent[MAX_NODE];

int find(int e){
  if(parent[e] == e) return e;
  return parent[e] = find(parent[e]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  parent[b] = a;
}

int main(){
  int ans = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  priority_queue<Edge> PQ;
  int from, to, dist;
  cin >> V >> E;
  for(int i = 1 ; i <= V ; ++i)
  parent[i] = i;
  for(int i = 0 ; i < E ; ++i){
	cin >> from >> to >> dist;
	PQ.push({.from = from, .to = to , .dist = dist});
	// edges.push_back({.from = from, .to = to , .dist = dist});
  }
  while(!PQ.empty()){
	from = PQ.top().from;
	to = PQ.top().to;
	dist = PQ.top().dist;
	PQ.pop();
  if(find(to) == find(from)) continue;
  merge(to, from);
	ans += dist;
  }
  cout << ans;
  return 0;
}
