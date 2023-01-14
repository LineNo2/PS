#include <stdio.h>
int main(){
  int n, temp=0;
  scanf("%d",&n);
  for(int i = n/5 ; i >= 0 ; --i){
	if( (temp = ( n - ( 5 * i ) ) ) % 3 ) continue;
	else {printf("%d", i + temp/3); return 0;}
  }
  printf("-1");
  return 0;
}
