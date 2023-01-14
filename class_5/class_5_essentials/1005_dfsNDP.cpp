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
vector<int> edges[MAX_NODE];
int cost_buildings[MAX_NODE];
int cnt;
int result[MAX_NODE];

int dfs(int node){
	if(edges[node].empty()) return result[node] = cost_buildings[node];
	if(result[node] != -1) return result[node];
	for(int i = 0 ; i < edges[node].size() ; ++i){
		int next_node = edges[node][i];
		result[node] = max(result[node], dfs(next_node) + cost_buildings[node]);
	}
	return result[node];
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
  int from, to;
  int goal;
  cin >> T;
  for(int tc = 0 ; tc < T ; ++tc){
	//init
	for(int i = 0 ; i < MAX_NODE ; ++i){
	  edges[i].clear();
		result[i] = -1;
	}
	cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i)
	  cin >> cost_buildings[i];
	for(int i = 0 ; i < K ; ++i){
	  cin >> from >> to;
	  edges[to].push_back(from);
	}
	cin >> goal;
	cout << dfs(goal)<< endl;
  }
  return 0;
}


