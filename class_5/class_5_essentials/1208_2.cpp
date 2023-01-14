#include <bits/stdc++.h>

using namespace std;

int N, S;
int N2;

long long ans;

int D[4000010];
int arr[41];
void dfsL(int idx, int sum){
  if(idx == N2){
	D[2000000 + sum]++;
  }
  else{
	dfsL(idx + 1, sum + arr[idx]);
	dfsL(idx + 1, sum);
  }
}

void dfsR(int idx, int sum){
  if(idx == N){
	if((idx = 2000000 + (S - sum)) > 4000000 || idx < 0);
	else ans += D[idx];
  }
  else{
	dfsR(idx + 1, sum + arr[idx]);
	dfsR(idx + 1, sum);
  }
}

int main(){
  cin >> N >> S;
  if(S == 0)--ans;
  N2 = N/2;
  for(int i = 0 ; i < N ; ++i)
	cin >> arr[i];
  dfsL(0, 0);
  dfsR(N2, 0); 
  cout << ans ;
  return 0;
}
