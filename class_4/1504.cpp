#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 987654321

using namespace std;

std::queue<int> Q;
int min(int a, int b){
  return a > b ? b : a;
}

int main(){
  int n,m;
  int G[1000][1000];
  int is_vistied[1000];
  int visiting_value[1000];
  int st, ed, value;
  int temp;
  int min_temp;
  scanf("%d %d",&n,&m);
  for(int i = 1 ; i <= n ; ++i){
	for(int j = 1 ; j <= n ; ++j){
	  G[i][j] = MAX;
	}
	is_vistied[i] = 0;
	visiting_value[i] = MAX;
  }
  for(int i = 0 ; i < m ; ++i){
	scanf("%d %d %d",&st,&ed,&value);
	G[st][ed] = value;
	//G[ed][st] = value;
  }
  scanf("%d %d",&st, &ed);
  Q.push(st);
  visiting_value[st] = 0;
	for(int i = 1 ; i <= n; ++i){
	  visiting_value[i] = min(G[st][i],visiting_value[i]);
	}
  while(Q.empty() == false){
	value = 0;
	temp = Q.front();
	Q.pop();
	for(int i = 1 ; i <= n; ++i){
	  visiting_value[i] = min(visiting_value[i], visiting_value[temp] + G[temp][i]);
	  //printf("%d is %d\t",i,visiting_value[i]);
	}
	is_vistied[temp] = 1;
	min_temp = 987654321;
	for(int i = 1 ; i <=n; ++i){
	  if(is_vistied[i] == 0 && min_temp > visiting_value[i])  {
		min_temp = visiting_value[i];
		temp = i;
		value = 1;
	  }
	}
	if(value == 1){
	Q.push(temp);
	//printf("%d is minimum %d\n",temp,visiting_value[temp]);
	}
  }
  printf("%d",visiting_value[ed]);
  return 0;
}


