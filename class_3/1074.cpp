#include <stdio.h>
#include <math.h>


int arr[32768][32768];

void insertZ(int n, int start, int x, int y ){
  if(n == 1){
	arr[x][y] = start;
	arr[x][y+1] = start + 1;
	arr[x+1][y] = start + 2;
	arr[x+1][y+1] = start + 3;
  }else{
	insertZ(n-1, 0 , x, y);
	insertZ(n-1, start/4, x+pow(n-1,2), y);
	insertZ(n-1, start/2, x, y+pow(n-1,2));
	insertZ(n-1, start*3/4, x+pow(n-1,2), y+pow(n-1,2));
  }
  return;
}


int main(){
  int n, r, c;
  scanf("%d %d %d",&n,&r,&c);
  insertZ(n, pow(2, pow(n,2)) ,0 , 0);
  for(int i = 0 ; i < pow(2,n) ; ++i){
	for(int j = 0 ; j < pow(2,n) ; ++j){
	  printf("%d ",arr[i][j]);
	}
	printf("\n");
  }
  return 0;
}
  
