#include <stdio.h>
int pow(int n){
  return n*n;
}
int main(){
  int a,b,c;
  for(;;){
	scanf("%d %d %d",&a ,&b, &c);
	if(a == 0 && b == 0 && c == 0) return 0;
	if(pow(a) + pow(b) == pow(c) ||
		pow(a) + pow(c) == pow(b) ||
		pow(b) + pow(c) == pow(a) )
	  printf("right\n");
	else
	  printf("wrong\n");
  }
}

