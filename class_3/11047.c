#include <stdio.h>

int main(){
  int n, k;
  int arr[10];
  int count = 0;
  scanf("%d %d",&n,&k);
  for(int i = 0; i < n ; ++i)
	scanf("%d",&arr[i]);
  for(int i = n - 1 ; i >= 0 ; --i){
	if(k >= arr[i]){
	  count += k/arr[i];
	  k -= (int)(k/arr[i])*arr[i];
	}
  }
  printf("%d",count);
  return 0;
}
