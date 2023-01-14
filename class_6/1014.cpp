#include <bits/stdc++.h>
#define N_MAX 10

using namespace std;

int TC;
int N, M;

bool Map[N_MAX][N_MAX];

int Count_x[N_MAX];

int ans = 0;

void BruteForce(int cur, int cnt){
  cnt += N - Count_x[cur];
  if(cur >= M-2) {
	ans = max(ans, cnt);
	return;
  }
  for(int i = cur + 1 ; i < M ; ++i){
	BruteForce(i, cnt);
  }
}

int main(){
  char temp;
  scanf("%d\n",&TC);
  while(TC--){
	scanf("%d %d\n",&N, &M);
	ans = 0;
	memset(Map,0,sizeof(Map));
	memset(Count_x,0,sizeof(Count_x));
	for(int i = 0 ; i < N ; ++i){
	  for(int j = 0 ; j < M ; ++j){
		temp = getchar();
		if(temp == 'x'){
		Map[i][j] = true;
		++Count_x[j];
		}
	  }
	  getchar();
	}
	BruteForce(0,0);
	cout << ans << endl;
  }
  return 0;
}

