#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  int num_arr[1000010];
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++)
	scanf("%d",&num_arr[i]);
  sort(num_arr, num_arr + n);
  for(int i = 0 ; i < n ; i++)
	printf("%d\n",num_arr[i]);
  return 0;
}
  

