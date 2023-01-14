#include <stdio.h>
int main(){
  int temp;
  int n ;
  int arr[10001];

  scanf("%d",&n);

  for(int i = 0 ; i < n; ++i){
	scanf("%d",&temp);
	++arr[temp];
  }

  for(int i = 1; i <= n; ++i){
	for(int j = 0 ; j < arr[i] ; ++j){
	  printf("%d\n", i);
    }
  }
  return 0;
}


