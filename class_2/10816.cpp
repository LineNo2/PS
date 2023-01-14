#include <iostream>
#include <algorithm>

int arr[500050];

int value;

using namespace std;

int binary_search_high(int low, int high){
  if( low > high )
	return high;
  int mid = (low + high) / 2;
  if(arr[mid] <= value)
	return binary_search_high(mid + 1, high);
  else
	return binary_search_high(low, mid - 1);
}
int binary_search_low(int low, int high){
  if( low > high )
	return low;
  int mid = (low + high) / 2;
  if(arr[mid] < value) 
	return binary_search_low(mid + 1, high);
  else
	return binary_search_low(low, mid - 1);
}
int binary_search(int low, int high){
  if( low > high )
	return -1;
  int mid = (low + high) / 2;
  if(arr[mid] < value)
	return binary_search(mid + 1, high);
  else if( arr[mid] == value )
	return mid;
  else
	return binary_search(low, mid - 1);
}

int main(){
  int n, m;
  int temp;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d",&arr[i]);
  }
  sort(arr, arr+n);
  scanf("%d",&m);
  for(int i = 0; i < m ; ++i){
	scanf("%d", &temp);
	value = temp;
	if(binary_search(0, n-1) == -1)
	  printf("0 ");
	else
	printf("%d ", binary_search_high(0, n-1) - binary_search_low(0, n-1) + 1 );
  }
  return 0;
}

