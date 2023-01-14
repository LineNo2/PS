#include <iostream>
#define ROW_MAX 6
#define COL_MAX 6

using namespace std;

typedef struct Matrix{
  int matrix[ROW_MAX][COL_MAX];
  int size;
  
  struct Matrix operator * (struct Matrix& p){
	struct Matrix temp_matrix;
  temp_matrix.size = size;
	int temp;
	for(int k = 0 ; k < size ; ++k){
	  for(int i = 0 ; i < size ; ++i){
		temp = 0;
		for(int j = 0 ; j < size ; ++j){
		  temp += p.matrix[j][i] * matrix[k][j] % 1000;
		}
		temp_matrix.matrix[k][i] = temp % 1000;
	  }
	}
	return temp_matrix;
  }
}Matrix;

Matrix M;
int N;
long long K;

Matrix matrix_pow(Matrix m, long long k){
  Matrix temp;
  temp.size = m.size;
  if(k == 1) return m;
  if(k % 2 == 0){
	temp = matrix_pow(m, k/2);
	return temp * temp;
  }
  else {
	temp = matrix_pow(m, (k-1)/2);
	return temp * temp * m;
  }
}

int main() {
  Matrix temp;
  cin >> N >> K;
  for(int i = 0 ; i < N ; ++i){
  for(int j = 0 ; j < N ; ++j){
  cin >> M.matrix[i][j];
  M.matrix[i][j] %= 1000;
  }
  }
  M.size = N;
  temp = matrix_pow(M,K);
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < N ; ++j){
	  printf("%d ",temp.matrix[i][j]);
	}
	printf("\n");
  }

  return 0;
}
