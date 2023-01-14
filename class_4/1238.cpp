#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 987654321

using namespace std;

typedef struct Node{
	int st, ed, value;
}Node;

queue<int> Q;
int n,m,k;
int G[1001][1001];
Node nodes[10001];

int min(int a, int b){
  return a > b ? b : a;
}

void get_dijkstra_arr(int st, int d[]){
  int is_visited[1001] = {0,};
  int temp;
  int min_temp, flag;
	is_visited[st] = 1;
	d[st] = 0;
	Q.push(st);
	for(int i = 1; i <= n ; ++i){
		d[i] = min(G[st][i], d[i]);
	}
	while(Q.empty() == false){
	  min_temp = MAX;
	  flag = 0;
	  temp = Q.front();
	  Q.pop();
	  is_visited[temp] = 1;
	  for(int i = 1 ; i <= n ; ++i){
		d[i] = min(d[i] , d[temp] + G[temp][i]);
	  }
	  for(int i = 1 ; i <= n ; ++i){
		if(is_visited[i] == 0 && min_temp > d[i]){
		  flag = 1;
		  min_temp = d[i];
		  temp = i;
		}
	  }
	  if(flag == 1){
		Q.push(temp);
	  }
	}
	return;
}

int main(){
  int st,et,value;
  int d[1001];
  int d2[1001];
  int temp;
  scanf("%d %d %d",&n,&m,&k);
	for(int i = 1;  i <= n ; ++i){
		for(int j = 1; j <= n ; ++j)
		G[i][j] = MAX;
	d[i] = MAX;
	d2[i] = MAX;
  }
  for(int i = 1; i <= m ; ++i){
	scanf("%d %d %d", &nodes[i].st, &nodes[i].ed, &nodes[i].value);
	G[nodes[i].st][nodes[i].ed] = nodes[i].value;
  }
  get_dijkstra_arr(k, d);
	temp = 0;
	for(int i = 1;  i <= n ; ++i)
		for(int j = 1; j <= n ; ++j)
			G[i][j] = MAX;
	 for(int i = 1; i <= m ; ++i){
	G[nodes[i].ed][nodes[i].st] = nodes[i].value;
  }
	get_dijkstra_arr(k, d2);
	temp = 0;
  for(int i = 1 ; i <= n ; ++i){
	if(temp < (value = d[i] + d2[i]))
	temp = value;
  }
  printf("%d",temp);
  return 0;
}
