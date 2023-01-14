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

void DFS(int area, int state){
  if(state == max_bit){
	if(area == 8) {
		print_sudoku();
		exit(0);
	}
	area += 1;
	DFS(area,A_idx[area]);
	return;
  }
  int elem = find_min(state); // min idx
  int *num_state = &A_num[area];
  for(int i = 0 ; i < 9 ; ++i){
	int cur_num = 1 << i;
	if(*num_state & cur_num) continue;
	int *cur_row = &R[(area/3) * 3 + elem/3];
	if(*cur_row & cur_num) continue;
	int *cur_col = &C[area%3 * 3 + elem%3];
	if(*cur_col & cur_num) continue;
	*num_state |= cur_num;
	*cur_row |= cur_num;
	*cur_col |= cur_num;
	sudoku[(area/3) * 3 + elem/3][area%3 * 3 + elem%3] = i + 1;
	DFS(area, (state|(1<<elem)) );
	sudoku[(area/3) * 3 + elem/3][area%3 * 3 + elem%3] = 0;
	cur_num = ~cur_num;
	*num_state &= cur_num;
	*cur_row &= cur_num;
	*cur_col &= cur_num;
  }
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
  DFS(0, A_idx[0]);
  return 0;
}
