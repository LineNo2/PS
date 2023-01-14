#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_EDGE 100001
#define MAX_NODE 1001
using namespace std;

typedef struct Edge{
  int to;
  int dist;
  bool operator<(const Edge& p)const{
	return dist < p.dist;
  }
}Edge;

int min(int a, int b){
  return a > b ? b : a;
}
vector<int> d;
int trace[MAX_NODE];
vector<Edge> edges[MAX_NODE];

priority_queue<Edge> pq;

int N, M;
int ST, ED;

void dfs_mindist(int st, int count){
  ++count;
  if(st == ST) {cout << count <<"\n" << st <<" "; return;}
  dfs_mindist(trace[st], count);
  cout << st <<" ";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int from, to, dist;
  cin >> N >> M;
  for(int i = 0 ; i < M ; ++i){
	cin >> from >> to >> dist;
	edges[from].push_back({.to = to, .dist = dist});
  }
  cin >> ST >> ED;
  d = vector<int>(N+1, INF);
  pq.push({.to = ST, .dist = 0});
  while(!pq.empty()){
	to = pq.top().to;
	dist = pq.top().dist;
	pq.pop();

	if(d[to] < dist) continue;

	for(int i = 0 ; i < edges[to].size() ; ++i){
	  int next_node = edges[to][i].to;
	  int next_dist = edges[to][i].dist + dist;
	  if(d[next_node] > next_dist){
    // trace[next_node].clear();
    // trace[next_node].insert(trace[next_node].end(), trace[to].begin(), trace[to].end());
		trace[next_node] = to;
		d[next_node] = next_dist;
		pq.push({.to = next_node, .dist = next_dist});
	  }
    }
  }
  cout << d[ED] <<endl;
  dfs_mindist(ED, 0);
  return 0;
}


