#include <bits/stdc++.h>
#define N_MAX 10001
#define INF 987654321
#define endl "\n"

using namespace std;

int TC;
int N, W;

int Area[N_MAX][2];

bool is_pos[N_MAX][3];

int DP[N_MAX][3];

FILE *fp;

void printArr(int arr[][3]){
  for(int i = 0 ; i < 3 ; ++i){
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

void DPSolve(){
  for(int i = 1 ; i < N ; ++i){
	int vertical = Area[i][0] + Area[i][1] <= W ? 1 : 2;
	int down = Area[i-1][0] + Area[i][0] <= W ? 1 : 2;
	int up = Area[i-1][1] + Area[i][1] <= W ? 1 : 2;
	DP[i][1] = min( DP[i-1][2] + down, DP[i-1][0] + 1);
	DP[i][2] = min( DP[i-1][1] + up, DP[i-1][0] + 1 );
	DP[i][0] = min({DP[i-1][0] + vertical,
		DP[i][2] + 1,
		DP[i][1] + 1,
		i > 1 ? DP[i-2][0] + down + up : down + up
		});
  }
//  printArr(DP);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 // fp = fopen("output.txt","w+");
  cin >> TC;
  for(int tc = 0 ; tc < TC; ++tc){
	cin >> N >> W;
	memset(Area,0,sizeof(Area));
	memset(is_pos,0,sizeof(is_pos));
	int ans = INF;
	for(int i = 0 ; i < 2 ; ++i)
	  for(int j = 0 ; j < N ; ++j)
		cin >> Area[j][i];
	if(N == 1){
	  ans = Area[0][0] + Area[0][1] <= W ? 1 : 2;
	  cout << ans << endl;
	  continue;
	}
	int Temp[2][2] = { 
	  {Area[N-1][0], Area[N-1][1]},
	  {Area[0][0], Area[0][1]} };
	DP[0][0] = Area[0][0] + Area[0][1] <= W ? 1 : 2; DP[0][1] = 1; DP[0][2] = 1; 
	DPSolve();
	ans = min(ans, DP[N-1][0]);
	if(Area[N-1][0] + Area[0][0] <= W){
	  Area[N-1][0] = INF;
	  Area[0][0] = INF;
	  DP[0][0] = 2; DP[0][1] = 1; DP[0][2] = 1;
	  DPSolve();
	  ans = min(ans, DP[N-1][2]);
	  Area[N-1][0] = Temp[0][0];
	  Area[0][0] = Temp[1][0];
	}
	if(Area[N-1][1] + Area[0][1] <= W){
	  Area[N-1][1] = Area[0][1] = INF;
	  DP[0][0] = 2; DP[0][1] = 1; DP[0][2] = 1;
	  DPSolve();
	  ans = min(ans, DP[N-1][1]);
	  Area[N-1][1] = Temp[0][1];
	  Area[0][1] = Temp[1][1];
	}
	if(Area[N-1][0] + Area[0][0] <= W && Area[N-1][1] + Area[0][1] <= W){
	  Area[N-1][0] = Area[0][0] = INF;
	  Area[N-1][1] = Area[0][1] = INF;
	  DP[0][0] = 2; DP[0][1] = 1; DP[0][2] = 1;
	  DPSolve();
	  ans = min(ans, DP[N-2][0]);
	}
	cout << ans << endl;
  }
  return 0;
}

