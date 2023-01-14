#include <bits/stdc++.h>
#define MAX_N 100001

using namespace std;

int Orders[MAX_N];
int Groups[MAX_N];
bool is_valid[MAX_N];
bool is_visited[MAX_N];

int T;

int DFS(int cur, int length){
  int next = Orders[cur];
  if(is_visited[cur]) return MAX_N;
  if(Groups[cur] != 0) return Groups[cur];
  Groups[cur] = ++length;
  int return_DFS = DFS(next, length);
  is_visited[cur] = true;
  if( return_DFS <= length ){
	is_valid[cur] = true;
	return return_DFS;
  }
  return length;
}

int main(){
  int cur_group = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  for(int tc = 0 ; tc < T; ++tc){
	int n;
	int ans = 0;
	cur_group = 0;
	cin >> n;
	memset(is_valid, false, sizeof(is_valid));
	memset(is_visited, false, sizeof(is_visited));
	memset(Orders, 0, sizeof(Orders));
	memset(Groups, 0, sizeof(Groups));
	for(int i = 1 ; i <= n ; ++i)
	  cin >> Orders[i];
	for(int i = 1 ; i <= n ; ++i){
	  if(is_visited[i]) continue;
	  DFS(i, 0);
	}
	for(int i = 1 ; i <= n ; ++i)
	  if(!is_valid[i]) ++ans;
	cout << ans << endl;
  }
  return 0;
}

