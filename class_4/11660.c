#include <stdio.h>
#define MAX 1025

int arr[MAX][MAX];
int d[MAX][MAX];

int main(){
  int n, m;
  
  scanf("%d %d",&n, &m);
  for(int i = 1 ; i <= n ; ++i){
	for(int j = 1 ; j <= n ; ++j){
	  scanf("%d",&arr[i][j]);
	  if( j == 1 ) d[i][j] = arr[i][j];
	  else d[i][j] = arr[i][j] + d[i][j-1];
	}
  }
	int x1, x2, y1, y2;
	for(int i = 0 ; i< m ;++i){
		scanf("%d %d %d %d",&x1, &y1 ,&x2, &y2);
		int temp = 0;
		for(int j = x1 ; j <= x2 ; ++j){
			temp += d[j][y2] - d[j][y1] + arr[j][y1];
		}
		printf("%d\n",temp);
	}
  return 0;
}

