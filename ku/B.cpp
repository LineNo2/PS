#include <bits/stdc++.h>
#define N_MAX 6

using namespace std;

int N, S, T, K;

int Fire[N_MAX];

int ans;

void printArr(int arr[]){
  for(int i = 0 ; i < N ; ++i)
	printf("%d ",arr[i]);
  printf("\n");
}

void FireDecrease(int pos, int Fire_[]){
  int Next_Fire[N_MAX];
  int count = 0;
  memcpy(Next_Fire, Fire_, sizeof(Next_Fire));
  for(int i = 0 ; i < N; ++i){
	if(pos == i) continue;
	--Next_Fire[i];
	if(i == 0 || Fire_[i-1] <= 0) --Next_Fire[i];
	if(i == N-1 || Fire_[i+1] <= 0) -- Next_Fire[i];
  }
  memcpy(Fire_,Next_Fire,sizeof(Next_Fire));
  printArr(Fire_);
}

void DFS(int time, int pos, int Fire[]){
  if(pos < 0 || pos >= N) return;
  printf("DFS(%d,%d) \n", time ,pos);
  FireDecrease(pos, Fire);
  if(time == T){
	int cnt = 0;
	for(int i = 0 ; i < N ; ++i)
	  if(Fire[i] > 0) ++cnt;
	if(cnt >= K) ++ans;
	return;
  }
  DFS(time+1, pos-1, Fire);
  DFS(time+1, pos+1, Fire);
  DFS(time+1, pos, Fire);
}

int main(){
  cin >> N >> S >> T >> K;
  for(int i = 0 ; i < N ; ++i)
	cin >> Fire[i];
  DFS(0, S, Fire);
  cout << ans;
  return 0;
}
