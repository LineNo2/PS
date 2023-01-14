#include <bits/stdc++.h>
#define N_MAX 101
#define COST_SUM_MAX 10001

using namespace std;

int N, M;
int total_mem;
int total_cost;
int program_mem[N_MAX];
int program_cost[N_MAX];

int DP[N_MAX][COST_SUM_MAX];

int main(){
  int min_cost = 987654321;
  cin >> N >> M;
  for(int i = 1 ; i <= N ; ++i){
	cin >> program_mem[i];
	total_mem += program_mem[i];
  }
  for(int i = 1 ; i <= N ; ++i){
	cin >> program_cost[i];
	total_cost += program_cost[i];
  }
  //memset(DP, -1, sizeof(DP));
  for(int i = 1 ; i <= N ; ++i){
	for(int j = 0 ; j <= total_cost ; ++j){
	  if( j < program_cost[i]) DP[i][j] = DP[i-1][j];
	  else DP[i][j] = max(DP[i-1][j], DP[i-1][j - program_cost[i]] + program_mem[i]);
	  if(DP[i][j] >= M && min_cost > j) min_cost = j;
	}
  }
  cout << min_cost;
  return 0;
}
