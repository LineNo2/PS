#include <stdio.h>
int main() {
  int temp;
  int total_scores=0, num_of_scores, max_score=-1;
  scanf("%d", &num_of_scores);
  for(int i =0; i<num_of_scores ; ++i){
	scanf("%d",&temp);
	if(max_score < temp)
	  max_score = temp;
	total_scores += temp;
  }
  printf("%.3f",(double)(total_scores*100)/(max_score*num_of_scores));
  return 0;
}
