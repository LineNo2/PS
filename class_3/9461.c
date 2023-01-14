#include <stdio.h>

int main(){
  int test_cases;
  int n;
  long long arr[100];
  int k = 2;
  scanf("%d",&test_cases);
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 2;
  arr[4] = 2;
  arr[5] = arr[2] + arr[4];
  arr[6] = arr[1] + arr[5];
  arr[7] = arr[0] + arr[6];
  for(int i = 8 ; i < 100 ; ++i){
	arr[i] = arr[i-1] + arr[i - 5];
  }
  for(int cases = 0 ; cases < test_cases ; ++cases){
	scanf("%d", &n);
	printf("%llu\n",arr[n - 1]);
  }
  return 0;
}
