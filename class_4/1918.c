#include <stdio.h>
#include <string.h>

char stack_num[101];
int level_num = -1;

void push_num(char a){
  stack_num[++level_num] = a;
}
int is_empty_num(){
  return level_num == -1;
}
char pop_num(){
  if(is_empty_num()) return 0;
  return stack_num[level_num--];
}
char front_num(){
	return stack_num[level_num];
}

char stack_oper[101];
int level_oper = -1;

void push_oper(char a){
  stack_oper[++level_oper] = a;
}
int is_empty_oper(){
  return level_oper == -1;
}
char pop_oper(){
  if(is_empty_oper()) return 0;
  return stack_oper[level_oper--];
}
char front_oper(){
	return stack_oper[level_oper];
}

char stack_oper_priority[101];
int level_oper_priority = -1;

void push_oper_priority(char a){
  stack_oper_priority[++level_oper_priority] = a;
}
int is_empty_oper_priority(){
  return level_oper_priority == -1;
}
char pop_oper_priority(){
  if(is_empty_oper_priority()) return 0;
  return stack_oper_priority[level_oper_priority--];
}
char front_oper_priority(){
	return stack_oper_priority[level_oper_priority];
}

// +, - -> 1, *, / -> 2, (+,-) -> 3, (*,/) -> 4
int main(){
  char temp;
	char ans[102] = {0,};
  int flag;
  temp = getchar();
  flag = 0;
  while(temp!='\n'){
	switch(temp){
	  case '(':
		++flag;
		break;
	  case ')':
		--flag;
		break;
	  case '+':
	  case '-':
		if(flag > 0){
			push_oper_priority(100+flag);
		}else{
			push_oper_priority(1);
		}
		push_oper(temp);
		break;
		case '*':
		case '/':
		if(flag > 0){
			push_oper_priority(10+flag);
		}else{
			push_oper_priority(2);
		}
		push_oper(temp);
		break;
		default:
		push_num(temp);
	}
	temp = getchar();
	}
	int ans_index = 100;
	flag = 0;
	int temp_prioirty = 0;
	int temp_index = 0;
	while(is_empty_oper_priority() == 0){
		if(flag == 1){
			for(int i = temp_index - 1; i >= 0 ; --i){
				ans[ans_index - i] = pop_oper();
			}
			ans_index -= temp_index;
			for(int i = 0 ; i < temp_index ; ++i){
				ans[ans_index - i ] = pop_num();
			}
			ans_index -= temp_index;
			temp_index = 0;
			flag = 0;
		}
		temp_prioirty = pop_oper_priority();
		++temp_index;
		if(temp_prioirty < front_oper_priority()){
			flag = 1;		
		}
	}
	for(int i = temp_index - 1; i >= 0 ; --i){
				ans[ans_index - i] = pop_oper();
			}
			ans_index -= temp_index;
			for(int i = 0 ; i < temp_index ; ++i){
				ans[ans_index - i ] = pop_num();
			}
			ans_index -= temp_index;
		ans[ans_index] = pop_num();
		ans[101] = '\0';
		printf("%s",&ans[ans_index]);
	return 0;

  }
  
