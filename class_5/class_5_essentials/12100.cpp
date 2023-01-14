#include <bits/stdc++.h>
#define MAX_N 20

using namespace std;

int N;

int ans;

int Board[MAX_N][MAX_N];

typedef struct Oper{
  int i_st, j_st;
  int i_add, j_add;
}Oper;

const int oper[4] = { 1, 2, 3, 4};
// for문의 시작 방향을 얘로 조정하자.

void print_board(int Board[][MAX_N]){
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			printf("%d ",Board[i][j]);
		}
		printf("\n");
	}
}
void Copy_Arr(int dest[][MAX_N], int src[][MAX_N]){// C++ 에는 Copy 함수가 있다..
  for(int i = 0; i < N ; ++i)
	for(int j = 0 ; j < N ; ++j)
	  dest[i][j] = src[i][j];
}

int search_shift_index(int oper, int col, int Board__[][MAX_N]); 
// col과 숫자, oper를 주면 해당 oper을 했을때 가야하는 인덱스를 반환해줌.

int (*Shift_Board(int oper, int Board__[][MAX_N]))[MAX_N]{
  bool Block_State[MAX_N][MAX_N] = {false,};
	int k, flag;
  switch(oper){
	case 0: //up
	  for(int i = 1 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
		  if(Board__[i][j] == 0) continue;
			flag = 0;
				for(k = i-1 ; k >= 0 ; --k){
					if(Board__[k][j] != 0) {
					if(Board__[k][j] == Board__[i][j]
					&& !Block_State[k][j] && !Block_State[i][j]) flag = 2;
					break;
				}
				flag = 1;
			}
		  if(!flag) continue;
			if(flag == 2){
				Block_State[k][j] = true;
				Board__[i][j] = 0;
				Board__[k][j] *= 2;
			}
			else{
				Board__[k+1][j] = Board__[i][j];
				Board__[i][j] = 0;
			}
		}
	  }
	  break;
	case 1: // down
	  for(int i = N-2 ; i >= 0 ; --i){
		for(int j = 0 ; j < N ; ++j){
		  if(Board__[i][j] == 0) continue;
			flag = 0;
			for(k = i+1 ; k < N ; ++k){
					if(Board__[k][j] != 0) {
					if(Board__[k][j] == Board__[i][j]
					&& !Block_State[k][j] && !Block_State[i][j]) flag = 2;
					break;
				}
				flag = 1;
			}
		  if(!flag) continue;
			if(flag == 2){
				Block_State[k][j] = true;
				Board__[i][j] = 0;
				Board__[k][j] *= 2;
			}
			else{
				Board__[k-1][j] = Board__[i][j];
				Board__[i][j] = 0;
			}
		}
	  }
		break;
	case 2://left
	  for(int i = 0 ; i < N ; ++i){
		for(int j = 1 ; j < N ; ++j){
		  if(Board__[i][j] == 0) continue;
			flag = 0;
			for(k = j-1 ; k >= 0 ; --k){
				if(Board__[i][k] != 0) {
					if(Board__[i][k] == Board__[i][j]
					&& !Block_State[i][k] && !Block_State[i][j]) flag = 2;
					break;
				}
				flag = 1;
			}
		  if(!flag) continue;
			if(flag == 2){
				Block_State[i][k] = true;
				Board__[i][j] = 0;
				Board__[i][k] *= 2;
			}
			else{
				Board__[i][k+1] = Board__[i][j];
				Board__[i][j] = 0;
			}
		}
	  }
		break;
	case 3:
	  for(int i = 0 ; i < N ; ++i){
		for(int j = N-2 ; j >= 0 ; --j){
		  if(Board__[i][j] == 0) continue;
			flag = 0;
			for(k = j+1 ; k < N ; ++k){
				if(Board__[i][k] != 0) {
					if(Board__[i][k] == Board__[i][j]
					&& !Block_State[i][k] && !Block_State[i][j]) flag = 2;
					break;
				}
				flag = 1;
			}
		  if(!flag) continue;
			if(flag == 2){
				Block_State[i][k] = true;
				Board__[i][j] = 0;
				Board__[i][k] *= 2;
			}
			else{
				Board__[i][k-1] = Board__[i][j];
				Board__[i][j] = 0;
			}
		}
	}
  break;
	}
  return Board__;
}

void DFS(int cnt, int Board_[][MAX_N]){
	// printf("cnt -> %d\n",cnt);
	// print_board(Board);
	if(cnt == 5) {
		for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < N ; ++j)
		ans = max(ans, Board[i][j]);
		return;
	}
  int Original_Board[MAX_N][MAX_N];
  Copy_Arr(Original_Board, Board_);
  
  for(int i = 0 ; i < 4 ; ++i){
		// printf("%d : ",i);
	DFS(cnt + 1, Shift_Board(i,Board)); 
	Copy_Arr(Board_, Original_Board);
  }

}
int main(){
  cin >> N;
  for(int i = 0 ; i < N ;++i)
	for(int j = 0 ; j < N ; ++j)
	  cin >> Board[i][j];
  DFS(0, Board);
	cout << ans;
  return 0;
}
