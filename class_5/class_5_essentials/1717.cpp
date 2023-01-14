#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NODE 1000001
#define MAX_EDGE 100001

using namespace std;

int N, M;

int parent[MAX_NODE];
int cnt[MAX_NODE];


int find(int elem){
  if (parent[elem] == elem) return elem;
  return parent[elem] = find(parent[elem]);
}

int is_in(int a, int b){
  return find(a) == find(b);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  if(cnt[a] > cnt[b]){
	cnt[a] += cnt[b];
	parent[b] = a;
  }
  else{
	cnt[b] += cnt[a];
	parent[a] = b;
  }
}

int main(){
  int oper, a, b;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  //init
  cin >> N >> M;
  for(int i = 0 ; i <= N ; ++i){
	parent[i] = i;
	cnt[i] = 1;
  }
  for(int i = 0 ; i < M ; ++i){
	cin >> oper >> a >> b;
	switch(oper){
	  case 0:
		merge(a,b);
		break;
	  case 1:
		if(is_in(a,b))
		  cout << "YES\n";
		else
		  cout << "NO\n";
		break;
	}
  }
  return 0;
}

  
