#include <iostream>
#include <algorithm>

using namespace std;

long long num_of_trees, goal_meter;
long long height_of_trees_arr[1000010];

long long binary_search(long long start, long long end);
long long cal_chopped_trees(long long height);

long long binary_search(long long start, long long end){
  long long mid = (start + end ) / 2;
  long long temp;
  if(start > end)
	return end;
  if( (temp = cal_chopped_trees(mid)) < goal_meter)
	return binary_search( start, mid - 1 );
  else if ( temp > goal_meter )
	return binary_search( mid + 1, end );
  else 
	return mid;
}

long long cal_chopped_trees(long long height){
  long long result = 0;
  long long temp;
  for(long long i = 0 ; i < num_of_trees ; ++i){
	result += (temp = height_of_trees_arr[i] - height) > 0 ? temp : 0;
  }
  return result;
}


int main(){
  scanf("%lld %lld", &num_of_trees, &goal_meter);
  for(long long i = 0 ; i < num_of_trees ; ++i){
	scanf("%lld",&height_of_trees_arr[i]);
  }
  sort(height_of_trees_arr, height_of_trees_arr + num_of_trees);
  printf("%lld", binary_search(0, height_of_trees_arr[num_of_trees - 1]));

  return 0;
}

  
