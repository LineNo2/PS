#include <stdio.h>
int main() {
  int temp, max=-1, index_max;
  for(int i = 0 ; i < 9 ; i++){
	scanf("%d", &temp);
	if(max < temp)
	  max = temp, index_max = i + 1;
  }
  printf("%d\n%d", max, index_max);
  return 0;
}
