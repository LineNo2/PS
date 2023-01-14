#include <bits/stdc++.h>
#define NMAX 100000
#define INF 987654321
using namespace std;

int N, S;

int arr[NMAX];

int find_idx(int ed, int key){
  int *p = lower_bound(arr, arr+ed, key);
  if((*p) == key) p++;
  //printf("lower_bound of %d : %ld = %d\n",key, p - arr, *p );
  return p - arr;
}

int main(){
  int temp;
  int min_length = INF;
  cin >> N >> S >> arr[0];
  for(int i = 1 ; i < N ; ++i){
	cin >> temp;
	arr[i] += arr[i-1] + temp;
  }

  for(int i = N-1 ; i >= 0 ; --i){
	if(arr[i] < S) break;
	min_length = min(i - find_idx(i-1, arr[i] - S), min_length); 
  }
  if(min_length == INF) cout << 0;
  else cout << min_length + 1;
  return 0;
}

