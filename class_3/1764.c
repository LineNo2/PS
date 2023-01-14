#include <stdio.h>
int main(){
  int h, s;
  char h_arr[500000][20];
  char s_arr[500000][20];
  scanf("%d %d",&h, &s);
  for(int i = 0 ; i < h ; ++i)
	scanf("%d",&h_arr[i][0]);
  for(int i = 0 ; i < s ; ++i)
	scanf("%d",&s_arr[i][0]);


