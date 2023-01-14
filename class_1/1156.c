#include <stdio.h>
#include <string.h>

int retCharCode(int alphabet){
  if(alphabet <= 90) return alphabet - 65;
  else return alphabet - 97;
}


int main() {
  char str[1000100];
  int dict[27], max_cnt=0, max_alpha=0,dupflag=0;
  scanf("%s",str);
  for(int i = 0 ;i<strlen(str);i++){
	++dict[retCharCode(str[i])];
  }
  for(int i = 0; i < 26; i++){
	if( max_cnt < dict[i] ) { max_cnt = dict[i]; max_alpha=i; dupflag = 0;}
	else if(max_cnt == dict[i]) dupflag = 1;
  }
  printf("%c",dupflag ? '?' : max_alpha+65);
  return 0;
}


