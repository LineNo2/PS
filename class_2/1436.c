#include <stdio.h>
#include <string.h>
int main(){
  int n, result;
  char temp[12];
  scanf("%d",&n);
  for(int count = 0, i = 666 ;;i++){
	sprintf(temp, "%d",i);
	if(strstr(temp, "666")) count++;
	if( count == n ){ result = i; break;} 
  }
  printf("%d",result);
  return 0;
}
  
	
