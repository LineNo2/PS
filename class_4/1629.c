#include <stdio.h>
long long operation(int a, int b, int c){
  if(b == 0){
	return 1;
  }
  else if(b % 2 == 0){
	long long temp = operation(a,(b/2),c) % c;
	return (temp*temp)%c;
  }
  else{
	long long temp = operation(a, (b/2),c) %c;
	return (((temp*temp)%c)*a)%c;
	}
}

int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  printf("%d",operation(a,b,c));
return 0;
}
