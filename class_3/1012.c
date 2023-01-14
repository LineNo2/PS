#include <stdio.h>
#include <memory.h>

int map[51][51];
int is_visited[51][51];

int dfs(int x, int y){
  if(map[x][y] == 0 || is_visited[x][y]) return 0;
  is_visited[x][y] = 1;
  return dfs(x-1,y) + dfs(x,y-1) + dfs(x+1,y) + dfs(x,y+1) +1;
}

int main(){
  int test_cases;
  int n, m , vegetables;
  int temp_x, temp_y;
  int count = 0;
  scanf("%d",&test_cases);
  for(int t = 0 ; t < test_cases ; ++t){
	scanf("%d %d %d",&n, &m, &vegetables);
	memset(map, 0, sizeof(map));
	memset(is_visited, 0, sizeof(is_visited));
	count = 0;
	for(int i = 0 ; i < vegetables ; ++i){
	  scanf("%d %d",&temp_x, &temp_y);
	  map[temp_x][temp_y] = 1;
	}
	for(int x = 0 ; x < n ; ++x){
	  for(int y = 0 ; y < m ; ++y){
		if(dfs(x,y) > 0)
		  count++;
	  }
	}
	printf("%d\n",count);
  }
  return 0;
}


	  


