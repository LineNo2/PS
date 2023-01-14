#include <stdio.h>

int stack[55];
int level = -1;
int is_empty(){
  return level == -1;
}
void push(int n){
  stack[++level] = n;
}
int pop(){
  if(is_empty()) return -1;
  return stack[level--];
}

int main(){
  int n;
  int flag;
  char temp;
  scanf("%d\n",&n);
  flag = 0;
  for(int i = 0 ; i < n; i++){
	for(;temp = getchar(), temp != '\n';){
	  if(temp == '(') push(1);
	  else if(temp == ')'){
		if(pop() == -1) {
		  flag = 1;
		}
	  }
	}
	if(is_empty() && flag == 0)
	  printf("YES\n");
	else
	  printf("NO\n");
	flag = 0;
	level = -1;
  }
  return 0;
}

