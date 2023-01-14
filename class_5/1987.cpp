#include <bits/stdc++.h>
#define MAX_N 20

using namespace std;

int R, C;

int oper_x[4] = { 1, -1, 0, 0};
int oper_y[4] = { 0, 0, 1, -1};

int Board[MAX_N][MAX_N];

int ans = 0;

void DFS(int x, int y, int cnt, int bitmask){
  ans = max(cnt, ans);
  for(int i = 0 ; i < 4; ++i){
	int next_x = x + oper_x[i];
	int next_y = y + oper_y[i];
	if( 0 > next_x || next_x >= R ||
		0 > next_y || next_y >= C) continue;
	if(bitmask & (1 << Board[next_x][next_y])) continue;
	int next_bit = bitmask | ( 1 << Board[next_x][next_y] );
	DFS(next_x, next_y, cnt + 1, next_bit);
  }
}

int main(){
char temp;
  cin >> R >> C;
  for(int i = 0 ; i < R ; ++i)
	for(int j = 0 ; j < C ; ++j){
	  cin >> temp;
	  Board[i][j] = temp - 'A';
	  }
  DFS(0,0,1,(1 << Board[0][0]));
  cout << ans;
  return 0;
}
