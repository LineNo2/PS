#include <bits/stdc++.h>
#define N_MAX 1000

using namespace std;

int N, M;

int Map[N_MAX * N_MAX];

int is_visited[N_MAX * N_MAX];

int DFS(int cur, int ans){
  int next = Map[cur];
  //printf("DFS(%d,%d)\n",cur,ans);
  if(is_visited[next] == 0) { 
	is_visited[next] = ans; 
	return is_visited[next] = DFS(next, ans);
  }
  else return is_visited[next];;
  
}

int main(){
  char temp;
  scanf("%d %d\n",&N,&M);
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < M ; ++j){
	  temp = getchar();
	  switch(temp){
		case 'D':
		  Map[i*M+j] = (i+1)*M+j;
		  break;
		case 'L':
		  Map[i*M+j] = i*M+j-1;
		  break;
		case 'R':
		  Map[i*M+j] = i*M+j+1;
		  break;
		case 'U':
		  Map[i*M+j] = (i-1)*M+j;
		  break;
	  }
	}
	getchar();
  }
  int ans = 1;
  for(int i = 0 ; i < N * M  ; ++i){
	if(is_visited[i]) continue;
	if(ans != (is_visited[i] = DFS(i,ans))) continue;
	++ans;
  }
  printf("%d",ans-1);
  return 0;
}
