#include <stdio.h>

int map[1010][1010] = {0,};
int is_visited[1010] = {0,};
int n , m;

void dfs(int st){
	is_visited[st] = 1;
  for(int i = 1 ; i <= n ; ++i){
	if(is_visited[i] == 0 && map[st][i] == 1){
	  dfs(i);
	}
  }
}

int main()
{
  int a,b;
  int count = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0 ; i < m; ++i){
	scanf("%d %d",&a, &b);
	map[a][b] = 1;
	map[b][a] = 1;
  }
  for(int i = 1 ; i <= n ; ++i){
		if(is_visited[i] == 0){
			dfs(i);
			++count;
		}
	}
  printf("%d",count);
  return 0;
}
