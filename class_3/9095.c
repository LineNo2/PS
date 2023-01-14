#include <stdio.h>
int main()
{
  int n;
  int temp;
  int arr[12];
  scanf("%d",&n);
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  for(int i = 4 ; i < 12; ++i){
	arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
  }
  for(int i = 0 ; i < n; ++i){
	scanf("%d",&temp);
	printf("%d\n",arr[temp]);
  }
  return 0;
}
