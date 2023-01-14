#include <bits/stdc++.h>
#define N_MAX 100001

using namespace std;

typedef struct Cost{
  int idx, pos;
  bool operator < (const Cost &c) const{
	return pos < c.pos;
  }
}Cost;

typedef struct Edge{
  int from, to, cost;
  bool operator < (const Edge e) const{
	return cost > e.cost;
  }
}Edge;

int N;

vector<Cost> Costs[3];

int Root[N_MAX];

int find(int n){
  if(n == Root[n]) return n;
  return Root[n] = find(Root[n]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if( a == b) return;
  Root[b] = a;
}

int main(){
  priority_queue<Edge> PQ;
  int temp;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i = 0 ; i < N ; ++i){
	Root[i] = i;
	for(int j = 0 ; j < 3 ; ++j){
	  cin >> temp;
	  Costs[j].push_back({.idx = i, .pos = temp});
	}
  }
  if(N == 1){
	cout << 0;
	return 0;
  }
  for(int i = 0 ; i < 3 ; ++i){
	sort(Costs[i].begin(), Costs[i].end());
	int former_idx = Costs[i][0].idx;
	int former_pos = Costs[i][0].pos;
	for(int j = 1 ; j < N ;++j){
	  int cur_idx = Costs[i][j].idx;
	  int cur_pos = Costs[i][j].pos;
	  PQ.push({.from= former_idx, .to= cur_idx, .cost = abs(former_pos - cur_pos)});
	  former_idx = cur_idx;
	  former_pos = cur_pos;
	}
  }
  long long ans = 0;
  while(!PQ.empty()){
	int from = PQ.top().from;
	int to = PQ.top().to;
	int cost = PQ.top().cost;
	PQ.pop();
	if(find(from) == find(to)) continue;
	ans += cost;
	merge(from, to);
  }
  cout << ans;
  return 0;
}

