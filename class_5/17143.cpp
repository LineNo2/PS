#include <bits/stdc++.h>
#define N_MAX 101

using namespace std;

typedef struct Point{
  int x, y;
  Point operator + (Point &p){
	return {.x = x + p.x , .y = y + p.y};
  }
  Point operator * (Point &p){
	return {.x = x * p.x , .y = y * p.y};
  }
  bool operator == (const Point &p) const{
	return p.x == x && p.y == y;
  }
}Point;

Point oper[4] = {
  {.x = -1, .y = 0},
  {.x = 1, .y = 0},
  {.x = 0, .y = 1},
  {.x = 0, .y = -1}
};

int R, C, M;

int Map[N_MAX][N_MAX];
int Map_next[N_MAX][N_MAX];
int S_index_by_size[1001];
FILE *fp;

typedef struct Shark{
  Point p;
  int size;
  int vector;
  Point velocity;
  void move(){
	fprintf(fp, "Shark size : %d, velocity : (%d,%d), pos : (%d, %d) ->",size,velocity.x,velocity.y,p.x,p.y);
	Point adder = oper[vector] * velocity;
	fprintf(fp, "adder : (%d ,%d) ", adder.x, adder.y);
	p = p + adder;
	if(p.x < 0) {
	  p.x = -p.x;
	  vector = 1;
	}
	if(p.y < 0) {
	  p.y = -p.y;
	  vector = 2;
	}
	p.x = p.x % (2*R - 2);
	p.y = p.y % (2*C - 2);
	if(p.x >= R) {
	  p.x = (R-1) - (p.x % R) - 1;
	  vector = 0;
	}
	if(p.y >= C) {
	  p.y = (C-1) - (p.y % C) - 1;
	  vector = 3;
	}
	if(Map_next[p.x][p.y]){
	  if(Map_next[p.x][p.y] < size) {
		S_index_by_size[Map_next[p.x][p.y]] = -1;
		Map_next[p.x][p.y] = size;
	  }
	  else S_index_by_size[size] = -1;
	}
	else Map_next[p.x][p.y] = size;
	fprintf(fp, " (%d, %d)\n",p.x,p.y);
  }
}Shark;

Shark S[N_MAX*N_MAX];

void printMap(){
  for(int i = 0 ; i < R ; ++i){
	for(int j = 0 ; j < C ; ++j){
	  fprintf(fp,"%5d",Map[i][j]);
	}
	fprintf(fp,"\n");
  }
}

int main(){
  int r, c, s, d, z;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fp = fopen("./output.txt","r+");
  cin >> R >> C >> M;
  memset(S_index_by_size,-1,sizeof(S_index_by_size));
  for(int i = 0 ; i < M ; ++i){
	cin >> r >> c >> s >> d >> z;
	--r;
	--c;
	--d;
	Map[r][c] = z;
	S[i].p.x = r;
	S[i].p.y = c;
	S[i].velocity = (Point){.x = s, .y = s};
	S[i].vector = d;
	S[i].size = z;
	S_index_by_size[z] = i;
  }
  int ans = 0;
  for(int t = 0 ; t < C ; ++t){
	memset(Map_next,0,sizeof(Map_next));
	fprintf(fp,"%dth's trial\n",t);
	printMap();
	for(int i = 0 ; i < R ; ++i){
	  int shark_size = Map[i][t];
	  if(!shark_size) continue;
	  ans += shark_size;
	  S_index_by_size[shark_size] = -1;
	  fprintf(fp,"target : %d\n",shark_size);
	  break;
	}
	for(int i = 1 ; i <= 10000 ; ++i){
	  int shark_index = S_index_by_size[i];
	  if(shark_index == -1) continue;
	  S[shark_index].move();
	}
	for(int i = 0 ; i < R ; ++i)
	  for(int j = 0 ; j < C ; ++j)
		Map[i][j] = Map_next[i][j];
  }
  cout << ans;
  return 0;
}

