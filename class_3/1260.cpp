#include <iostream>
#include <queue>
#include <string.h>

int map[1001][1001];
int is_visited[1001];
int n, m, st;
int temp_st, temp_end;

std::queue<int> queue;

void dfs(int end){
  if(is_visited[end] == 1)
	return;
  is_visited[end] = 1;
  printf("%d ", end);
  for(int i = 1 ; i <= n ; ++i){
	if(map[end][i] == 1)
	  dfs(i);
  }
}


int main(){
  std::scanf("%d %d %d",&n, &m, &st);
  for(int i = 0 ; i < m ; ++i){
	scanf("%d %d",&temp_st, &temp_end);
	map[temp_st][temp_end] = 1;
	map[temp_end][temp_st] = 1;
  }
  is_visited[st] = 1;
  printf("%d ",st);
  for(int i = 1 ; i <= n ; ++i){
	if(map[st][i] == 1)
	  dfs(i);
  }
  memset(is_visited, 0, sizeof(is_visited));
  printf("\n");
  is_visited[st] = 1;
  queue.push(st);
  while(queue.empty() == false){
	temp_end = queue.front();
	queue.pop();
	printf("%d ",temp_end);
	for(int i = 1 ; i <= n ; ++i){
	  if(map[temp_end][i] == 1 && is_visited[i] == 0){
		queue.push(i);
		is_visited[i] = 1;
	  }
	}
  }
  return 0;
}
  
