#include <iostream>

using namespace std;

int n , m;

int arr[9];

void print_arr(){
  for(int i = 0 ; i < m ; ++i)
	cout << arr[i] << " ";
  cout << "\n";
}

void bt_perm(int idx, int key){
  if(idx == m) print_arr();
  else{
	for(int i = key ; i <= n ; ++i){
	  arr[idx] = i;
	  bt_perm(idx + 1, i + 1);
	}
  }
}

int main(){
  cin >> n >> m;
  bt_perm(0,1);
  return 0;
}

