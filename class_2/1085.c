#include <stdio.h>
int main(){
  int x,y,w,h;
  int min = 1001;
  scanf("%d %d %d %d",&x,&y,&w,&h);
  min = min > x ? x : min;
  min = min > y ? y : min;
  min = min > w-x ? w-x : min;
  min = min > h-y ? h-y : min;
  printf("%d",min);
  return 0;
}
