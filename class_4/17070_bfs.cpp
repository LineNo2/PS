#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX_N 16

using namespace std;

int N;

typedef struct Point{
  int x;
  int y;
  Point operator + (Point &p){
	return {.x = x + p.x , .y = y + p.y};
  }
}Point;

typedef struct Pipe{
  int status; // 0 -> horizotial , 1 -> vertical , 2 -> diagonal
  Point head;
}Pipe;

Point pipe_oper[3] = {
  {.x = 0 , .y = 1},
  {.x = 1 , .y = 0},
  {.x = 1 , .y = 1}
};

bool map[MAX_N][MAX_N];

bool check_path_valid(Point head, int next_status){
  Point next_head;
	for(int i = 0 ; i < 3; ++i){
   if(next_status == 2 || next_status == i ) 
  {
    next_head = pipe_oper[i] + head;
    if(next_head.x >= N || next_head.y >= N) return false;
	  if(map[next_head.x][next_head.y]) return false;
  }
  }
  return true;
}

int main(){
  queue<Pipe> Q;
  int cur_status;
  int count = 0;
  int exec_count = 0;
  Point cur_head;
  Point next_head;
  cin >> N;
  for(int i = 0 ; i < N ; ++i)
	for(int j = 0 ; j < N ; ++j)
	  cin >> map[i][j];
  Q.push({.status = 0, .head = {.x = 0, .y = 1} });
  while(!Q.empty()){
	cur_status = Q.front().status;
	cur_head =  Q.front().head;
  Q.pop();
	for(int i = 0 ; i < 3 ; ++i){
    if(cur_status == 2 
    || (cur_status == 1 && i != 0) 
    || (cur_status == 0 && i != 1)
    ) {
      if(check_path_valid(cur_head, i)){
        next_head = cur_head + pipe_oper[i];
	      if(next_head.x == N - 1 && next_head.y == N - 1) { ++count; continue; }
		    Q.push({.status = i , .head = next_head});
      }
    }
  }
  }
  cout << count;
  return 0;
}

