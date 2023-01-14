#include <bits/stdc++.h>
#define N_MAX 10

using namespace std;

FILE *fp;

bool Map[N_MAX][N_MAX];

bool Map_original[N_MAX][N_MAX];

void toggleSwitch(int x,int y,bool arr[][N_MAX]){
  if(x > 0) arr[x-1][y] = !arr[x-1][y];
  if(y > 0) arr[x][y-1] = !arr[x][y-1];
  arr[x][y] = !arr[x][y];
  if(x < 9) arr[x+1][y] = !arr[x+1][y];
  if(y < 9) arr[x][y+1] = !arr[x][y+1];
}

int answer = 101;

void DFS(int y, int cnt){
  if(y == 10){
  int ans = cnt;
  for(int i = 0 ; i < 10; ++i)
	for(int j = 0 ; j < 10 ; ++j)
	  Map[i][j] = Map_original[i][j];
  for(int i = 1 ; i < 10; ++i){
	for(int j = 0 ; j < 10 ; ++j){
	  if(!Map[i-1][j]) continue;
	  ++ans;
	  toggleSwitch(i,j,Map);
	}
  }
  for(int i = 0 ; i < 10 ; ++i)
	if(Map[9][i])  return;
  answer = min(answer, ans);
  return;
  }
  toggleSwitch(0,y,Map_original);
  DFS(y+1, cnt + 1);
  toggleSwitch(0,y,Map_original);
  DFS(y+1, cnt);
}

int main(){
  char temp;
  for(int i = 0 ; i < N_MAX ; ++i){
	for(int j = 0 ; j < N_MAX ; ++j){
	  temp = getchar();
	  if(temp == 'O')  Map[i][j] = true;
	  Map_original[i][j] = Map[i][j];
	}
	getchar();
  }
  DFS(0,0);
  if(answer == 101) cout << -1;
  else cout << answer;
  return 0;
}
