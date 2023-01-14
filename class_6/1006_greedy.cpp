#include <bits/stdc++.h>
#define N_MAX 10001

using namespace std;

int TC;
int N, Num;

int Area[N_MAX*2];

bool is_pos[N_MAX][3];

int DP[N_MAX];

int Status[N_MAX];

FILE *fp;

void printArr(int arr[]){
  for(int j = 0 ; j < N; ++j){
	fprintf(fp,"%d ", arr[j]);
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
  fp = fopen("output.txt","w+");
  cin >> TC;
  for(int tc = 0 ; tc < TC; ++tc){
	cin >> N >> Num;
	memset(is_pos,0,sizeof(is_pos));
	int ans = 2 * N_MAX;
	for(int i = 0 ; i < 2*N ; ++i)
	  cin >> Area[i];
	for(int i = 0 ; i < N ; ++i){
	  if(Area[i] + Area[i+N] <= Num) is_pos[i][0] = true;
	  if(Area[i] + Area[(i+1)%N] <= Num) is_pos[i][1] = true;
	  if(Area[i+N] + Area[(i+1)%N + N] <= Num) is_pos[i][2] = true;
	}
	printArr(is_pos);
	for(int k = 0 ; k <= 4; ++k){
	  fill(DP, DP + N_MAX, 2*N_MAX);
	  fill(Status, Status + N_MAX, 0);
	  if(1 <= k && k <= 3 && !is_pos[0][k-1]) continue;
	  if(k == 4 && !( is_pos[0][1] && is_pos[0][2] )) continue;
	  DP[0] = 2;
	  DP[1] = 4;
	  switch(k){
		case 1:
		  DP[0] = 1; Status[0] = 3;
		  DP[1] = 3;
		  break;
		case 2:
		case 3:
		  DP[0] = 2; Status[0] = k-1;
		  DP[1] = 3; Status[1] = k-1;
		  break;
		case 4:
		  DP[0] = 2; Status[0] = 3;
		  DP[1] = 2; Status[1] = 3;
		  break;
	  }
	  if(is_pos[1][0] && !Status[1]){
		DP[1] = DP[0] + 1;
		Status[1] = 3;
	  }
	  for(int i = 2 ; i < N ; ++i){
		DP[i] = DP[i-1] + 2;
		if(is_pos[i][0]){
			DP[i] = DP[i-1] + 1;
			Status[i] = 3;
		}
		bool flag1 = is_pos[i-1][1] && !(Status[i-1] & 1);
		bool flag2 = is_pos[i-1][2] && !(Status[i-1] & 2);
		if(flag1 && flag2){
		  DP[i] = DP[i-1];
		  Status[i] = 3;
		}
		else if(flag1){
		  DP[i] = DP[i-1] + 1;
		  Status[i] = 1;
		}
		else if(flag2){
		  DP[i] = DP[i-1] + 1;
		  Status[i] = 2;
		}
	  }
	  bool flag[2];
	  for(int j = 1 ; j <= 2 ; ++j)
		flag[j-1] = is_pos[N-1][j] && !(Status[0] & j) && !(Status[N-1] & j);
	  DP[0] = DP[N-1]  - flag[0] - flag[1];
	  printArr(DP);
	  ans = min(ans, DP[0]);
  }
  cout << ans << endl;
}
return 0;
}

