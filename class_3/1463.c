#include <stdio.h>
int arr[1000010];

int return_min(int a, int b){
  if( a > b) return b;
  return a;
}

int main(){
  int n;
  scanf("%d",&n);
  arr[2] = 1;
  arr[1] = 0;
  arr[3] = 1;
  for(int i = 4 ; i <= n; i++){
	if(i%3 == 0) {
		if(i%2 == 0){
			arr[i] = return_min(arr[i/3] + 1, arr[i/2] + 1);
		}
		else{
		arr[i] = return_min(arr[i/3] + 1,arr[i/2] + 2);}
	}
	else if(i%3 == 1){
	  if(i%2 == 0){
		arr[i] = return_min(arr[i/3] + 2, arr[i/2] + 1);
	  }
	  else arr[i] = return_min(arr[i/3] + 2, arr[i/2] + 2);
	}
	else{
	  if(i%2 == 0){
		arr[i] = return_min(arr[i/3] + 3, arr[i/2] + 1);
	  }
	  else{
		arr[i] = return_min(arr[i/3] + 3, arr[i/2] + 2);
	  }
	}
  }
  printf("%d",arr[n]);
  return 0;
}
