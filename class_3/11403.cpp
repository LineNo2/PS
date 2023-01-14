#include <iostream>
#include <string.h>

int G[100][100];
int n;

int main(){
  int temp;
  scanf("%d",&n);

  memset(G, 1, sizeof(G));
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  scanf("%d",&temp);
	  if(temp == 1){
		G[i][j] = 1;
	  }
	}
  }
  for(int k = 0 ; k < n ; ++k){
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
		if(G[i][k] == 1 && G[k][j] == 1){
		  G[i][j] = 1;
		}
	  }
	}
  }
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0; j < n ; ++j){
	  printf("%d ",G[i][j] == 1 ? 1 : 0);
	}
	printf("\n");
  }
  return 0;
}
