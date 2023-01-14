#include <iostream>
#include <string.h>
#include <math.h>
#define MAX 3074

bool pic[7000][7000] = {false,};

void star_print(int x, int y, int k){
  if(k != 1){
	star_print(x,y,k/2);
	star_print(x + 3*k/2, y - 3*k/2, k/2);
	star_print(x + 3*k/2, y + 3*k/2 , k/2);
  return;
  }
  pic[x][y] = true;
  pic[x+1][y+1] = true;
  pic[x+1][y-1] = true;
  for(int i = 0 ;i<=2;++i){
	pic[x+2][y+i] = true;
	pic[x+2][y-i] = true;
  }
  return;
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i <n*2 ; ++i){
    for(int j = 0 ; j < n*2 ; ++j)
    pic[i][j] = false;
  }
	star_print(0,n,n/3);

  for(int i = 0; i < n ; ++i){
	for(int j = 1 ; j < 2*n ; ++j){
	  printf("%c",pic[i][j] ? '*' : ' ');
	}
  printf("\n");
  }
  return 0;
}




