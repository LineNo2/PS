#include <bits/stdc++.h>
#define N_MAX 10001
#define INF 987654321
#define endl "\n"

using namespace std;

int TC;
int N, Num;

int Area[N_MAX*2];

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

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // fp = fopen("output.txt","w+");
  cin >> TC;
  for(int tc = 0 ; tc < TC; ++tc){
	cin >> N >> Num;
	memset(Area,0,sizeof(Area));
	memset(is_pos,0,sizeof(is_pos));
	int ans = INF;
	for(int i = 0 ; i < 2*N ; ++i)
	  cin >> Area[i];
	for(int i = 0 ; i < N ; ++i){
	  if(Area[i] + Area[i+N] <= Num) is_pos[i][0] = true;
	  if(Area[i] + Area[(i+1)%N] <= Num) is_pos[i][1] = true;
	  if(Area[i+N] + Area[(i+1)%N + N] <= Num) is_pos[i][2] = true;
	}
	// printArr(is_pos);
	for(int k = 0 ; k <= 4 ; ++k){
	  for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < 3; ++j)
		  DP[i][j] = INF;
	  DP[0][0] = 2; DP[0][1] = 1; DP[0][2] = 1; 
	  DP[1][0] = is_pos[1][0] ? 3 : 4; DP[1][1] = 3; DP[1][2] = 3;
	  switch(k){
		case 0:
		  break;
		case 1:
		  if(!is_pos[0][0]) continue;
		  DP[0][0] = 1;
		  DP[1][0] = is_pos[1][0] ? 2 : 3;
		  break;
		case 2:
		  if(!is_pos[0][1]) continue;
		  DP[1][1] = 2;
		  break;
		case 3:
		  if(!is_pos[0][2]) continue;
		  DP[1][2] = 2;
		  break;
		case 4:
		  if(!is_pos[0][1] || !is_pos[0][2]) continue;
		  DP[1][0] = 2; DP[1][1] = 2; DP[1][2] = 2;
	  }
	  DP[1][0] = min({DP[1][0], DP[1][1] + 1, DP[1][2] + 1});
	  for(int i = 2 ; i < N ; ++i){
		int vertical = is_pos[i][0] ? 1 : 2;
		int down = is_pos[i-1][1] ? 1 : 2;
		int up = is_pos[i-1][2] ? 1 : 2;
		DP[i][1] = min( DP[i-1][2] + down, DP[i-1][0] + 1);
		DP[i][2] = min( DP[i-1][1] + up, DP[i-1][0] + 1 );
		DP[i][0] = min({DP[i-1][0] + vertical,
			DP[i][2] + 1,
			DP[i][1] + 1,
			DP[i-2][0] + down + up
			});
	  }
	  if(N > 1){
		DP[N-1][2] += is_pos[N-1][1] && ( k == 0 || k == 3) ? 0 : 1;
		DP[N-1][1] += is_pos[N-1][2] && ( k == 0 || k == 2) ? 0 : 1;
		DP[N-1][0] = is_pos[N-1][1] && is_pos[N-1][2] && k == 0 
		  ? DP[N-2][0] : DP[N-1][0]; 
	  }
	  else{
		DP[N-1][1] = 2; DP[N-1][2] = 2;
	  }
	  ans = min({ans,DP[N-1][0] , DP[N-1][1], DP[N-1][2]});
	  //printArr(DP);
	}
	cout << ans << endl;
  }
  return 0;
}

