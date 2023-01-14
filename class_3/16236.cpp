#include <iostream>
#include <queue>
#include <string.h>

typedef struct Fish{
  int x;
  int y;
  int size;
}Fish;

Fish tagret[400];

typedef struct Point{
  int x;
  int y;
  int time;
}Point;

std::queue<Point> Q;

//bool compare(Fish& p1, Fist& p2){
//  if(p1.x == p2.x){
//	if(p1.y == p1.y){
//	  return p1.size < p2.size;
//	}
//  }
//}


int main(){
  int map[20][20]={0,};
  int is_visited[20][20]={0,};
  int shark_size = 2;
  int fishes = 0;
  int n;
  int temp;
  int start_x, start_y;
  int flag = -1;
  int min_x, min_y;
  int min_dist;
  Point temp1, temp2;
  int time;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  scanf("%d",&temp);
	  map[i][j] = temp;
	  if(temp == 9){
		start_x = i;
		start_y = j;
	  }
	}
  }
  time = 0;
  while(1){
  temp1.time = 0;
  temp1.x = start_x;
  temp1.y = start_y;
  Q.push(temp1);
  map[temp1.x][temp1.y] = 0;
  flag = -1;
  min_x = 987654321;
  min_y = 987654321;
  min_dist = -1;
  for(int i = 0 ; i < n; ++i){
    memset(is_visited[i], 0, sizeof(int) * n);
  }
  while(Q.empty() == false){
	temp2 = Q.front();
	Q.pop();
	if(temp2.x < 0 || temp2.y < 0 || temp2.x >= n || temp2.y >= n) continue;
	if((temp = map[temp2.x][temp2.y]) > shark_size) continue;
  if(is_visited[temp2.x][temp2.y] == 1) continue;
  is_visited[temp2.x][temp2.y] = 1;
	if(temp != 0 && temp < shark_size) {
    if(min_dist == -1){
      min_dist = temp2.time;
      min_x = temp2.x;
      min_y = temp2.y;
    }
    if(min_dist < temp2.time) break;
    if(min_x > temp2.x){
      min_x = temp2.x;
      min_y = temp2.y;
    }else if(min_x == temp2.x && min_y > temp2.y){
      min_x = temp2.x;
      min_y = temp2.y;
    }
	}
	Q.push((Point){.x = temp2.x - 1, .y = temp2.y, .time = temp2.time + 1});
	Q.push((Point){.x = temp2.x, .y = temp2.y - 1, .time = temp2.time + 1});
	Q.push((Point){.x = temp2.x, .y = temp2.y + 1, .time = temp2.time + 1});
	Q.push((Point){.x = temp2.x + 1, .y = temp2.y, .time = temp2.time + 1});
  }
  if(min_dist == -1){
	printf("%d",time);
	return 0;
  }
  while(Q.empty() == false){
	Q.pop();
  }
  if(++fishes == shark_size){
	  ++shark_size;
    fishes = 0;
  }
  time += min_dist;
  start_x = min_x;
  start_y = min_y;
  // printf("%d %d -> %d \n",start_x, start_y, time);
  }
}



  
