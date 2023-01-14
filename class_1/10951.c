#include <stdio.h>
int main(){
  int temp_a, temp_b;
  for(;scanf("%d %d",&temp_a, &temp_b) != EOF;){
    printf("%d\n",temp_a + temp_b);
  }
  return 0;
}

