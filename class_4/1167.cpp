#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct Vertex{
  int ed;
  int value;
}Vertex;

vector<Vertex> G[100001];
bool is_visited[100001];
int n;
int max_value = 0;
int max_index;

void dfs(int st_, int value_){
  if(is_visited[st_] > 0) return;
  is_visited[st_] = 1;

  if( value_ > max_value ){
	max_value = value_;
	max_index = st_;
  }
  for(int i = 0 ; i < G[st_].size() ; ++i){
	dfs(G[st_][i].ed, value_ + G[st_][i].value);
  }
}

int main(){
  int st, ed, value;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d",&st);
	while(1){
	  scanf("%d",&ed);
	  if(ed == -1) break;
	  scanf("%d",&value);
	  G[st].push_back({ .ed = ed, .value = value});
	  G[ed].push_back({ .ed = st, .value = value});
	}
  }
  dfs(1,0);
  memset(is_visited, 0, sizeof(is_visited));
  max_value = 0;
  dfs(max_index, 0);
  printf("%d",max_value);
  return 0;
}
