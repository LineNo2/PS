#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

vector<int> edges[MAX];

int parents[MAX];
bool is_visited[MAX];

void dfs(int node){
  for(int i = 0 ; i < edges[node].size() ; ++i){
    if(is_visited[edges[node][i]] == true) continue;
    is_visited[edges[node][i]] = true;
    parents[edges[node][i]] = node;
    dfs(edges[node][i]);
  }
}

int main(){
  int n;
  int from, to;
  cin >> n;
  for(int i = 0 ; i < n -1 ; ++i){
	cin >> from >> to;
  edges[from].push_back(to);
  edges[to].push_back(from);
  }
  is_visited[1] = true;
  dfs(1);
  for(int i = 2 ; i <= n; ++i){
    printf("%d\n",parents[i]);
  }
  return 0;
}
