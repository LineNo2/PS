#include <bits/stdc++.h>
#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_ALPHA 27

using namespace std;

typedef struct Point{
  int x , y;
  Point operator + (Point &p){
	return {.x = x + p.x , .y = y + p.y};
  }
}Point;



int TC, H, W;

bool Key_arr[MAX_ALPHA] = {0,};

vector<Point> Door_arr[MAX_ALPHA];

char Map[MAX_HEIGHT][MAX_WIDTH];

bool is_visited[MAX_HEIGHT][MAX_WIDTH];

int main(){
  char temp;
  int ans = 0;
	Point opers[4] = {
  {.x = 1 , .y = 0},
  {.x = -1 , .y = 0},
  {.x = 0 , .y = 1},
  {.x = 0 , .y = -1}
};
  scanf("%d\n",&TC);
  for(int c = 0 ; c < TC ; ++c){
	scanf("%d %d\n", &H, &W);
	memset(Map,0,sizeof(Map));
	memset(is_visited, false, sizeof(is_visited));
	memset(Key_arr, false, sizeof(Key_arr));
	ans = 0;
	for(int i = 0 ; i < MAX_ALPHA ; ++i)
	  Door_arr[i].clear();
	queue<Point> Q;
	for(int i = 0 ; i < H ;++i){
	  for(int j = 0 ; j < W; ++j){
		temp = getchar();
		Map[i][j] = temp;
		if(i == 0 || j == 0 || i == H-1 || j == W-1) {
		  if(temp >= 'A' && 'Z' >= temp) Door_arr[temp-'A'].push_back({.x = i, .y = j});
		  else if(temp != '*') {
				Q.push({.x = i, .y = j});
				is_visited[i][j] = true;
			}
		}
	  }
	  getchar();
	}
	temp = getchar();
	if(temp != '0'){
	  while(temp != '\n'){
		int cur_alpha = temp - 'a';
		Key_arr[cur_alpha] = true;
		while(!Door_arr[cur_alpha].empty()){
		  Q.push(Door_arr[cur_alpha].back());
		  Door_arr[cur_alpha].pop_back();
		}
		temp = getchar();
	  }
	}
	while(!Q.empty()){
	  int cur_x = Q.front().x;
	  int cur_y = Q.front().y;
	  Q.pop();
		// cout << Map[cur_x][cur_y];
	  if(Map[cur_x][cur_y] != '.'){
		int cur_alpha = Map[cur_x][cur_y];
		if(cur_alpha >= 'a' && 'z' >= cur_alpha){
		  cur_alpha -= 'a';
			Key_arr[cur_alpha] = true;
		  while(!Door_arr[cur_alpha].empty()){
			Q.push(Door_arr[cur_alpha].back());
			Door_arr[cur_alpha].pop_back();
		  }
		}
		else if(cur_alpha == '$') ++ans;
		else{
			if(!Key_arr[cur_alpha - 'A']) {
		    Door_arr[cur_alpha - 'A'].push_back({.x = cur_x, .y = cur_y});
		    continue;
			}
		}
	  }
	  for(int i = 0 ; i < 4 ; ++i){
		int next_x = cur_x + opers[i].x;
		int next_y = cur_y + opers[i].y;
		if(next_x < 0 || next_y < 0 || next_x >= H || next_y >= W) continue;
		if(is_visited[next_x][next_y]) continue;
		is_visited[next_x][next_y] = true;
		if(Map[next_x][next_y] == '*') continue;
		Q.push({.x = next_x , .y = next_y});
	  }
	}
	printf("%d\n",ans);
  }
  return 0;
}
