#include <iostream>
#define ROW_MAX 8
#define COL_MAX 8
#define MOD 1000000007

using namespace std;

typedef struct Matrix{
  int matrix[ROW_MAX][COL_MAX] ={
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,0,1,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,0,1,0,1,1,0},
	{0,0,1,1,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0} };
  int size = 8;  
  struct Matrix operator * (struct Matrix& p){
	struct Matrix temp_matrix;
  temp_matrix.size = size;
	int temp;
	for(int k = 0 ; k < size ; ++k){
	  for(int i = 0 ; i < size ; ++i){
		temp = 0;
		for(int j = 0 ; j < size ; ++j){
		  temp = ( temp +  ((long long)p.matrix[j][i] * (long long)matrix[k][j]) % MOD ) %  MOD;
		} 
		temp_matrix.matrix[k][i] = temp % MOD;
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
  N = 8;
  Matrix temp;
  cin >> K;
  M.size = N;
  temp = matrix_pow(M,K);
  cout << temp.matrix[0][0];
  return 0;
}
