#include <stdio.h>
#include <string.h>
int main() {
  int total_text,temp_repeat; 
  char temp_string[20];
  scanf("%d",&total_text);
  for(int i = 0; i < total_text ; ++i){
	scanf("%d %s", &temp_repeat,temp_string);
	for(int j = 0 ; j< strlen(temp_string);++j){
	  for(int k =  0 ; k < temp_repeat; ++k)
		printf("%c",temp_string[j]);
	}
	printf("\n");
  }
  return 0;
}

	

