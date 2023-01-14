#include <bits/stdc++.h>
#define N_MAX 100001

using namespace std;

typedef struct Point{
  long long x, y;
  Point operator - (Point &p){
	return {.x = x - p.x , .y = y - p. y};
  }
  bool operator < (const Point &p) const{
  if(p.y * x == p.x * y){
	  return pow(x,2) + pow(y,2) < pow(p.x,2) + pow(p.y,2);
	}
	return p.y * x > p.x * y;
  }
  bool operator == (const Point &p) const{
	return x == p.x && y == p.y;
  }
}Point;

int N;

long long ccw(Point p1, Point p2, Point p3){
  long long value = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
  if(value > 0) return 1;
  if(value == 0) return 0;
  return -1;
}

vector<Point> Points;
vector<Point> Sorted_Points;

stack<Point> S;

int main(){
  int min_y, min_x, min_idx;
  int x, y;
  Point p_min;
  cin >> N;
  cin >> min_x >> min_y;
  Points.push_back({.x = min_x, .y = min_y});
  for(int i = 1 ; i < N ; ++i){
	cin >> x >> y;
	if(min_y >= y){
	  if(min_y == y) min_x = min(min_x, x);
    else { 
      min_y = y;
      min_x = min(40001, x);
    }
	}
	Points.push_back({.x = x, .y = y});
  }
  p_min = {.x = min_x , .y = min_y};;
  for(int i = 0 ; i < N ; ++i){
	if( p_min == Points[i] ) continue;
	Sorted_Points.push_back(Points[i] - p_min);
  }
  sort(Sorted_Points.begin(), Sorted_Points.end());
  p_min.x = 0;
  p_min.y = 0;
  S.push(p_min);
  S.push(Sorted_Points[0]);
  for(int i = 1 ; i < N-1 ; ++i){
	while(S.size() >= 2){
	  Point p2 = S.top();
	  S.pop();
	  Point p1 = S.top();
	  if(ccw(p1,p2,Sorted_Points[i]) > 0){
		S.push(p2);
		break;
	  }
	}
	S.push(Sorted_Points[i]);
  }
  int ans = 0;
  while(!S.empty()){
	S.pop();
	++ans;
  }
  cout << ans;
  return 0;
}
