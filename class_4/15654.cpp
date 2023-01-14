#include <iostream>
#include <algorithm>

using namespace std;

int n , m;

bool comp(int a, int b){
  return a < b;
}

int nums[9];
bool check[9];
int arr[9];

void print_arr(){
  for(int i = 0 ; i < m ; ++i)
	cout << arr[i] << " ";
  cout << "\n";
}

void bt_perm(int idx, int key){
  if(idx == m) print_arr();
  else{
	for(int i = 0 ; i < n ; ++i){
    if(check[i]) continue;
	  arr[idx] = nums[i];
    check[i] = true;
	  bt_perm(idx + 1, i);
    check[i] = false;
	}
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0 ; i < n ;++i)
	cin >> nums[i];
  sort(nums, nums + n);
  bt_perm(0,0);
  return 0;
}


