#include <stdio.h>
int main(){
  int total_repeat;
  int total_score = 0 ;
  char temp_answer;
  scanf("%d",&total_repeat);
  getchar();
  for(int i = 0 ; i < total_repeat; ++i){
	for(int streak = 1 ; temp_answer = getchar(), temp_answer != '\n' ;){
	  if(temp_answer == 'O')
		total_score += streak++;
	  else
		streak =  1;
	}
  printf("%d\n",total_score);
  total_score = 0;
  }
  return 0;
}


