#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Point{
  int x;
  int y;
}Point;

bool compare(const Point& p1, const Point& p2){
  if(p1.x == p2.x)
	return p1.y < p2.y;
  else
	return p1.x < p2.x;
}

int main(){
  int n;
  Point arr[100010];
  scanf("%d",&n);
  for(int i = 0; i < n ; ++i)
	scanf("%d %d",&arr[i].x, &arr[i].y);
  sort(arr, arr+n, compare);
  for(int i = 0; i < n ; ++i)
	printf("%d %d\n", arr[i].x, arr[i].y);
  return 0;
}

