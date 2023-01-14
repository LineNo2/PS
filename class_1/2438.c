#include <stdio.h>
int main(){
  int level;
  scanf("%d",&level);
  for(int i = 1; i <= level ; ++i){
	for(int j = 1 ; j <= i ; ++j)
	  printf("*");
	printf("\n");
  }
  return 0;
}

