#include <iostream>
#include <queue>
#include <vector>
#define MAX_ROW 8
#define MAX_COL 8

using namespace std;

typedef struct Point{
	int x;
	int y;
}Point;

Point oper[4] = { 
  {.x = -1 , .y = 0},
  {.x = 1 , .y = 0},
  {.x = 0 , .y = -1},
  {.x = 0 , .y = 1},
};

int max(int a, int b){
  return a > b ? a : b;
}

int N, M;
int map[MAX_ROW][MAX_COL];
vector<Point> virus;
vector<Point> hollow;

int bfs(int *arr_points_idx){
  queue<Point> Q;
  bool is_visited[MAX_ROW][MAX_COL];
  int new_map[MAX_ROW][MAX_COL];
  int cur_x, cur_y;
  int next_x, next_y;
  for(int i = 0  ; i < N ; ++i)
	for(int j = 0 ; j < M ; ++j){
	  new_map[i][j] = map[i][j];
	  is_visited[i][j] = false;
	}
  for(int i = 0 ; i < 3 ; ++i){
	int points_idx = arr_points_idx[i];
	new_map[hollow[points_idx].x][hollow[points_idx].y] = 1;
  }
  for(int i = 0 ; i < virus.size() ; ++i){
	Q.push(virus[i]);
	is_visited[virus[i].x][virus[i].y] = true;
  }
  while(!Q.empty()){
	cur_x = Q.front().x;
	cur_y = Q.front().y;
	Q.pop();
	for(int i = 0 ; i < 4 ; ++i){
	  next_x = cur_x + oper[i].x;
	  next_y = cur_y + oper[i].y;
	  if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
	  if(is_visited[next_x][next_y]) continue;
	  is_visited[next_x][next_y] = true;
	  if(new_map[next_x][next_y] != 0) continue;
	  new_map[next_x][next_y] = 2;
	  Q.push({.x = next_x, .y = next_y});
	}
  }
  int count = 0;
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < M ; ++j){
	  if(new_map[i][j] == 0) ++count;
	}
  }
  return count;
}

int main(){
  int temp;
  int arr_points[3];
  cin >> N >> M;
  for(int i = 0 ; i < N ; ++i)
	for(int j = 0 ; j < M ; ++j){
	  cin >> temp;
	  if(temp == 2) virus.push_back({.x = i , .y = j});
	  else if(temp == 0) hollow.push_back({.x = i , .y = j});
	  map[i][j] = temp;
	}
  int size = hollow.size();
  int ans = 0;
  for(int i = 0 ; i < size ; ++i){
	arr_points[0] = i;
	for(int j = i + 1 ; j < size ; ++j){
	  arr_points[1] = j;
	  for(int k =  j + 1 ; k < size ; ++k){
		arr_points[2] = k;
		ans = max(ans,bfs(arr_points));
	  }
	}
  }
  cout << ans;
  return 0;
}


