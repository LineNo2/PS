#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

typedef struct Edge{
  int from;
  int to;
  int cost;
}Edge;

int n, m, w;

vector<Edge> E;
vector<int> D;

void is_reversible(){
  int from_ , to_ , cost_;
  D[1] = 0;
  for(int i = 0 ; i < n - 1 ; ++i){
		for(int edge = 0 ; edge < E.size() ; ++edge){
	  	from_ = E[edge].from;
	  	to_ = E[edge].to;
	  	cost_ = E[edge].cost;
	  	if(D[from_] == INF) continue;
	  	if(D[to_] > D[from_] + cost_) D[to_] = D[from_] + cost_;
		}
	}
	for(int edge = 0 ; edge < E.size() ; ++edge){
	from_ = E[edge].from;
	to_ = E[edge].to;
	cost_ = E[edge].cost;
	if(D[from_] == INF) continue;
	if(D[to_] > D[from_] + cost_){
	  cout << "YES\n";
		return;
	}
	}
	cout << "NO\n";
	// for(int i = 1 ; i<= n ; ++i){
	// 	cout << D[i] <<"\t";
	// }
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
  int test_cases;
  int from, to, cost;
  cin >> test_cases;
  for(int i = 0; i < test_cases ; ++i){
	cin >> n >> m >> w;
	for(int j = 0 ; j < m ; ++j){
	  cin >> from >> to >> cost;
	  E.push_back({.from = from, .to = to, .cost = cost});
	  E.push_back({.from = to, .to = from, .cost = cost});
	}
	for(int j = 0 ; j < w ; ++j){
	  cin >> from >> to >> cost;
	  E.push_back({.from = from, .to = to, .cost = -cost});
	}
	D = vector<int>(n + 1, INF);
	is_reversible();
	E.clear();
  }
  return 0;
}
