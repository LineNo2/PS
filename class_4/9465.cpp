#include <iostream>
#include <algorithm>
#define MAX 100010

using namespace std;

int value[2][MAX];
int d[2][MAX];

int max(int a, int b){
  return a > b ? a : b;
}
int get_reverse_index(int a){
  return a == 0 ? 1 : 0;
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL);
  int tc;
  int n;
  cin >> tc;
  for(int c = 0 ; c < tc; ++c){
	cin >> n;
	for(int h = 0 ; h < 2 ; ++h){
	  for(int i = 0 ; i < n ; ++i){
		cin >> value[h][i];
	  }
	}
	d[0][0] = value[0][0];
	d[0][1] = value[0][1];
	d[1][0] = d[0][1] + value[1][0];
	d[1][1] = d[0][0] + value[1][1];
	for(int i = 0 ; i < n ; ++i){
	  for(int j = 0 ; j < 2 ; ++j){
		d[j][i] = max(max(d[get_reverse_index(j)][i-1], d[get_reverse_index(j)][i-2]), d[j][i-2]) + value[j][i];
	  }
	}
	cout << max(d[0][n-1], d[1][n-1]) <<endl;
	fill(d[0],d[0] + n, 0);
	fill(d[1], d[1] + n, 0);
  }
  return 0;
}
