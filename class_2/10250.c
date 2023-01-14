#include <stdio.h>
int main(){
  int num_of_testcases;
  int height, rooms_per_floor, nth_customer;
  int count;
  scanf("%d",&num_of_testcases);
  for(int i = 0 ; i < num_of_testcases; ++i){
	scanf("%d %d %d",&height, &rooms_per_floor, &nth_customer);
	count = 0;
    for(int i = 1 ; i <= rooms_per_floor; ++i){
	 for(int j = 1 ; j <= height; ++j){
	   count++;
	  if( count == nth_customer ) printf("%d\n",j * 100 + i);
	 }
	}
  }
  return 0;
}
