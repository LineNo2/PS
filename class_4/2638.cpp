#include <iostream>
#include <algorithm>
#include <queue>
#include <unistd.h>
#define MAX 100

bool map[MAX][MAX];
bool check_inside[MAX][MAX];

int n, m;
int time_chz = 0;

typedef struct Point{
  int x;
  int y;
}Point;

Point oper[4] = {
  {.x = -1, .y = 0},
  {.x = 1, .y = 0},
  {.x = 0, .y = -1},
  {.x = 0, .y = 1},
};

int get_adjcent_chz(int x, int y){
  return check_inside[x-1][y] + check_inside[x+1][y] + check_inside[x][y-1] + check_inside[x][y+1];
}

std::queue<Point> Q;


void init_arr(bool arr[][MAX]){
  for(int i = 0 ; i < n ; ++i)
  for(int j = 0 ; j < m ; ++j)
  arr[i][j] = false;
}

void check_border(){
  Point temp, temp_next;
  int flag;
  bool check_setted[MAX][MAX];
  bool is_visited[MAX][MAX];
  std::queue<Point> Q_border;
  init_arr(check_setted);
  init_arr(check_inside);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < m ; ++j){
	  if(i == 0 || j == 0 || i == n || j == m)
		check_inside[i][j] = false;
	}
  }
  for(int i = 1 ; i < n-1 ; ++i){
    for(int j = 1 ; j < m-1 ; ++j){
      if(map[i][j]) { check_inside[i][j] = true; check_setted[i][j] = true; }
      if(check_setted[i][j]) continue;
      flag = 0;
      init_arr(is_visited);
      while(Q_border.empty() == false){
        Q_border.pop();
      }
      //init
      Q_border.push({.x = i, .y = j});
      is_visited[i][j] = true;
      while(Q_border.empty() == false){
        temp = Q_border.front();
        Q_border.pop();
        for(int k = 0 ; k < 4 ; ++k){
          temp_next = {.x = temp.x + oper[k].x, .y = temp.y + oper[k].y};
          if(temp_next.x == 0 || temp_next.y == 0 || 
          temp_next.x == n-1 || temp_next.y == m-1){flag = 1;continue;}
          if(map[temp_next.x][temp_next.y] == true) continue;
          if(is_visited[temp_next.x][temp_next.y] == true) continue;
          Q_border.push(temp_next);
          is_visited[temp_next.x][temp_next.y] = true;
        }
      }
      for(int x = 1 ; x < n-1 ; ++x){
        for(int y = 1 ; y < m-1 ; ++y){
          if(is_visited[x][y] == true) { 
		  check_inside[x][y] = flag == 1 ? false : true;
		  check_setted[x][y] = true;}
        }
      }
    }
  }
}

void print_chz(){
  printf("time : %d\n",time_chz);
  for(int i = 0 ; i < n ; ++i){
  for(int j = 0 ;  j < m ; ++j){
  printf("%d ",map[i][j]);
  }
  printf("\n");
  }
  
}

int main(){
  int temp;
  Point temp_point;
  scanf("%d %d",&n, &m);
  for(int i=0;i<n;++i){
	for(int j=0;j<m;++j){
	  scanf("%d",&temp);
    map[i][j] = temp == 0 ? false : true;
    check_inside[i][j] = temp == 0 ? false : true;
	}
  }
  do{
  if(Q.empty() == false) ++time_chz;
	while(Q.empty() == false){
	  temp_point = Q.front();
	  Q.pop();
	  map[temp_point.x][temp_point.y] = false;
	}
  check_border();
   //print_chz();
  for(int i=1;i<n-1;++i){
	for(int j=1;j<m-1;++j){
    if(map[i][j]){
	    temp = get_adjcent_chz(i,j);
	    if(get_adjcent_chz(i, j) <= 2) Q.push({.x = i, .y = j});
    }
	}
  }
  }while(Q.empty() == false);
  printf("%d",time_chz);
  return 0;

}
