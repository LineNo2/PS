#include <bits/stdc++.h>
#define N_MAX 10

using namespace std;

typedef struct Point{
  int x, y;
  bool operator == (const Point &p) const{
	return p.x == x && p.y == y;
  }
}Point;

typedef struct Oper{
  Point red;
  Point blue;
  int cnt;
}Oper;

int Board[N_MAX][N_MAX];

bool is_visited[N_MAX][N_MAX][N_MAX][N_MAX];
int N, M;

bool determin_marble_order(Point red, Point blue, int oper){ // true -> red , false ->blue first
  bool flag = true;
  switch(oper){
	case 0:
	  if(red.y == blue.y && red.x > blue.x) flag = false;
	  break;
	case 1:
	  if(red.y == blue.y && red.x < blue.x) flag = false;
	  break;
	case 2:
	  if(red.x == blue.x && red.y > blue.y) flag = false;
	  break;
	case 3:
	  if(red.x == blue.x && red.y < blue.y) flag = false;
	  break;
  }
  return flag;
}

Point move_marble(Point marble, int oper){
  int i;
  int x = marble.x, y = marble.y;
  switch(oper){
	case 0: // up
	  for(i = marble.x ; i >= 0; --i){
		if(Board[i][marble.y] != 0) {
		  if(Board[i][marble.y] == -2) ++i;
		  break;
		}
	  }
	  x = i;
	  break;
	case 1:
	  for(i = marble.x ; i < N; ++i){
		if(Board[i][marble.y] != 0) {
		  if(Board[i][marble.y] == -2) --i;
		  break;
		}
	  }
	  x = i;
	  break;
	case 2://left
	  for(i = marble.y ; i >= 0 ; --i){
		if(Board[marble.x][i] != 0) {
		  if(Board[marble.x][i] == -2) ++i;
		  break;
		}
	  }
	  y = i;
	  break;
	case 3:
	  for(i = marble.y ; i < M ; ++i){
		if(Board[marble.x][i] != 0) {
		  if(Board[marble.x][i] == -2) --i;
		  break;
		}
	  }
	  y = i;
	  break;
  }
  return {.x = x, .y = y};
}

void print_Board(Point red, Point blue){
  for(int i = 0;  i < N  ;++i){
	for(int j = 0 ; j < M ; ++j){
	  if(red.x == i && red.y ==j) printf("R");
	  else if(blue.x == i && blue.y == j) printf("B");
	  else if(Board[i][j] == -1) printf("O");
	  else if(Board[i][j] == 0) printf(".");
	  else printf("#");
	}
	printf("\n");
  }
}

int main(){
  Point red, blue, hole;
  int cnt;
  char temp;
  queue<Oper> Q;
  scanf("%d %d\n",&N,&M);
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < M ; ++j){
	  temp = getchar();
	  switch(temp){
		case '#':
		  Board[i][j] = -2;
		  break;
		case '.':
		  Board[i][j] = 0;
		  break;
		case 'O':
		  hole.x = i; hole.y = j;
		  Board[i][j] = -1;
		  break;
		case 'R':
		  //Board[i][j] = 1;
		  red.x = i; red.y = j;
		  break;
		case 'B':
		  //Board[i][j] = 2;
		  blue.x = i; blue.y = j;
		  break;
	  }
	}
	getchar();
  }
  //보드를 큐에 담는 대신, 구슬을 보드에 임시로 표시하자.
  Q.push({ .red = red, .blue = blue, .cnt = 0});
  while(!Q.empty()){
	red = Q.front().red;
	blue = Q.front().blue;
	cnt = Q.front().cnt;
	// printf("%d ->\n",cnt);
	// print_Board(red,blue);
	Q.pop();
	if(cnt > 10) continue;
	if(red == hole) {
	  if(blue == hole){
		continue;
	  }
	  else{
		printf("%d",cnt); return 0;
	  }
	}

	for(int i = 0 ; i < 4 ; ++i){
	  Point next_red, next_blue, temp_p;
	  int temp_board;
	  bool flag = false; // red & blue change
	  if(!determin_marble_order(red, blue, i)){
		flag = true;
		swap(red, blue);
	  }
	  //구슬이 존재할 수 있는곳은 .(0) 뿐.
		temp_board = Board[blue.x][blue.y];
	  Board[blue.x][blue.y] = -2;
	  next_red = move_marble(red, i);
	  Board[blue.x][blue.y] = temp_board;
	  if(!(next_red == hole)){
		//next_red가 존재할 수 있는곳은 . 또는 구멍, 구멍이 아니라면 -2로 바꿔서 시뮬해야함.
		temp_board = Board[next_red.x][next_red.y];
		Board[next_red.x][next_red.y] = -2;
	  }
	  else{
		//next_red == hole 인데 스왑된거면 blue가 들어간것이므로 종료해야함.
		if(flag) {
			swap(red,blue);
			continue;
			}
	  }
	  next_blue = move_marble(blue, i);
	  if(!(next_red == hole)) 
		Board[next_red.x][next_red.y] = temp_board;
	  if(flag) {
		swap(next_red, next_blue);
		swap(red, blue);
	  }
	  if(is_visited[next_red.x][next_red.y][next_blue.x][next_blue.y]) continue;
	  is_visited[next_red.x][next_red.y][next_blue.x][next_blue.y] = true;
	  Q.push({.red = next_red, .blue = next_blue, .cnt = cnt + 1});
	}
  }
  printf("-1");
  return 0;
}
