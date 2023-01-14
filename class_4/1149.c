#include <stdio.h>

int min(int a, int b){
  return a > b  ? b : a;
}

int main(){
  int n;
  int value[1000][3];
  int d[1000][3];
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < 3; ++j){
	  scanf("%d",&value[i][j]);
	}
  }
  d[0][0] = value[0][0];
  d[0][1] = value[0][1];
  d[0][2] = value[0][2];
  for(int i = 1 ; i < n; ++i){
	for(int j = 0 ; j < 3; ++j){
	  d[i][j] = min(d[i-1][(j+1)%3], d[i-1][(j+2)%3]) + value[i][j]; 
	}
  }
  printf("%d", min(min(d[n-1][0], d[n-1][1]),d[n-1][2]));
  return 0;
}

