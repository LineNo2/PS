#include <stdio.h>
#include <math.h>


int r, c;

int insertZ(int n, int start, int x, int y){
  if( n == 1){
	if(r == x && c == y) return start;
	if(r == x + 1 && c == y) return start + 1;
	if(r == x && c == y + 1) return start + 2;
	if(r == x + 1 && c == y + 1) return start + 3;
  }
  else{
	if( r <= x + pow(2,n-1) - 1  && c <= y + pow(2, n-1) - 1)
	return insertZ(n-1, start, x, y);
	else if( r <= x + pow(2,n) - 1&& c <= y + pow(2, n-1) - 1)
	return insertZ(n-1, start + pow(4,n) / 4, x + pow(2,n-1), y);
	else if( r <= x + pow(2, n-1) - 1 && c <= y + pow(2,n) - 1)
	return insertZ(n-1, start + pow(4,n) * 2 / 4 , x , y + pow(2,n-1));
	else
	return insertZ(n-1, start + pow(4,n) * 3 / 4 , x + pow(2, n-1) , y + pow(2,n-1));
  }
  return -1;
}

int main(){
  int n;
  scanf("%d %d %d",&n,&c,&r);
  printf("%d", insertZ(n ,0 ,0 ,0));
  return 0;
}
