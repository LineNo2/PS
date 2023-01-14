#include <bits/stdc++.h>
#define N_MAX 500

using namespace std;

typedef struct Matrix{
  int row;
  int col;
}Matrix;

int N;

Matrix M[N_MAX];
int DP[N_MAX][N_MAX];
int main(){
  int st, ed;
  cin >> N;
  for(int i = 0 ; i < N ; ++i){
	cin >> M[i].row >> M[i].col;
	if(i > 0) DP[i-1][i] = M[i-1].row * M[i].row * M[i].col;
  }
  int min_value;
  for(int i = 2 ; i < N ; ++i){
	for(int j = 0 ; j < N-i ; ++j){
	  min_value = 2147483647;
	  for(int k = 1 ; k <= i ; ++k){
		int cur_value = DP[j][j+i-k] + DP[j+(i-k)+1][j+i] + M[j].row * M[j+(i-k)+1].row * M[j+i].col;
		min_value = min(min_value, cur_value);
		//printf("DP[%d][%d] + DP[%d][%d] + %d = %d\n", j,j+i-k,j+(i-k)+1,j+i,M[j].row * M[j+(i-k)+1].row * M[j+i].col,cur_value);
	  }
	  DP[j][i+j] = min_value;
	  //printf("D[%d][%d] = %d\n",j, i+j, min_value);
	}
  }
  cout << DP[0][N-1];
  return 0;
}




