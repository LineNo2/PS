#include <iostream>
#define VERTEX 101
#define INF 987654321

using namespace std;

int n, m;

int min(int a, int b){
  return a > b ? b : a;
}


int edge[VERTEX][VERTEX];
int d[VERTEX][VERTEX];

int main(){
  int from, to, dist;
  cin >> n >> m;
  for(int i = 1 ; i <= n ; ++i)
	for(int j = 1 ; j <= n ; ++j)
	  d[i][j] = INF;
  for(int i = 0 ; i< m ; ++i){
	cin >> from >> to >> dist;
	if(edge[from][to] == 0)
	  edge[from][to] = dist;
	else
	  edge[from][to] = min(dist, edge[from][to]);
	d[from][to] = edge[from][to];
  }
  for(int i = 1 ; i <= n ; ++i)
	d[i][i] = 0;
  for(int k = 1 ; k <= n ; ++k){
  for(int i = 1 ; i <= n ; ++i){
	for(int j = 1 ; j <= n ; ++j){
	  d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
	}
  }
  }
  for(int i = 1 ; i <= n ; ++i){
	for(int j = 1; j <= n ; ++j){
	  printf("%d ",d[i][j] == INF ? 0 : d[i][j]);
	}
	printf("\n");
  }
  return 0;
}

