#include <stdio.h>
int stack[100010];
int level = -1;
void push(int n){
  stack[++level] = n;
}
int pop(){
  return stack[level--];
}
int is_empty(){
  return level == -1;
}
int main() {
  int n;
  int temp;
  long long sum;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d",&temp);
	if(temp == 0)
	  pop();
	else
	  push(temp);
  }
  sum = 0;
  for(;is_empty() == 0;){
	sum += pop();
  }
  printf("%lld",sum);

  return 0;
}
