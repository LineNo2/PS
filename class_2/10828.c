#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[10010];
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

int top(){
  if(is_empty()) return -1;
  return stack[level];
}

int size(){
  return level + 1;
}

int main(){
  char input[20];
  char *ptr;
  int n;
  int temp;
  scanf("%d\n",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%s", &input[0]);
	if(strcmp(input,"push") == 0){
	  scanf("%d\n", &temp);
	  push(temp);
	}
	else if(strcmp(input, "top") == 0)
	  printf("%d\n", top());
	else if(strcmp(input, "size") == 0)
	  printf("%d\n", size());
	else if(strcmp(input, "empty") == 0)
	  printf("%d\n", is_empty());
	else if(strcmp(input, "pop") == 0)
	  printf("%d\n", pop());
  }
  return 0;
}

