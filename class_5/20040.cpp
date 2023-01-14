#include <bits/stdc++.h>
#define N_MAX 1000001

using namespace std;

int N, M;

int Root[N_MAX];

int find(int n){
  if(n == Root[n]) return n;
  return Root[n] = find(Root[n]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  Root[b] = a;
}

int main(){
  int from, to;
  int ans = 0;
  cin >> N >> M;
  for(int i = 0 ; i <= N ; ++i)
	Root[i] = i;
  for(int i = 1 ; i <= M ; ++i){
	cin >> from >> to;
	if(ans == 0 && find(from) == find(to)) ans = i;
	else  merge(from, to);
  } 
  cout << ans;
  return 0;
}
