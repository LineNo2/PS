#include <bits/stdc++.h>
#define MAX_N 20

using namespace std;

typedef struct Point{
  int x,y;
}Point;

typedef struct Elem{
  Point point;
  int cnt;
  int bitmask;
}Elem;

int R, C;

Point oper[4] = {
  {.x = 1 , .y = 0},
  {.x = -1, .y = 0},
  {.x = 0, .y = 1},
  {.x = 0, .y = -1}
};

char Board[MAX_N][MAX_N];

bool is_visited[MAX_N][MAX_N][1<<26];

int get_alpha_bit(char A){
  return 1 << (A - 'A');
}

int main(){
  int ans = 0;
  queue<Elem> Q;
  cin >> R >> C;
  for(int i = 0 ; i < R ; ++i)
	for(int j = 0 ; j < C ; ++j)
	  cin >> Board[i][j];
  Q.push({.point = {.x = 0, .y = 0}, .cnt = 1, .bitmask = (1 << get_alpha_bit(Board[0][0]))});
  while(!Q.empty()){
	int x = Q.front().point.x;
	int y = Q.front().point.y;
	int cur_cnt = Q.front().cnt;
	int cur_bit = Q.front().bitmask;
	Q.pop();
	ans = max(ans,cur_cnt);
	for(int i = 0 ; i < 4 ; ++i){
	  int next_x = x + oper[i].x;
	  int next_y = y + oper[i].y;
	  if(next_x < 0 || next_x >= R ||
		  next_y < 0 || next_y >= C) continue;
	  if(cur_bit & ( 1 << get_alpha_bit(Board[next_x][next_y]) )) continue;
	  int next_bit = cur_bit | (1 << get_alpha_bit(Board[next_x][next_y]));
	  if(is_visited[next_x][next_y][next_bit]) continue;
	  is_visited[next_x][next_y][next_bit] = true;
	  Q.push({.point = {.x = next_x, .y = next_y}, .cnt = cur_cnt + 1, .bitmask = next_bit});
	}
  }
  cout << ans;
  return 0;
}

