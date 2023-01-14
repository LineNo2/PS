#include <stdio.h>
#include <string.h>

int set[21];

int main(){
  int n;
  char inst[10];
  int temp;
  scanf("%d",&n);
  for(int i = 0 ; i < n ;++i){
	scanf("%s",&inst[0]);
	if(strcmp(inst, "add") == 0){
	scanf("%d",&temp);
	set[temp] = 1;
	}
	else if(strcmp(inst, "check") == 0){
	  scanf("%d",&temp);
	  printf("%d\n",set[temp]);
	}
	else if(strcmp(inst, "remove") == 0){
	  scanf("%d",&temp);
	  set[temp] = 0;
	}
	else if(strcmp(inst, "toggle") == 0){
	  scanf("%d",&temp);
	  if(set[temp]) set[temp] = 0;
	  else set[temp] = 1;
	}
	else if(strcmp(inst, "all") == 0){
	  for(int s = 1 ; s <= 20 ; s++)
		set[s] = 1;
	}
	else if(strcmp(inst, "empty") == 0){
	  for(int s = 1 ; s <= 20 ; s++)
		set[s] = 0;
	}
  }
  return 0;

}
