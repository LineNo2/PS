#include <stdio.h>
int main(){
  int n, m;
  int cloest_num = -1;
  int temp;
  int cards[110];
  scanf("%d %d",&n, &m);
  for(int i = 0 ; i < n; ++i){
	scanf("%d", &cards[i]);
  }
  for(int i = 0 ; i < n ; ++i){
	for(int j = 1 ; j < n ; ++j){
	  for(int k = 2 ;  k < n ; ++k){
		if(( ( i != j ) && (i != k) && ( j != k) && ( (temp = ((cards[i] + cards[j]) + cards[k])) <= m))){
		  if(cloest_num < temp)
			cloest_num = temp;
		}
	  }
	}
  }
  printf("%d", cloest_num);
  return 0;
}



