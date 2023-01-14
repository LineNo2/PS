#include <bits/stdc++.h>

using namespace std;

long long A, B;

long long DFS(long long num, int r){
  if(r == 0) return 0;
  long long result = num%(long long)pow(2,r) - (long long)pow(2,r-1) + 1;
  result = result < 0 ? 0 : result;
  result += num/(long long)pow(2,r-1)/2 * (long long)pow(2,r-1);
  return DFS(num, r-1) + result;
}

int main(){
  cin >> A >> B;
  int i = -1;
  A -= 1;
  while(1){
	if(A < pow(2,++i)) break;
  }
  A = DFS(A, i);
  i = -1;
  while(1){
	if(B < pow(2, ++i)) break;
  }
  B = DFS(B, i);
  cout << B - A;
  return 0;
}
