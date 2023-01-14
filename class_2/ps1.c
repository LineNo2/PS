#include <stdio.h>
int main(){
  int n;
  int int_arr[10000] = {0,};
  int primes[10000];
  int count = 0;
  scanf("%d",&n);
  for(int i = 2 ; i <= n ; ++i){
	if(int_arr[i]) continue;
	int_arr[i] = 2;
	primes[count++] = i;
	for(int j = 2 ; j*i <= n ; j++){
	  int_arr[j*i] = 1;
	}
  }
  for(int i = 0; i < count - 1 ; ++i){
	if(n < primes[i] * primes[i + 1]){
	  printf("%d\n", primes[i] * primes[i + 1]);
	return 0;
	}
  }
  return 0;
}
	
	
