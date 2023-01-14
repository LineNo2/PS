#include <bits/stdc++.h>
#include <string.h>
#define INF 987654321
#define NODE_MAX 16
using namespace std;

int N;

int ans = INF;

int W[NODE_MAX][NODE_MAX];

int D[NODE_MAX][1 << NODE_MAX];

int lengthOfArr(int is_visited[]){
  int sum = 0;
  for(int i = 0; i < N; ++i)
	sum += is_visited[i] > 0 ? 1 : 0;
  return sum;
}
void printArr(int is_visited[]){
  for(int i = 0 ; i < N ; ++i)
  printf("%d ->", is_visited[i]);
  return;
}
void dfs(int node, int is_visited[], int val, int th){
  if(lengthOfArr(is_visited) == N && node == 0){
    printArr(is_visited);
    printf("%d\n",val);
    ans = min(val,ans);
	  return;
  }
  int ans = INF;
  for(int i = 0 ; i < N ; ++i){
	if(is_visited[i]) continue;
	if(W[node][i] == 0) continue;
	is_visited[i] = th ;
  dfs(i, is_visited, val + W[node][i],th + 1);
	is_visited[i] = 0;
  }
  return;
}

int main(){
  int is_visited[NODE_MAX];
  memset(is_visited, 0, sizeof(is_visited));
  cin >> N;
  for(int i = 0 ; i < N ; ++i)
	for(int j = 0 ; j < N ; ++j)
	  cin >> W[i][j];
    dfs(0,is_visited,0,0);
  cout << ans;
  return 0;
}
