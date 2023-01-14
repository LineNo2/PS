#include <bits/stdc++.h>
#define MAX_N 100001

using namespace std;

int G, P;

int top, bottom;

int Root[MAX_N];

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
  int temp;
  bool flag = 0;
  int ans = 0;
  cin >> G >> P;
  for(int i = 1 ; i <= G ; ++i)
	Root[i] = i;
  for(int i = 0 ; i < P; ++i){
	cin >> temp;
	int insert_pos = find(temp);
	if(insert_pos == 0) flag = true;
	if(flag) continue;
	merge(insert_pos-1, temp);
	++ans;
  }
  cout << ans;
  return 0;
}
