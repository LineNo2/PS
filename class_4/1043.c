#include <stdio.h>
typedef struct Party{
  int members_arr[51];
  int n;
  int flag;
}Party;

int n, p;
int temp_number, temp_data;
int temp_data_former;
int is_true[51] = {0,};
int is_visited[51] = {0,};
int G[51][51] = {0,};
int know_truth[51], know_truth_number;
Party parties[51];

void dfs(int k){
  if (is_visited[k] == 1) return;
  is_visited[k] = 1;
  know_truth[know_truth_number++] = k;
  //printf("%d know the truth.\n",k);
  for(int i = 1 ; i <= n  ;++i){
	if(G[k][i] == 1 || G[i][k] == 1)
	  dfs(i);
  }
  return;
}

int main(){
  int count = 0;
  scanf("%d %d",&n ,&p);
  scanf("%d",&know_truth_number);
  for(int i = 0 ; i < know_truth_number ; ++i){
	scanf("%d",&temp_data);
	is_true[temp_data] = 1;
	know_truth[i] = temp_data;
	}
  for(int i = 0 ; i < p; ++i){
	scanf("%d",&temp_number);
	scanf("%d",&temp_data_former);
	parties[i].n= temp_number;
	parties[i].flag = 0;
	parties[i].members_arr[0] = temp_data_former;
	for(int j = 1 ; j < temp_number ;++j){
	  scanf("%d",&temp_data);
	  parties[i].members_arr[j] = temp_data;
	  G[temp_data_former][temp_data] = 1;
	  G[temp_data][temp_data_former] = 1;
	  //printf("G[%d][%d] = 1\n",temp_data_former,temp_data);
	}
  }
  for(int i = 0 ; i < know_truth_number ; ++i){
	//printf("%d searching..\n", know_truth[i]);
	dfs(know_truth[i]);
	//printf("%d\n",i);
  }
  //printf("passed dfs\n");
  count = 0;
  int flag = 0;
	for(int j = 0 ; j < p ;++j){
	flag = -1;
	  for(int k = 0 ; k < parties[j].n ; ++k){
	  if(is_visited[parties[j].members_arr[k]] == 0) continue;
	  flag = 1;
	  }
	if(flag == -1) ++count;
	}
  printf("%d",count);
  return 0;
}

	

