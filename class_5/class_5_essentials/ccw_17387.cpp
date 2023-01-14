#include <bits/stdc++.h>

using namespace std;

typedef struct Point{
  long long x, y;
  bool operator == (const Point &p) const{
	return x == p.x && y == p.y;
  }
}Point;


int ccw(Point p1, Point p2, Point p3){
  long long result = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
  if(result > 0) return 1;
  if(result < 0) return -1;
  return 0;
}

bool is_in(Point target, Point  st, Point ed){//x, y 둘다 수 
int st_x = st.x, st_y= st.y, ed_x = ed.x, ed_y= ed.y;
if(st.x > ed.x){st_x = ed.x; ed_x = st.x;}
if(st.y > ed.y){st_y = ed.y; ed_y = st.y;}
  return ( st_x <= target.x && target.x <= ed_x )
	&& st_y <= target.y && target.y <= ed_y;
}

int main(){
  Point p[4];
  int ccw_1, ccw_2;
  bool ans = false;
  for(int i =0  ; i < 4 ;++i)
	cin >> p[i].x >> p[i].y;
  if(p[0] == p[2] || p[0] == p[3] || p[1] == p[2] || p[1] == p[3]){
	cout << 1;
	return 0;
  }
  if(p[0] == p[1]){
    swap(p[0],p[2]);
    swap(p[1],p[3]);
  }
  ccw_1 = ccw(p[0],p[1],p[2]);
  ccw_2 = ccw(p[0],p[1],p[3]);
  // cout << ccw_1 << endl << ccw_2;
  if( ccw_1 * ccw_2 < 0){ // 나머지 선분에 대한 ccw 점검
	  swap(p[0], p[2]);
	  swap(p[1], p[3]);
    ccw_1 = ccw(p[0],p[1],p[2]);
    ccw_2 = ccw(p[0],p[1],p[3]);
  }else if(ccw_1 * ccw_2 > 0){
    cout << 0;
    return 0;
  }
  if(ccw_1 == 0 && ccw_2 == 0){//both parrallel
	ans = is_in(p[0],p[2],p[3]) ||
	  is_in(p[1],p[2],p[3]) ||
	  is_in(p[2],p[0],p[1]) || 
	  is_in(p[3],p[0],p[1]);
  }
  else if(ccw_1 == 0){ // p0, p1, p2가 한 직선 위에 있음
	ans = is_in(p[2],p[0],p[1]);
  }
  else if(ccw_2 == 0){ // p0, p1, p3가 한 직선 위에 있음
	ans = is_in(p[3],p[0],p[1]);
  }
  else if( ccw_1 * ccw_2 > 0){
	ans = false;
  }
  else{
	ans = true;
  }
  cout << ans;
  return 0;
}



