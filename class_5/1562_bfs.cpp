#include <bits/stdc++.h>
#define STR_MAX 101
#define MOD 1000000000

using namespace std;

typedef struct Elem{
	int cur_num;
	int cnt;
	bool flag;
}Elem;

int N;

int check_curnum_pushed[2][10][STR_MAX]; // 0 -> front , 1 -> end

int main(){
  queue<Elem> Q;
	long long ans = 0;
  cin >> N;  
  if(N < 10) {
	cout << 0;
	return 0;
  }
  if(N == 10){
	cout << 1;
	return 0;
  }
	if(N == 11){
		cout << 3;
		return 0;
	}
  Q.push({.cur_num = 1, .cnt = 11, .flag = true});
	++check_curnum_pushed[1][1][11];
	Q.push({.cur_num = 9, .cnt = 11, .flag = true});
	++check_curnum_pushed[1][9][11];
	Q.push({.cur_num = 1, .cnt = 11, .flag = false});
	++check_curnum_pushed[0][1][11];
  Q.push({.cur_num = 8, .cnt = 11, .flag = false});
	++check_curnum_pushed[0][8][11];
	
  while(!Q.empty()){
	int cur_num = Q.front().cur_num;
	int cnt = Q.front().cnt;
	bool flag = Q.front().flag;
	Q.pop();
	if(cnt == N) continue;
	++cnt;
	if(cur_num > 0) {
	  if(!check_curnum_pushed[flag][cur_num - 1][cnt]){
		Q.push({.cur_num = cur_num - 1, .cnt = cnt, .flag = flag});
	  }
	  check_curnum_pushed[flag][cur_num - 1][cnt] = 
		(check_curnum_pushed[flag][cur_num - 1][cnt] 
		+ check_curnum_pushed[flag][cur_num][cnt-1]) % MOD ;
	}
	if(cur_num < 9) {
	  if(!check_curnum_pushed[flag][cur_num + 1][cnt]){
	  Q.push({.cur_num = cur_num + 1, .cnt = cnt, .flag = flag});
	  }
	  check_curnum_pushed[flag][cur_num + 1][cnt] =
			(check_curnum_pushed[flag][cur_num + 1][cnt]
		+ check_curnum_pushed[flag][cur_num][cnt-1]) % MOD ;
	}
  }
	for(int i = 1 ; i < 10 ; ++i)
	for(int j = 0 ; j < 2 ; ++j)
		ans = (ans + check_curnum_pushed[j][i][N]) % MOD; 
  cout << (ans + check_curnum_pushed[1][0][N])%MOD;
  return 0;
}



