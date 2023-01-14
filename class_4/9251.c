#include <stdio.h>
#include <string.h>
#define MAX 1000

char s1[MAX], s2[MAX];
int max = 0;
int s1_len, s2_len;

/*int backtrack(char *lcs, int lcs_len, char add_char, int s1_st, int s2_st){
  strcat(lcs + lcs_len, add_char);
}*/
void backtrack(char key, int s1_st, char *s2_ptr, int count){
  char *ptr = strchr(s2_ptr, key);
  // printf("f(%c,%d,%s,%d)\n",key,s1_st,s2_ptr,count);
  while(ptr != NULL){
	for(int i = s1_st + 1 ; i < s1_len ; ++i){
	  backtrack(s1[i], i, ptr + 1, count + 1);
	}
	ptr = strchr(ptr + 1, key);
  }
  if(count > max ) max = count;
  return ;
}

int main(){
  char temp[MAX];
  scanf("%s\n%s",s1,temp);
  if(strlen(s1) <= strlen(temp)) strcpy(s2, temp);
  else { strcpy(s2,s1); strcpy(s1,temp); }
  s1_len = strlen(s1);
  s2_len = strlen(s2);
  for(int i = 0 ; i< s1_len ; ++i)
    backtrack(s1[i], i, s2, 0);
  printf("%d",max);
  return 0;
}
