#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define MAX_NODE 1001
#define MAX_EDGE 100001
#define INF 987654321
#define endl "\n"

using namespace std;

int T, N, K;

int main(){
  vector<int> edges[MAX_NODE];
  int indegree[MAX_NODE];
  int cost_buildings[MAX_NODE];
  int dp[MAX_NODE];
  bool is_visited[MAX_NODE];
  int from, to;
  int goal;
  int max_topology;
  int max_time;
  int ans;
  cin >> T;
  for(int tc = 0 ; tc < T ; ++tc){
	//init
	ans = 0;
	max_topology = 0;
	for(int i = 0 ; i < MAX_NODE ; ++i){
	  edges[i].clear();
	  indegree[i] = 0;
	  is_visited[i] = false;
	  dp[i] = 0;
	}
	// how to check diff. network
	cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i)
	  cin >> cost_buildings[i];
	for(int i = 0 ; i < K ; ++i){
	  cin >> from >> to;
	  ++indegree[to];
	  edges[from].push_back(to);
	}
	cin >> goal;
	queue<int> Q;
	for(int i = 1 ; i <= N ; ++i){
	  if(indegree[i] == 0) {
		Q.push(i);
		dp[i] = cost_buildings[i];
	  }
	}
	while(!Q.empty()){
	  int cur_node = Q.front();
	  Q.pop();
	  if(indegree[cur_node] != 0) continue;
	  if(cur_node == goal) {
			continue;
	  }
	  for(int i = 0 ; i < edges[cur_node].size() ;++i){
		int next_node = edges[cur_node][i];
	  dp[next_node] = max(dp[cur_node] + cost_buildings[next_node], dp[next_node]);
		if(--indegree[next_node] == 0) 
		  Q.push( next_node);
	  }
	}
	cout << dp[goal]<< endl;
  }
  return 0;
}


