#include <bits/stdc++.h>

using namespace std;

  double x[4];
  double y[4];
	double delta_x[2];
	double delta_y[2];
	double denominator, numerator;
	double  c1, c2;
	double  x_cross;

bool is_in(int target_x, int target_y, int st_x, int st_y, int ed_x, int ed_y){//x, y 둘다 수 
if(st_x > ed_x){swap(st_x,ed_x);}
if(st_y > ed_y){swap(st_y,ed_y);}
  return ( st_x <= target_x && target_x <= ed_x )
	&& st_y <= target_y && target_y <= ed_y;
}

int main(){

  bool ans = false;
  for(int i =0  ; i< 4 ; ++i)
	cin >> x[i] >> y[i];
  if( ( (x[0] == x[2] ) && (y[0] == y[2]) )||
	  ( (x[0] == x[3] ) && (y[0] == y[3]) ) ||
	  ( (x[1] == x[2] ) && (y[1] == y[2]) ) ||
	  ( (x[1] == x[3] ) && (y[1] == y[3]) ) ){
	cout << 1;
	return 0;
  }
  delta_x[0] = x[1] - x[0];
  delta_x[1] = x[3] - x[2];
  delta_y[0] = y[1] - y[0];
  delta_y[1] = y[3] - y[2];
  
  denominator = (y[2] - y[0]) * delta_x[0] * delta_x[1] 
	+ x[0] * delta_x[1] * delta_y[0] - x[2] * delta_x[0] * delta_y[1];
  numerator = delta_x[1] * delta_y[0] - delta_x[0] * delta_y[1];
  if(numerator == 0){ // keisan hukanou
	if(delta_x[1] == 0 && delta_x[0] == 0){ // two lines are vertical
		ans = (x[0] == x[2]) && 
		( is_in(y[0],y[2],y[3]) 
		|| is_in(y[1],y[2],y[3])
		|| is_in(y[2],y[0],y[1]) 
		|| is_in(y[3],y[0],y[1]) );
	}
	// one vertical, one horizontal or parrallel
	else if(delta_x[0] == 0 && delta_y[1] == 0){
		ans = is_in(x[0], x[2], x[3]) && is_in(y[2], y[0], y[1]);
	}
	else if(delta_x[1] == 0 && delta_y[0] == 0){
		ans = is_in(y[0], y[2], y[3]) && is_in(x[2], x[0], x[1]);
	} 
	// both horizontal
	else if(delta_y[0] == 0 && delta_y[1] == 0){
		ans = (y[0] == y[2]) && 
		( is_in(x[0],x[2],x[3]) 
		|| is_in(x[1],x[2],x[3])
		|| is_in(x[2],x[0],x[1]) 
		|| is_in(x[3],x[0],x[1]) );
	}
	else{ 
		c1 = ( y[0] * delta_x[0] - x[0] * delta_y[0] ) * delta_x[1] ;
    c2 = ( y[2] * delta_x[1] - x[2] * delta_y[1] ) * delta_x[0] ;
		ans = (c1 == c2) && ( 
			is_in(x[0],x[2],x[3]) 
	    || is_in(x[1],x[2],x[3])
		  || is_in(x[2],x[0],x[1]) 
			|| is_in(x[3],x[0],x[1]) );
	}
	}
  else{
  x_cross = denominator / numerator ;
  //printf("%lfd/%lfd -> x_cross : %lf",denominator,numerator,x_cross);
	ans = ( 
		is_in(x_cross, x[0], x[1]) &&
		is_in(x_cross, x[2], x[3]) );
  }
  cout << ans;
  return 0;
}
