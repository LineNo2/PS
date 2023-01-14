#include <bits/stdc++.h>
#define MAX_STUDENTS 32001

using namespace std;

int N, M;

vector<int> Rules[MAX_STUDENTS];
bool is_visited[MAX_STUDENTS];

bool check_empty(vector<int> idx){
  for(int i = 0 ; i < idx.size() ; ++i){
	if(is_visited[idx[i]]) continue;
	return false;
  }
  return true;
}

void find_rule(int idx){
  if(is_visited[idx]) return;
  for(int i = 0 ; i< Rules[idx].size(); ++i){
	find_rule(Rules[idx][i]);
  }
  is_visited[idx] = true;
	cout << idx <<" ";
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int from, to;
  cin >> N >> M;
  for(int i = 0 ; i < M ; ++i){
	cin >> from >> to;
	Rules[to].push_back(from);
  }
  for(int i = 1 ; i <= N ; ++i)
	find_rule(i);
  return 0;
}
