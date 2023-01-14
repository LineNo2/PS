#include <bits/stdc++.h>
#define N_MAX 100000

using namespace std;

int N;

int Arr[N_MAX];

int main(){
  int *p1, *p2;
  int temp, cur_value; 
  long long min_value = 2e+18;
  int min_elems[2];
  cin >> N;
  for(int i = 0 ; i < N ; ++i)
	cin >> Arr[i];

  int j = N - 1;

  for(int i = 0 ; i < N ; ++i){
	for( ; i < j ; --j){
	  cur_value = abs(Arr[i] + Arr[j]);
	  if( min_value > cur_value ) {
		min_elems[0] = Arr[i];
		min_elems[1] = Arr[j];
		min_value = cur_value;
	  }
	  if( (i == j-1) || abs(Arr[i] + Arr[j-1]) > cur_value) break;
	}
  }
  for(int i = 0 ; i < 2 ; ++i)
	cout << min_elems[i] << " ";
  return 0;
}
