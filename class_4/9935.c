#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000000
#define MAX_LEN_BOMB 36

typedef struct Func_Result{
  char* ptr_st;
	char* ptr_ed;
  int flag;
}Func_Result;

char str[MAX_LEN];
int str_len;
char *next_str[MAX_LEN];
char bomb_str[MAX_LEN_BOMB];
int bomb_len;

Func_Result compare_bomb(char* ptr_original){
	int bomb_idx = 0;
	char* ptr;
	for(ptr = ptr_original ; bomb_idx < bomb_len ; ++ptr ){
		// (*ptr) == '\0' <- 이거 좀 위험한 조건인거같음.
		if((*ptr) == bomb_str[bomb_idx]) {++bomb_idx; continue;}
		else if((*ptr) == bomb_str[0]) return compare_bomb(ptr);
		else if((*ptr) == '!') ptr = next_str[ptr - str];
		else return (Func_Result){.ptr_st = ptr, .ptr_ed = ptr, .flag = 0};
	}
  return (Func_Result){.ptr_st = ptr_original, .ptr_ed = ptr, .flag = 1}; 
	// 리턴할떄 ptr_original으로 해주면 bomb 문자열의 시작점을 알수있다!

}

int main(){
  Func_Result temp;
  int count;
	int flag = 0;
  scanf("%s %s",str, bomb_str);
  str_len = strlen(str);
  bomb_len = strlen(bomb_str);
  
	for(char *ptr = str ;(*ptr) != '\0'; ++ptr){
	  if((*ptr) == bomb_str[0]){
		temp = compare_bomb(ptr);
		if(temp.flag == 1){ // bomb
		  (*temp.ptr_st) = '!';
		  next_str[temp.ptr_st - str] = temp.ptr_ed - 1;
			ptr = temp.ptr_st - 2;
			if(ptr - str == -2 )
			ptr = next_str[0];
		}
		else ptr = temp.ptr_ed; // jump
	  }
	  else if((*ptr) == '!')
		ptr = next_str[ptr - str];
	}

  for(char *ptr = str; (*ptr) != '\0'; ++ptr){
		if(*ptr == '!') ptr = next_str[ptr - str];
		else{
		printf("%c",*ptr);
		flag = 1;
		}
	}
	if(flag == 0) printf("FRULA");
  return 0;
}
  


