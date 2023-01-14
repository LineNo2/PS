#include <stdio.h>
#include <string.h>

int main() {
  char str[1100000];
  int cnt = 0;
  scanf("%[^\n]s", str);
  if(str[0] == ' ' && strlen(str)==1) {printf("0");
	return 0;}
  for(int i = 1 ; i<strlen(str)-1; i++)
	if(str[i] == ' ') cnt++;
  printf("%d", cnt+1);
  
  return 0;
}
