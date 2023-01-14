#include <iostream>
#include <vector>
#define MAX_ROW 50
#define MAX_COL 50

using namespace std;

typedef struct Point{
  int x;
  int y;
  Point operator + (struct Point &p){
	return {.x = x + p.x , .y = y + p.y};
  }
  bool operator == (struct Point &p){
    return x == p.x && y == p.y;
  }
}Point;

typedef struct Dust{
  int value;
  Point point;
}Dust;

int R,C,T;

Point opers[4] = {
  {.x = -1 , .y = 0},
  {.x = 1 , .y = 0},
  {.x = 0 , .y = -1},
  {.x = 0 , .y = 1}
};

vector<Dust> dusts;
vector<Point> pos_ac;

int map[MAX_ROW][MAX_COL];

void get_dust_spread(){
  int next_map[MAX_ROW][MAX_COL];
  int count;
  int spread_dust;
  Point temp_p;
  for(int i = 0; i < R ; ++i)
	for(int j = 0 ; j < C ; ++j)
	  next_map[i][j] = map[i][j];

  for(int i = 0 ; i < R ; ++i){
	for(int j = 0; j < C ; ++j){
	  count = 0;
	  if(map[i][j] == 0 || map[i][j] == -1) continue;
	  spread_dust = map[i][j] / 5;
	  for(int op = 0 ; op < 4; ++op){
		temp_p = {.x = i + opers[op].x, .y = j + opers[op].y};
		if(temp_p.x < 0 || temp_p.y < 0 || temp_p.x >= R  || temp_p.y >= C) continue;
		if(map[temp_p.x][temp_p.y] == -1) continue;
		++count;
		next_map[temp_p.x][temp_p.y] += spread_dust;
	  }
	  next_map[i][j] = next_map[i][j] - spread_dust * count;
	}
  }

  for(int i = 0; i < R ; ++i)
	for(int j = 0 ; j < C ; ++j)
	  map[i][j] = next_map[i][j];
}

void print_map(){
  cout <<"\n";
  for(int i = 0;  i < R ; ++i){

	for(int j = 0 ; j < C ; ++j){
	  cout << map[i][j] <<" ";
	}
	cout <<"\n";
  }
}

void dfs_ac_0(Point pos, int oper){
  if(map[pos.x][pos.y] == -1 && oper == 0) { 
    dfs_ac_0(pos + opers[oper], oper); 
    return;
  }
  if(pos.x == 0 && pos.y == 0) oper = 3;
  else if(pos.x == 0 && pos.y == C - 1) oper = 1;
  else if(pos.x == pos_ac[0].x && pos.y == C - 1) oper = 2;
  if(map[pos.x + opers[oper].x][pos.y + opers[oper].y] == -1 ) { 
    map[pos.x][pos.y] = 0; 
    return;
    }
  map[pos.x][pos.y] = map[pos.x + opers[oper].x][pos.y + opers[oper].y];
  dfs_ac_0(pos + opers[oper], oper);
}

void dfs_ac_1(Point pos, int oper){
  if(map[pos.x][pos.y] == -1 && oper == 1) { 
    dfs_ac_1(pos + opers[oper], oper); 
    return;
  }
  if(pos.x == R - 1  && pos.y == 0) oper = 3;
  else if(pos.x == R - 1 && pos.y == C - 1) oper = 0;
  else if(pos.x == pos_ac[1].x && pos.y == C - 1) oper = 2;
  if(map[pos.x + opers[oper].x][pos.y + opers[oper].y] == -1 ) {
     map[pos.x][pos.y] = 0; 
     return; 
    }
  map[pos.x][pos.y] = map[pos.x + opers[oper].x][pos.y + opers[oper].y];
  dfs_ac_1(pos + opers[oper], oper);
}

int main() {
  int temp;
  int idx = 0;
  cin >> R >> C >> T;
  for(int i = 0 ; i < R ; ++i){
	for(int j = 0 ; j < C ; ++j){
	  cin >> temp;
	  if(temp == -1)
		pos_ac.push_back({.x = i, .y = j});
	  //else if(temp > 0) 
	  //  dusts.push_back({.value = temp, .point = {.x = i, .y = j}});
	  map[i][j] = temp;
	}
  }
  for(int t = 0 ; t < T ; ++t){
	get_dust_spread();
	// print_map();
	dfs_ac_0(pos_ac[0], 0);
  dfs_ac_1(pos_ac[1], 1);
	// print_map();
  }
  int ans = 0;
  for(int i = 0; i < R ; ++i){
    for(int j =0 ;  j< C ; ++j){
      ans += map[i][j];
    }
  }
  cout << ans + 2;
  return 0;
}

