#include <stdio.h>

int main(){
  int test_cases;
  int temp;
  int arr_0[41];
  int arr_1[41];
  arr_0[0] = 1;
  arr_0[1] = 0;
  arr_1[0] = 0;
  arr_1[1] = 1;
  scanf("%d",&test_cases);
  for(int i = 2 ; i < 41; ++i){
	arr_0[i] = arr_0[i-1] + arr_0[i-2];
	arr_1[i] = arr_1[i-1] + arr_1[i-2];
  }
  for(int i = 0 ; i < test_cases ; ++i){
	scanf("%d",&temp);
	printf("%d %d\n",arr_0[temp] ,arr_1[temp]);
  }
  return 0;
}

