#include <stdio.h>
#include <string.h>

int stack[220];
int level = -1;
int is_empty(){
  return  level == -1 ;
}
void push(int type){
  stack[++level] = type;
}
int pop(){
  if(is_empty()) return -1;
  return stack[level--];
}
void clear_stack(){
  level = -1;
}
  
int main(){
  int flag;
  char temp;
  for(;;){
	flag = 0 ;
	temp = getchar();
	if( temp == '.' ) return 0;
	for(;;){
	  switch(temp){
	  case '(':
		push(1);
		break;
	  case ')':
		if(pop() != 1) flag = 1;
		break;
	  case '[':
		push(2);
		break;
	  case ']':
		if(pop() != 2) flag = 1;
		break;
	  }
	  temp = getchar();
	  if(temp == '.') {
		printf("%s\n", is_empty() && flag == 0 ? "yes" : "no"); 
		getchar(); 
		clear_stack();
		break;
	  }
	}
  }
}

