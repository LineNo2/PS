#include <bits/stdc++.h>
#define N_MAX 3001

using namespace std;

typedef struct Point{
  int x, y;
}Point;

int N, M;

long long num_of_M[N_MAX][N_MAX];
long long num_of_S[N_MAX][N_MAX];
long long num_of_E[N_MAX][N_MAX];

vector<Point> E_pos;
vector<Point> S_pos;

int Arr[N_MAX][N_MAX];

int main(){
  long long ans = 0;
  char temp;
  scanf("%d %d\n",&N, &M);
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < M ; ++j){
	  temp = getchar();
	  switch(temp){
		case 'E':
		  E_pos.push_back({.x = i, .y = j});
		  break;
		case 'S':
		  Arr[i][j] = 1;
		  break;
		case 'M':
		  Arr[i][j] = 2;
		  break;
	  }
	}
	getchar();
  }
  for(int i = N-1; i >= 0 ; --i){
	int cur_M = 0;
	int cur_S = 0;
	for(int j = M-1; j >= 0 ; --j){
	  if(Arr[i][j] == 2)
		++cur_M;	  
		num_of_M[i][j] = cur_M + num_of_M[i+1][j]; 
	  if(Arr[i][j] == 1)
		cur_S += num_of_M[i][j] % 1000000007;
	  num_of_S[i][j] = cur_S +num_of_S[i+1][j];
	}
  }
  for(int i = 0 ; i < E_pos.size();  ++i){
	int e_x = E_pos[i].x;
	int e_y = E_pos[i].y;
	ans += num_of_S[e_x][e_y] % 1000000007;
  }
  printf("%d",ans % 1000000007);
  return 0;
}

