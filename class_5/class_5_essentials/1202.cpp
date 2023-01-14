#include <bits/stdc++.h>
#define MAXN 300000

using namespace std;

typedef struct Jam{
  int mass;
  int value;
  bool operator<(const Jam& J)const{
  return value < J.value;
  }
}Jam;

bool comp(int a, int b){
  return a > b;
}

bool sort_jam(Jam a, Jam b){
  return a.mass < b.mass;
}

int N, K;
Jam jams[MAXN];
int bags[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, v, c;
  long long ans = 0;
  priority_queue<Jam> PQ;
  cin >> N >> K;
  for(int i = 0 ; i < N ; ++i){
	cin >> m >> v;
	jams[i] = {.mass = m, .value = v};
  }
  for(int i = 0 ; i < K ; ++i)
	cin >> bags[i];
  sort(jams, jams + N, sort_jam);
  sort(bags, bags + K);
  int former_idx = 0;
  int flag = 0;
  for(int i = 0 ; i < K ; ++i){
	int cur_c = bags[i];
	flag = 0;
	for(int i = former_idx ; i < N ; ++i){
	  if(jams[i].mass > cur_c) break;
	  PQ.push(jams[i]);
    ++former_idx;
	}
	if(!PQ.empty()){
		ans += (long long)PQ.top().value;
	  PQ.pop();
	}
  }
  cout << ans;

  return 0;
}


