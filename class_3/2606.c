#include <stdio.h>
int map[101][101];
int is_visited[101];
int num_of_computers;
int num_of_nodes;

int search(int n){
  int count = 1;
  for(int i = 2 ; i <= num_of_computers ; ++i){
	if(map[n][i] == 1 && is_visited[i] == 0){
	  is_visited[i] = 1;
	  count = search(i) + count;
	}
  }
  return count;
}
int main(){
  int start = 1;
  int temp1, temp2;
  int count = 0;
  scanf("%d %d",&num_of_computers, &num_of_nodes);
  for(int i = 0 ; i < num_of_nodes ; ++i){
	scanf("%d %d", &temp1, &temp2);
	map[temp1][temp2] = 1;
	map[temp2][temp1] = 1;
  }
  for(int i = 2 ; i <= num_of_computers ; ++i){
	if(map[start][i] == 1 && is_visited[i] == 0){
	  is_visited[i] = 1;
	  count += search(i);
	}
  }
  printf("%d",count);
}

