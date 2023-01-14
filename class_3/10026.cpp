#include <iostream>
#include <string.h>

int picture_normal[100][100];
bool picture_colorblind[100][100];
bool is_visted[100][100];
int n;

void dfs(int x, int y, int color){
  int temp_;
  if(x < 0 || y < 0 || x >= n || y >= n) return;
  if(picture_normal[x][y] != color) return;
  if(is_visted[x][y] == 1) return;
  is_visted[x][y] = 1;
  dfs(x-1,y,color);
  dfs(x+1,y,color);
  dfs(x,y-1,color);
  dfs(x,y+1,color);
  return;
}

void dfs(int x, int y, bool color){
  int temp_;
  if(x < 0 || y < 0 || x >= n || y >= n) return;
  if(picture_colorblind[x][y] != color) return;
  if(is_visted[x][y] == 1) return;
  is_visted[x][y] = 1;
  dfs(x-1,y,color);
  dfs(x+1,y,color);
  dfs(x,y-1,color);
  dfs(x,y+1,color);
  return;
}

void print_is_visited(){
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			printf("%d ", is_visted[i][j]);
		}
		printf("\n");
	}
}

int main(){
  char temp;
  scanf("%d\n",&n);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0; j < n ; ++j){
	  temp = getchar();
	  if(temp == 'B'){
		picture_colorblind[i][j] = true;
		picture_normal[i][j] = 2;
	  }
	  else if(temp == 'R'){
		picture_colorblind[i][j] = false;
		picture_normal[i][j] = 1;
	  }
	  else{
		picture_colorblind[i][j] = false;
		picture_normal[i][j] = 0;
	  }
	}
	getchar();
  }
  int count = 0;
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  if(is_visted[i][j] == false){
		dfs(i, j, picture_normal[i][j]);
		++count;
	//	print_is_visited();
	  }
	}
  }
  memset(is_visted, 0, sizeof(is_visted));
  printf("%d ",count);
  count = 0;
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  if(is_visted[i][j] == false){
		dfs(i, j, picture_colorblind[i][j]);
		++count;
	//	print_is_visited();
	  }
	}
  }
  printf("%d", count);
  return 0;
}

