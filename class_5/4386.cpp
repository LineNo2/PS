#include <bits/stdc++.h>
#define MAX_N 101

using namespace std;

typedef struct Edge{
  int from, to;
  double cost;
  bool operator < (const Edge &e) const{
	return cost > e.cost;
  }
}Edge;

int N;

int Points[MAX_N][2];

int Root[MAX_N];

int find(int n){
  if(n == Root[n]) return n;
  return Root[n] = find(Root[n]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  Root[b] = a;
}

int main(){
  priority_queue<Edge> PQ;
  double p1,p2;
  cin >> N;
  for(int i = 0 ; i < N ; ++i){
	cin >> p1 >> p2;
	Root[i] = i;
	Points[i][0] = p1 * 100;
	Points[i][1] = p2 * 100;
  }
  for(int i = 0 ; i < N ; ++i){
	for(int j = i+1 ; j < N ; ++j){
	  PQ.push({
		  .from = i,
		  .to = j,
		  .cost = sqrt(
			  pow( Points[i][0] - Points[j][0], 2) +
			  pow( Points[i][1] - Points[j][1], 2) )
		  });
	}
  }
  double ans = 0;
  while(!PQ.empty()){
	int from = PQ.top().from;
	int to = PQ.top().to;
	double cost = PQ.top().cost;
	PQ.pop();
	if(find(from) == find(to)) continue;
	merge(from, to);
	ans += cost;
  }
  cout << ans / 100;
  return 0;
}
