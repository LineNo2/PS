#include <stdio.h>
int main(){
  int n;
  int height[51], weight[51];
  int rank[51];
  int big_guys;
  int cur_weight, cur_height;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i)
	scanf("%d %d",&weight[i], &height[i]);
  for(int i = 0 ; i < n ; ++i){
	big_guys = 0;
	cur_height = height[i];
	cur_weight = weight[i];
	for(int j = 0 ; j < n; ++j){
	  if((cur_weight < weight[j] && cur_height < height[j]))
		++big_guys;
	}
	rank[i] = big_guys;
  }
  for(int i = 0 ; i < n ; ++i)
	printf("%d\n", rank[i] + 1);
  return 0;
}


