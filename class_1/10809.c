#include <stdio.h>
#include <string.h>
int main() {
  int alpha_pos_arr[26];
  char temp_char;
  memset(alpha_pos_arr, -1, sizeof(alpha_pos_arr));
  for(int pos = 0;temp_char = getchar(), temp_char != '\n';++pos)
	if(alpha_pos_arr[temp_char - 97] == -1)
		alpha_pos_arr[temp_char - 97] = pos;
  for(int i = 0 ; i < 26 ; ++i) 
	printf("%d ", alpha_pos_arr[i]);
  return 0;
}

