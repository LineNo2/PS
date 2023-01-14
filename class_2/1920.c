#include <stdio.h>


int int_arr[100010];

void quick_sort(int *data, int start, int end){ 
  if(start >= end){ // 원소가 1개인 경우 
	return; } 
  int pivot = start; 
  int i = pivot + 1; // 왼쪽 출발 지점 
  int j = end; // 오른쪽 출발 지점 
  int temp; while(i <= j){ // 포인터가 엇갈릴때까지 반복 
	while(i <= end && data[i] <= data[pivot]){ 
	  i++; 
	} 
	while(j > start && data[j] >= data[pivot]){
	  j--; 
	} 
	if(i > j){ // 엇갈림 
	  temp = data[j]; 
	  data[j] = data[pivot]; 
	  data[pivot] = temp; 
	}
	else{ // i번째와 j번째를 스왑 
	  temp = data[i]; 
	  data[i] = data[j]; 
	  data[j] = temp; 
	} 
  } // 분할 계산 
  quick_sort(data, start, j - 1); 
  quick_sort(data, j + 1, end); 
}

int binary_search(int start, int end, int value){
  if(start > end) return 0;
  int mid = (start + end) / 2;
  if( int_arr[mid] == value)
	return 1;
  else if( int_arr[mid] < value )
	return binary_search(mid + 1, end , value);
  else
	return binary_search(start, mid - 1, value);
}
  
int main(){
  int n, m;
  int temp;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
	scanf("%d", &int_arr[i]);
  }
  quick_sort(int_arr, 0, n);
  scanf("%d",&m);
  for(int i = 0 ; i < m ; i++){
	scanf("%d",&temp);
	printf("%d\n", binary_search(0, n, temp));
  }
  return 0;
}
  
