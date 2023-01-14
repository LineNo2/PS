#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Appointment{
  int st;
  int et;
}Appointment;

bool compare(const Appointment& p1, const Appointment& p2){
  if( p1.et == p2.et ) { return p1.st < p2.st; }
  return p1.et < p2.et;
}

int main(){
  int n;
  int count;
  int former_et;
  Appointment arr[100010];
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d %d",&arr[i].st, &arr[i].et);
  }
  sort(arr, arr + n, compare);
  count = 1;
  former_et = arr[0].et;
  for(int i = 1 ; i < n ; ++i){
	  if( arr[i].st >= former_et ){
	    ++count;
	    former_et = arr[i].et;
	  }
  }
  printf("%d",count);
  return 0;
}

