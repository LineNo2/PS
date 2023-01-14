#include <cstdio>
#include <iostream>
#include <queue>

typedef struct Pos{
  int x;
  int y;
}Pos;

Pos oper[4] = { 
  {.x = -1, .y = 0}, 
  {.x = 1, .y = 0}, 
  {.x = 0, .y = 1}, 
  {.x = 0, .y = -1}
};

int n, m;
bool map[101][101];
int is_visited[101][101] = {0,};


void print_map(){
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < m ;++j){
	  printf("%d ",is_visited[i][j]);
	}
	printf("\n");
  }
}

std::queue<Pos> queue;

int main(){
  char temp;
  Pos arr[101];
  Pos temp1, temp2;
  scanf("%d %d\n", &n, &m);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < m ; ++j){
	  temp = getchar();
	  map[i][j] = temp - '0';
	}
	getchar();
  }
  temp1.x = 0;
  temp1.y = 0;
  queue.push(temp1);
  is_visited[0][0] = 1;
  while(queue.empty() == false){
	temp1 = queue.front();
	queue.pop();
	for(int i = 0 ; i < 4 ;++i){
	  temp2.x = temp1.x + oper[i].x;
	  temp2.y = temp1.y + oper[i].y;
	  if(temp2.x < 0 || temp2.y < 0 || temp2.x >= n || temp2.y >= m) continue;
	  if(map[temp2.x][temp2.y] == false) continue;
	  if(is_visited[temp2.x][temp2.y] > 0) continue;
	  if(temp2.x == n-1 && temp2.y == m-1){
		//print_map();
		//printf("%d %d\n", temp2.x, temp2.y);
		printf("%d",is_visited[temp1.x][temp1.y] + 1);
		return 0;
	  }
	  queue.push(temp2);
	  is_visited[temp2.x][temp2.y] = is_visited[temp1.x][temp1.y] + 1;
  }
  }
  return 0;
}



