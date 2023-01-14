#include <stdio.h>
#include <math.h>

int main(){
  int n;
  int arr[50001] = {0,};
  int sqrt_n;
  int temp;
  scanf("%d",&n);
  temp = ceil(sqrt(n));
  for(int i = 1 ; i*i <= n ; ++i){
	arr[i*i] = 1;
  }
  for(int i = 1 ; i <= floor(sqrt(n)); ++i){
	for(int j = 1 ; j*j <= n - i*i ; ++j){
	  temp = i*i + j*j;
	  if(arr[temp] == 0){
		arr[temp] = 2;
	  }
	}
  }
  for(int i = 1 ; i <= floor(sqrt(n)); ++i){
	for(int j = 1 ; j*j <= n - i*i ; ++j){
	  for(int k = 1 ; k*k <= n - i*i - j*j ; ++k){
	  temp = i*i + j*j + k*k;
	  if(arr[temp] == 0){
		arr[temp] = 3;
	  }
	  }
	}
  }
  printf("%d",arr[n] == 0 ? 4 : arr[n]);
  return 0;
}
