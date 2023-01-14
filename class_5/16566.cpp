#include <bits/stdc++.h>
#define N_MAX 4000002
#define endl "\n"

using namespace std;

int N, M, K;

vector<int> Arr;

int Root[N_MAX];

int find(int n){
  if(Root[n] == n) return n;
  return Root[n] = find(Root[n]);
}

void merge(int a, int b){
  a= find(a);
  b = find(b);
  if(a == b) return;
  Root[b] = a;
}

int main(){
  int temp,idx;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> K;
  for(int i = 1 ; i <= N ; ++i)
	Root[i] = i;
  for(int i = 0 ; i < M ; ++i){
	cin >> temp;
	Arr.push_back(temp);
  }
  sort(Arr.begin(), Arr.end());
  for(int i = 0 ; i < K ; ++i){
	cin >> temp;
	idx = upper_bound(Arr.begin(), Arr.end(), temp) - Arr.begin();
	idx = find(idx);
	Root[idx] = idx+1;
	cout << Arr[idx] << endl;
  }
  return 0;
}
