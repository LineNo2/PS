#include <iostream>
#include <algorithm>
#define MAX 500

using namespace std;

int Triangle[MAX][MAX];
int D[MAX][MAX];

int max(int a, int b){
  return a > b ? a : b;
}

int main(){
  int n;
  int temp;
  cin >> n;
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j <= i ; ++j){
	  cin >> Triangle[i][j];
	}
  }
  D[0][0] = Triangle[0][0];
  D[1][0] = D[0][0] + Triangle[1][0];
  D[1][1] = D[0][0] + Triangle[1][1];
  for(int i = 2 ; i < n ; ++i){
    D[i][0] = D[i-1][0] + Triangle[i][0];
    for(int j = 1 ; j <= i ; ++j){
      D[i][j] = max(D[i-1][j-1],D[i-1][j]) + Triangle[i][j];
    }
  }
  temp = 0;
  for(int i = 0 ; i < n; ++i){
    if(temp < D[n-1][i])
    temp = D[n-1][i];
  }
  printf("%d",temp);
  return 0;

}
