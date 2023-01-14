#include <stdio.h>
#include <string.h>
int stack[100010];
int level = 0;

void push(int elem) {
  stack[++level] = elem;
}
int pop(){
  return stack[level--];
}

int main(){
  char result_str[200010] = "";
  int n;
  int req_stack[100010];
  int last_int = 1;
  int len = 0;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; ++i){
	scanf("%d",&req_stack[i]);
  }
  for(int i = 1 ; i <= n ; ++i){
	for(int j = last_int ; j <= req_stack[i] ; ++j){
		push(j);
		strcat(result_str + len,"+\n");
    len += 2;
	}
	if(last_int <= req_stack[i]) last_int = req_stack[i] + 1;
	if(req_stack[i] == pop()){
	  strcat(result_str + len,"-\n");
    len += 2;
	}
	else{
	  printf("NO");
	  return 0;
	}
  }
  printf("%s",result_str);
  return 0;
}
