#include <iostream>
#include <algorithm>

using namespace std;

int n , m;

bool comp(int a, int b){
  return a < b;
}

int nums[9];
int arr[9];

void print_arr(){
 
  for(int i = 0 ; i < m ; ++i)
	cout << arr[i] << " ";
  cout << "\n";
}

void check_true(int idx, int key){
  for(int i = idx; i <= m ; ++i)
	  check[i][key] = true;
}

void check_true_this_level(int idx, int key){
  for(int i = key ; i < n ; ++i){
    if(nums[key] < nums[i]) break;
    check[idx][i] = true;
  }
}

void check_false(int idx, int key){
  for(int i = idx; i <= m ; ++i)
	check[i][key] = false;
}

void check_false_this_level(int idx, int key){
  for(int i = key ; i < n ; ++i){
    if(nums[key] < nums[i]) break;
    check[idx][i] = false;
  }
}

void bt_perm(int idx, int key){
  bool check[9];
  if(idx == m) print_arr();
  else{
	for(int i = 0 ; i < n ; ++i){
    if(check[idx][i]) continue;
    // if(i != 0 && nums[i] == nums[i-1]) continue;
	  arr[idx] = nums[i];
	  check_true(idx,i);
    check_true_this_level(idx,i);
	  bt_perm(idx + 1, i);
    check_false(idx,i);
	}
  for(int i = 0 ; i < n ; ++i)
    check_false_this_level(idx,i);
  }
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin >> n >> m;
  for(int i = 0 ; i < n ;++i)
	cin >> nums[i];
  sort(nums, nums + n);

  return 0;
}


