#include <stdio.h>
int main(){
  int temp_a,temp_b;
  for(;scanf("%d %d",&temp_a, &temp_b), temp_a !=0 && temp_b !=0;)
	printf("%d\n",temp_a+temp_b);
  return 0;
}

