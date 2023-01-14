#include <stdio.h>
#include <string.h>

void is_pali(char *num_){
  int string_length = strlen(num_);
  for(int i = 0 ; i < string_length ; ++i){
	if(num_[i] == num_[string_length - (1 + i)]) continue;
	printf("no\n");
	return;
  }
  printf("yes\n");
  return;
}

int main () {
  char num[6];
  for(;;){
	scanf("%s",num);
	if(strcmp(num, "0") == 0) return 0;
	is_pali(num);
  }
}
