#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  short arr[10000010];
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i)
	scanf("%hd",&arr[i]);
  sort(arr, arr+n);
  for(int i = 0 ; i < n ; ++i)
	printf("%hd\n",arr[i]);
  return 0;
}
