#include <iostream>
#include <queue>
#include <vector>
#define MAX_NODE 101
#define MAX_EDGE 101
#define INF 987654321

using namespace std;

int N,M,R;

int max(int a, int b){
  return a > b ? a : b;
}

typedef struct Edge{
  int to;
  int dist;
  bool operator < ( const struct Edge &e )const{
	return dist < e.dist;
  }
}Edge;

int nodes[MAX_NODE];
vector<Edge> edges[MAX_NODE];

vector<int> dijkstra(int st){
  vector<int> D(MAX_NODE, INF);
  priority_queue<Edge> pq;
  pq.push({.to = st, .dist = 0});
  D[st] = 0;
  while(!pq.empty()){
	int to = pq.top().to;
	int dist = pq.top().dist;
  pq.pop();

	if(dist > D[to]) continue;

	for(int i = 0 ; i < edges[to].size() ; ++i){
	  int next = edges[to][i].to;
	  int next_dist = edges[to][i].dist + dist;

	  if(next_dist < D[next]){
		D[next] = next_dist;
		pq.push({.to = next, .dist = next_dist});
	  }

	}
  }
  return D;
}

int main(){
  int temp;
  int from, to ,dist;
  int ans = 0;
  vector<int> D_st;
  cin >> N >> M >> R;
  for(int i = 1 ; i <= N ; ++i){
	cin >> temp;
	nodes[i] = temp;
  }
  for(int i = 0 ; i < R ; ++i){
	cin >> from >> to >> dist;
	edges[from].push_back({.to = to, .dist = dist});
	edges[to].push_back({.to = from, .dist = dist});
  }
  for(int i = 1; i<= N ;++i){
	D_st = dijkstra(i);
	temp = 0;
	for(int i = 1 ; i <= N ;++i){
	  if(D_st[i] > M) continue;
	  temp += nodes[i];
	}
	ans = max(temp, ans);
  }
  cout << ans;
  return 0;
}



