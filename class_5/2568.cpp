#include <bits/stdc++.h>
#define N_MAX 100001
#define endl "\n"

using namespace std;

typedef struct Line{
  int st, ed;
  bool operator < (const Line &l) const{
	return st < l.st;
  }
}Line;

typedef struct Elem{
  int num;
  int idx;
}Elem;

int N;

int DP[N_MAX];

bool is_valid[N_MAX];

vector<Elem> Trace[N_MAX];

vector<Line> Lines;

void DFS(int cur, int former_idx){
  if(cur == 0) return;
  for(int i = Trace[cur].size() - 1 ; i >= 0 ; --i){
	int cur_idx = Trace[cur][i].idx;
	if(former_idx < cur_idx) continue;
	DFS(cur - 1, cur_idx);
	is_valid[cur_idx] = true;
	return;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int st, ed;
  cin >> N;
  for(int i = 0 ; i < N ; ++i){
	cin >> st >> ed;
	Lines.push_back({.st = st, .ed = ed});
  }
  sort(Lines.begin(), Lines.end());
  fill(DP + 1, DP + N + 1, 500001);
  int max_length = 1;
  DP[1] = Lines[0].ed;
  Trace[1].push_back({.num = Lines[0].ed, .idx = 0});
  for(int i = 1 ; i < N ; ++i){
	int cur = Lines[i].ed;
	int idx = lower_bound(DP, DP + max_length + 1, cur) - DP;
	if(DP[idx] < cur) continue;
	DP[idx] = cur;
	Trace[idx].push_back({.num = Lines[i].st, .idx = i});
	if( idx > max_length ) ++max_length;
  }
  cout << N - max_length << endl; 
  is_valid[Trace[max_length][0].idx] = true;
  DFS(max_length-1,Trace[max_length][0].idx);
  for(int i = 0 ; i < N ; ++i){
	if(is_valid[i]) continue;
	cout << Lines[i].st << endl;
  }
  return 0;
}
