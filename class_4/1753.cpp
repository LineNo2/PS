#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

typedef struct Vertex{
  int ed;
  int value;
	bool operator<(const Vertex& vertex)const {
		return value < vertex.value;
	}
}Vertex;

int min(int a, int b){
  return a > b ? b : a;
}

vector<Vertex> G[20001];
// int G[20001][20001];
queue<int> Q;
// int d[20001];
vector<int> d;

bool is_visited[20001];

int n, m;
int start;

Vertex get_info_of_edge(int st, int ed){
	for(int i = 0 ; i < G[st].size() ; ++i){
		if(G[st][i].ed == ed) return G[st][i];
	}
	return {.ed = -1, .value = INF};
}

int get_info_of_index(int st, int ed){
	for(int i = 0 ; G[st].size() ; ++i){
		if(G[st][i].ed == ed) return i;
	}
	return -1;
}

void dijkstra_priorityqueue(int st_){
	d = vector<int>(n+1, INF);
	d[st_] = 0;
	priority_queue<Vertex> pq;
	pq.push({.ed = st_, .value = 0});
	while(!pq.empty()){
		int cost = pq.top().value;
		int node = pq.top().ed;

		pq.pop();

		if(d[node] < cost) continue;
		for(int i = 0 ; i<G[node].size(); ++i){
			int next = G[node][i].ed;
			int nextD = G[node][i].value + cost;

			if(nextD < d[next]){
				d[next] = nextD;
//				printf("%d is now %d\n",next , nextD);
				pq.push({.ed = next, .value = nextD});
			}
		}
	}
}


int main(){
  int st, ed, value;
	int temp_index;
  scanf("%d %d %d",&n, &m, &start);
  for(int i = 0 ; i < m ; ++i){
	scanf("%d %d %d",&st, &ed, &value);
//	if(get_info_of_edge(st,ed).ed == -1)
		G[st].push_back({ .ed = ed, .value = value});
//	else{
//		temp_index = get_info_of_index(st,ed);
//		G[st][temp_index].value = min( G[st][temp_index].value , value);
//	}
	}
	dijkstra_priorityqueue(start);
  for(int i = 1; i <= n ; ++i){
	if(d[i] == INF)
	  printf("INF\n");
	else{
	  printf("%d\n",d[i]);
	}
  }
  return 0;
}
  
