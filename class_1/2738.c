#include <stdio.h>
int main(){
  int key_num;
  scanf("%d",&key_num);
  for(int i = 1 ; i <= 9 ; ++i)
	printf("%d * %d = %d\n", key_num, i, key_num*i);
  return 0;
}
