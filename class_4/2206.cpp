#include <iostream>
#include <algorithm>
#include <queue>
#define N 1000
#define M 1000

typedef struct Point{
  int x;
  int y;
  bool flag;
  int dist;
}Point;

typedef struct Oper{
  int x_oper;
  int y_oper;
}Oper;

Oper opers[4] = { {1,0},{0,1},{-1,0},{0,-1}};

std::queue<Point> Q;

bool is_visited[N][M]={false,};
bool is_visited_flag[N][M]={false,};
bool map[N][M]={false,}; // false : no wall / true : wall

int main(){
  int n, m;
  char temp;
  scanf("%d %d\n",&n, &m);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < m ; ++j){
	  temp = getchar();
	  map[i][j] = temp == '0' ? false : true;
	}
	getchar();
  }
  //BFS;
  Point temp_point;
  Q.push({.x = 0 , .y = 0, .flag = false, .dist = 1});
  while(Q.empty() == false){
	temp_point = Q.front();
	Q.pop();
	if( temp_point.x == n-1 && temp_point.y == m-1) {
	  	printf("%d",temp_point.dist);
	  	return 0;
		}
	++temp_point.dist ;
	// next Points push to Q
	for(int i = 0 ; i < 4; ++i){
	  int x = temp_point.x + opers[i].x_oper;
	  int y = temp_point.y + opers[i].y_oper;
	  if( x < 0 || y < 0 || x >= n || y >= m) continue;
		if(is_visited[x][y]) continue;
		
	  if(temp_point.flag == true){
		if(is_visited_flag[x][y] == true) continue;
		if(map[x][y] == true) continue;
		Q.push({.x = x, .y = y, .flag = true, .dist = temp_point.dist});
		is_visited_flag[x][y] = true;
		// is_visited[x][y] = true;
	  }
	  else{
		if(is_visited[x][y] == true) continue;
		if(map[x][y] == true){
		  if(is_visited_flag[x][y] == true) continue;
			Q.push({.x = x, .y = y, .flag = true, .dist = temp_point.dist});
			is_visited_flag[x][y] = true;
			// is_visited[x][y] = true;
		}
		else{
		  Q.push({.x = x, .y = y, .flag = false, .dist = temp_point.dist});
			is_visited[x][y] = true;
		}
	  }
	}
  }
  printf("-1");
  return 0;
}
