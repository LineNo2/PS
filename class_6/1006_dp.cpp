#include <bits/stdc++.h>
#define N_MAX 10001

using namespace std;

int TC;
int N, Num;

int Area[N_MAX*2];

bool is_pos[N_MAX][3];

int DP[N_MAX][5];

bool pos_0[5];

FILE *fp;

void printArr(int arr[][5]){
  for(int i = 0 ; i < 5 ; ++i){
	for(int j = 0 ; j < N; ++j){
	  fprintf(fp,"%d ", arr[j][i]);
	}
	fprintf(fp,"\n");
  }
  fprintf(fp,"\n");
}

void printArr(bool arr[][3]){
  for(int i = 0 ; i < 3 ; ++i){
	for(int j = 0 ; j < N; ++j){
	  fprintf(fp,"%d ", arr[j][i]);
	}
	fprintf(fp,"\n");
  }
  fprintf(fp,"\n");
}

int main(){
  // fp = fopen("output.txt","w+");
  cin >> TC;
  for(int tc = 0 ; tc < TC; ++tc){
	cin >> N >> Num;
	memset(is_pos,0,sizeof(is_pos));
	int ans = 0;
	for(int i = 0 ; i < 2*N ; ++i)
	  cin >> Area[i];
	for(int i = 0 ; i < N ; ++i){
	  if(Area[i] + Area[i+N] <= Num) is_pos[i][2] = true;
	  if(Area[i] + Area[(i+1)%N] <= Num) is_pos[i][0] = true;
	  if(Area[i+N] + Area[(i+1)%N + N] <= Num) is_pos[i][1] = true;
	}
	// printArr(is_pos);
	for(int k = 0 ; k <= 8; ++k){
	  memset(DP,0,sizeof(DP));
	  bool flag[5];
	  flag[1] = (k & (1 << 0)) && is_pos[0][0];
	  flag[2] = (k & (1 << 1)) && is_pos[0][1];
	  flag[3] = (k & (1 << 2)) && is_pos[0][0] && is_pos[0][1];
	  flag[4] = (k & (1 << 3)) && is_pos[0][2];

	  for(int i = 1 ; i < 5;  ++i)
		DP[0][i] = flag[i];
	  for(int i = 1 ; i < N ; ++i){
		int former_max = 0;
		for(int j = 0 ; j < 5 ; ++j){
		  former_max = max(former_max, DP[i-1][j]);
		  DP[i][j] = DP[i-1][0];
		}
		DP[i][0] = former_max;
		DP[i][1] = max(DP[i][1], DP[i-1][2]) + is_pos[i][0];
		DP[i][2] = max(DP[i][2], DP[i-1][1]) + is_pos[i][1];
		DP[i][3] = max(DP[i][3], DP[i-1][4]) + is_pos[i][0] + is_pos[i][1];
		DP[i][4] = max(DP[i][4], DP[i-1][4]) + is_pos[i][2];
	  }
	  // printArr(DP);
	  ans = max(ans, DP[N-1][0]);
	  if(flag[1]) ans = max(ans, DP[N-1][2] - is_pos[N-1][2]);
	  else ans = max(ans, DP[N-1][2]);
	  if(flag[2]) ans = max(ans, DP[N-1][1] - is_pos[N-1][1]);
	  else ans = max(ans, DP[N-1][1]);
	  if(flag[3]) ans = max(ans, DP[N-1][3] - is_pos[N-1][1] - is_pos[N-1][2]);
	  else ans = max(ans, DP[N-1][3]);
	  //cout << ans << endl;
	}
	cout << 2*N - ans << endl;
  }
  return 0;
}

