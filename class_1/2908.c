#include <stdio.h>

int rev_max(int a_, int b_){
  if(a_%10 == b_%10 && a_ !=0 )
	return rev_max(a_/10, b_/10);
  else 
	return a_%10 > b_%10;
}
void rev_print(int num_){
  if(num_ == 0)
	return;
  printf("%d",num_%10);
  rev_print(num_/10);
}

int main(){
  int num_a,num_b;
  scanf("%d %d", &num_a, &num_b);
  if(rev_max(num_a,num_b))
	rev_print(num_a);
  else
	rev_print(num_b);
  return 0;
}
