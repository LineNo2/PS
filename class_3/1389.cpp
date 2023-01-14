#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

int graph[101][101];

int is_visited[101];

int value[101];

std::queue<int> Q;

int num_of_people;
int num_of_relations;

void search(int start){
  for(int i = 1 ; i <= num_of_people ; ++i){
	if(graph[start][i] == 1 && is_visited[i] == 0){
	  Q.push(i);
	  is_visited[i] = is_visited[start] + 1;
	}
  }
}

int main(){
  int st, ed;
  int temp;
  int min = 987654321;
  scanf("%d %d",&num_of_people, &num_of_relations);
  for(int i = 0 ; i < num_of_relations ; ++i){
	scanf("%d %d",&st , &ed);
	graph[st][ed] = 1;
	graph[ed][st] = 1;
  }
  for(int i = 1 ; i <= num_of_people ; ++i){
	memset(is_visited, 0, sizeof(is_visited));
	is_visited[i] = 1;
	search(i);
	while(Q.empty() == false){
	  temp = Q.front();
	  Q.pop();
	  search(temp);
	}
	for(int j = 0 ; j <= num_of_people ; ++j)
	  value[i] += is_visited[j];
  }
  for(int i = 1 ; i <= num_of_people ; ++i){
	if(min > value[i]) {
	  min = value[i];
	  temp = i;
	}
  }
  printf("%d",temp);
  return 0;
}


