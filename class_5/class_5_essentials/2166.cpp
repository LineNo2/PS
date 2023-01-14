#include <bits/stdc++.h>

using namespace std;

int N;

typedef struct Point{
  int x, y;
  bool operator < (const struct Point &p) const{
	return y * p.x == x * p.y ? x*x + y*y < p.x*p.x + p.y*p.y
	  : y * p.x < x * p.y;
  }
  Point operator + (struct Point &p) {
	return {.x = x + p.x , .y = y + p.y};
  }
}Point;

int get_surface(Point p[]){
  return abs( 
	  ( p[0].x * p[1].y + p[1].x * p[2].y + p[2].x * p[0].y ) 
	  - ( p[0].y * p[1].x + p[1].y * p[2].x + p[2].y * p[0].x ) );  
}

vector<Point> points;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int ans = 0;
  Point temp;
  Point p[3];
  p[0].x = 987654321;
  cin >> N;
  for(int i = 0 ; i < N ; ++i){
	cin >> temp.x >> temp.y;
	points.push_back(temp);
	if(p[0].x > temp.x) p[0] = temp;
  }
  sort(points.begin(), points.end());
  p[1] = points[0];
  for(int i = 1 ; i < points.size() ; ++i){
	p[2] = points[i];
	ans += get_surface(p);
	p[1] = p[2];
  }
  cout << fixed << setprecision(1);
  cout << (float)ans/2;
  return 0;
}
