#include <bits/stdc++.h>

using namespace std;

int A_num[9],A_idx[9];
int R[9];
int C[9];

int sudoku[9][9];

int max_bit;

void print_sudoku(){
	for(int i = 0 ; i < 9 ; ++i){
		for(int j = 0; j < 9 ; ++j){
		  printf("%d",sudoku[i][j]);
		}
		printf("\n");
	}
}

int find_min(int bit){
  for(int i = 0 ; i < 9 ; ++i){
	if(bit & (1 << i)) continue;
	return i;
  }
  return -1;
}

void DFS(int idx){
	if(idx == 81){
			print_sudoku();
		  exit(0);
	}
	int area = (idx/27)*3 + (idx%9)/3;
	int row = (idx/9)%3;
	int col = idx%3;
	if(A_idx[area] &(1 << (row*3 + col))) {
		DFS(idx+1);
		return;
	}
	A_idx[area] |= (1 << (row*3 + col));
  int *num_state = &A_num[area];
  for(int i = 0 ; i < 9 ; ++i){
	int cur_num = 1 << i;
	if(*num_state & cur_num) continue;
	int *cur_row = &R[(area/3) * 3 + row];
	if(*cur_row & cur_num) continue;
	int *cur_col = &C[(area%3) * 3 + col];
	if(*cur_col & cur_num) continue;
	*num_state |= cur_num;
	*cur_row |= cur_num;
	*cur_col |= cur_num;
	sudoku[(area/3) * 3 + row][(area%3) * 3 + col] = i + 1;
	DFS(idx+1);
	sudoku[(area/3) * 3 + row][(area%3) * 3 + col] = 0;
	cur_num = ~cur_num;
	*num_state &= cur_num;
	*cur_row &= cur_num;
	*cur_col &= cur_num;
  }
	A_idx[area] &= ~(1 << (row*3 + col));
}

int main(){
  int temp;
  max_bit = (1 << 9) - 1;
  for(int i = 0 ; i < 9 ; ++i){
	for(int j = 0 ; j < 9 ; ++j){
	  temp = getchar();
	  temp = temp - '0' - 1;
	  if(temp == -1) continue;
	  R[i] |= (1 << temp);
	  C[j] |= (1 << temp);
	  A_idx[i/3 * 3 + j/3] |= (1 << (i % 3 * 3 + j % 3));
		A_num[i/3 * 3 + j/3] |= (1 << temp);
		sudoku[i][j] = temp + 1;
	}
	getchar();
  }
  DFS(0);
  return 0;
}
