#include <iostream>
#include <algorithm>
#include <vector>
#define N 10000

using namespace std;

typedef struct Vertex{
  int to;
  int dist;
}Vertex;

vector<Vertex> G[N];
bool is_visited[N];
int n;
int max_value = 0;
int max_index;

void dfs(int st_, int value_){
  if(is_visited[st_] == true) return;
  is_visited[st_] = true;

  if( value_ > max_value ){
	max_value = value_;
	max_index = st_;
  }
  for(int i = 0 ; i < G[st_].size() ; ++i){
	dfs(G[st_][i].to, value_ + G[st_][i].dist);
  }
}

int main(){
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL);
  int from, to ,dist;
  cin >> n;
  for(int i = 0 ; i < n-1 ;++i){
	cin >> from >> to >> dist;
	G[from].push_back({.to = to, .dist = dist});
	G[to].push_back({.to = from, .dist = dist});
  }
  dfs(1,0);
  fill(is_visited, is_visited + n + 1, 0);
  max_value = 0;
  dfs(max_index, 0);
  cout << max_value;
  return 0;
}

