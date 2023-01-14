#include <bits/stdc++.h>
#define N_MAX 1000

using namespace std;

int N, M;

bool Map[N_MAX][N_MAX];

bool is_visited[N_MAX][N_MAX];

int Root[N_MAX * N_MAX];

int Count[N_MAX * N_MAX];

int find(int n){
  if(n == Root[n]) return n;
  return Root[n] = find(Root[n]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  if(Count[a] < Count[b]) swap(a,b);
  Root[b] = a;
  Count[a] += Count[b];
  Count[b] = 0;
}

int oper[4][2] = {
  {0,1},
  {0,-1},
  {1,0},
  {-1,0} };

void DFS(int x, int y){
  for(int i = 0 ; i < 4 ; ++i){
	int next_x = x + oper[i][0];
	int next_y = y + oper[i][1];
	if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
	if(Map[next_x][next_y]) continue;
	 merge(next_x*M+next_y, x*M+y);
    if(is_visited[next_x][next_y]) continue;
	is_visited[next_x][next_y] = true;
	DFS(next_x, next_y);
  }
}

int getAreaSum(int x, int y){
  int ans = 1;
  vector<int> check;
  for(int i = 0 ; i < 4 ; ++i){
	bool flag = false;
	int next_x = x + oper[i][0];
	int next_y = y + oper[i][1];
	if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
	int set = find(next_x*M+next_y);
	for(int j = 0 ; j < check.size(); ++j){
	  if(check[j] == set) flag = true;
	}
	if(flag) continue;
	ans += Count[set];
	check.push_back(set);
  }
  return ans%10;
}

int main(){
  char temp;
  scanf("%d %d\n",&N,&M);
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < M ; ++j){
	  temp = getchar();
	  Root[i*M+j] = i*M+j;
	  if(temp == '1')
		Map[i][j] = true;
	  else  
		Count[i*M+j] = 1;
	}
	getchar();
  }
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < M ; ++j){
	  if(Map[i][j]) continue;
	  if(is_visited[i][j]) continue;
	  is_visited[i][j] = true;
	  DFS(i,j);
	}
  }
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < M ; ++j){
	  if(Map[i][j])
	    printf("%d",getAreaSum(i,j));
	  else
		printf("0");
	}
	puts("");
  }
  return 0;
}
