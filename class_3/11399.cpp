#include <iostream>
#include <algorithm>

int main(){
  int n;
  int arr[1001];
  int time = 0;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i)
	scanf("%d", &arr[i]);
  std::sort(arr,arr+n);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j <= i ; ++j){
	  time += arr[j];
	}
  }
  printf("%d",time);
  return 0;
}
