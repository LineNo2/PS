#include <bits/stdc++.h>
#define MAX_NODE 16
#define INF 987654321

using namespace std;

int N;

int ans = INF;

int W[MAX_NODE][MAX_NODE];

int DP[MAX_NODE][1 << MAX_NODE];

int N_to_bit;

int dfs(int node, int is_visited){ //dfs는 지금부터 0 까지 가는데 필요한 비용을 리턴해준다.
  if(is_visited == N_to_bit){
    if(W[node][0] == 0)return INF;
    return W[node][0];
  }
  if(DP[node][is_visited] != -1) return DP[node][is_visited];
  DP[node][is_visited] = INF;

  for(int i = 0 ; i < N ; ++i){
	if(W[node][i] == 0) continue;
	if(is_visited & ( 1 << i )) continue;
	// printf("%d selected : %d\n",i,W[node][i]);
    DP[node][is_visited] = min(DP[node][is_visited],
    dfs(i, is_visited | ( 1 << i ) ) + W[node][i]  
    );
  }
  return DP[node][is_visited];
}

int main(){
  cin >> N;
  memset(DP, -1, sizeof(DP));
  for(int i = 0 ; i < N ; ++i)
	for(int j = 0 ; j < N ;++j)
	  cin >> W[i][j];
  N_to_bit = (1 << N) - 1;
  
  cout << dfs(0,1);
  return 0;
}
