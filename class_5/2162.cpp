#include <bits/stdc++.h>
#define N_MAX 3001

using namespace std;

typedef struct Point{
  int x;
  int y;
  bool operator <= (const Point &p) const{
	return x == p.x ? y <= p.y : x < p.x;
  }
}Point;

int ccw(Point p1, Point p2, Point p3){
  long long temp = (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);
  if(temp > 0) return 1;
  if(temp < 0) return -1;
  return 0;
}

int N;

int root[N_MAX];

int elem_count[N_MAX];

bool is_checked[N_MAX];

int find(int n){
  if(n == root[n]) return n;
  return root[n] = find(root[n]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  if(b < a) swap(a,b);
  if(elem_count[a] < elem_count[b]) swap(a,b);
  root[b] = a;
  elem_count[a] += elem_count[b];
  elem_count[b] = 0;
}

bool is_intersect(Point P0, Point P1, Point P2, Point P3){
  int ccw_1 = ccw(P0, P1, P2) * ccw(P0, P1, P3);
  int ccw_2 = ccw(P2, P3, P0) * ccw(P2, P3, P1);
  if( ccw_1 == 0 && ccw_2 == 0){
	if(P1 <= P0) swap(P1, P0);
	if(P3 <= P2) swap(P2, P3);
	return P2 <= P1;
  }
  else if( ccw_1 <= 0 && ccw_2 <= 0)
	return true;
  else
	return false;
}


Point P[N_MAX][2];

int main() {
  cin >> N;
  for(int i = 1 ; i <= N ; ++i){
	cin >> P[i][0].x >> P[i][0].y >> P[i][1].x >> P[i][1].y;
	root[i] = i;
  elem_count[i] = 1;
  }
  for(int i = 1 ; i <= N ; ++i){
	for(int j = i + 1; j <= N ; ++j){
	  if(!is_intersect(P[i][0], P[i][1], P[j][0], P[j][1])) continue;
	  merge(i,j);
	}
  }
  int cnt = 0, ans = 0;
  for(int i = 1 ; i <= N ; ++i){
	if(root[i] != i) continue;
	++cnt;
	ans = max(elem_count[i], ans);
  }
  cout << cnt << endl << ans;
  return 0;
}


