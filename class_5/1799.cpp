#include <bits/stdc++.h>
#define N_MAX 10

using namespace std;

int N;

int ans = 0;

void copy_bool_arr(bool target[][N_MAX], bool original[][N_MAX]){
  for(int i = 0 ; i < N_MAX; ++i)
	for(int j = 0 ; j < N_MAX; ++j)
	  target[i][j] = original[i][j];
  return;
}

bool (*check_board(int x, int y, bool Board__[][N_MAX]))[N_MAX]{
  for(int i = -N ; i <= N ; ++i){
	if(0 <=  x-i  && x-i < N
		&& 0 <= y-i && y-i < N)
	  Board__[x-i][y-i] = false;
  if(0 <=  x+i  && x+i < N
		&& 0 <= y-i && y-i < N)
    Board__[x+i][y-i] = false;
  }
  return Board__;
};

void DFS(bool flag, int former_i, int former_j, int cnt, bool Board_[][N_MAX]){
  bool next_board[N_MAX][N_MAX];
  for(int i = 0 ; i < N ; ++i){
	for(int j = i % 2 == 0 ? flag : !flag ; j < N; j+=2){
    if( i <= former_i && j <= former_j ) continue;
	  if(!Board_[i][j]) continue;
	  copy_bool_arr(next_board,Board_);
	  copy_bool_arr(next_board, check_board(i,j,next_board));
	  DFS(flag, i, j, cnt + 1, next_board);
	}
  }
  ans = max(cnt, ans);
}

// 1 -> placeable, 0 -> not placeable
int main(){
  // time_t start,end;
  // double result;
  int ans_temp;
  bool Board[N_MAX][N_MAX] = {0,};
  cin >> N;
  for(int i = 0 ; i < N ; ++i)
	for(int j = 0 ; j < N ; ++j)
	  cin >> Board[i][j];
  // start = time(NULL);
  DFS(false,-1,-1,0,Board);
  ans_temp = ans;
  ans = 0;
  DFS(true,-1,-1,0,Board);
  ans += ans_temp;
  // end = time(NULL);
  // result = (double)(end - start);
  // cout << result <<endl;
  cout << ans;
  return 0;
}

