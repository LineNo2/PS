#include <bits/stdc++.h>
#define N_MAX 100000

using namespace std;

int N;

long long Arr[N_MAX];

int main(){
  long long temp, cur_value; 
  long long min_value = 3e+18;
  int min_elems[3];
  cin >> N;
  for(int i = 0 ; i < N ; ++i)
	cin >> Arr[i];

  sort(Arr, Arr + N);

  for(int k = 0 ; k < N ; ++k){
  int j = N - 1;
  for(int i = k + 1 ; i < N ; ++i){
	for( ; i < j ; --j){
	  cur_value = abs(Arr[k] + Arr[i] + Arr[j]);
	  if( min_value > cur_value ) {
		min_elems[0] = Arr[k];
		min_elems[1] = Arr[i];
		min_elems[2] = Arr[j];
		min_value = cur_value;
	  }
	  if( (i == j-1) || abs(Arr[k] + Arr[i] + Arr[j-1]) > cur_value) break;
	}
  }
  }
  for(int i = 0 ; i < 3 ; ++i)
	cout << min_elems[i] << " ";
  return 0;
}
