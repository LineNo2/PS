#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[26][26];
int is_visited[26][26];
int aparts[625];

int dfs(int x, int y ){
  if(is_visited[x][y] != 0 ) return 0 ;
  if(x < 0 || y < 0 || x >= n || y >= n) return 0;
  if(map[x][y] == 1){
	is_visited[x][y] = 1;
	return  1 + 
	  dfs(x-1, y) +
	  dfs(x+1, y) +
	  dfs(x, y-1) +
	  dfs(x, y+1);
  }
  else
	return 0;
}

int main(){
  int level = 0;
  char temp;
  scanf("%d\n",&n);
  for(int i = 0 ; i < n; ++i){
	for(int j = 0 ; j < n ; ++j){
	  temp = getchar(); 
	  map[i][j] = temp - '0';
	}
	getchar();
  }

  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  if(map[i][j] == 0 || is_visited[i][j] != 0) continue;
	  aparts[level++] = dfs(i,j);
	}
  }
  sort(aparts, aparts + level);
  printf("%d\n",level);
  for(int i = 0 ; i < level ; ++i)
	printf("%d\n",aparts[i]);
  return 0;
}
