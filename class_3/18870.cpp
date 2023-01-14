#include <iostream>
#include <algorithm>

typedef struct Point{
  int index;
  int data;
}Point;

Point arr[1000010];

bool cmp_data(Point& p1, Point& p2){
  return p1.data < p2.data;
}

bool cmp_index(Point& p1, Point& p2){
  return p1.index < p2.index;
}

int main(){
  int n;
  int temp;
  int min = 0;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d",&temp);
	arr[i].data = temp;
	arr[i].index = i;
  }
  std::sort(arr, arr + n , cmp_data);
  temp = arr[0].data;
  arr[0].data = min;
  for(int i = 1 ; i < n ; ++i){
	if(temp == arr[i].data){
	  arr[i].data = min;
	}
	else{
	  temp = arr[i].data;
	  arr[i].data = ++min;
	}
  }
  std::sort(arr, arr+n, cmp_index);
  for(int i = 0 ; i < n ; ++i){
	printf("%d " ,arr[i].data);
  }
  return 0;
}
