#include <stdio.h>

int main(){
  int n, m, provided_blocks;
  int exist_blocks = 0;
  int blocK_height_arr[250001];
  int temp;
  int max_height;
  int answer_height, min_time =987654321;

  scanf("%d %d %d",&n, &m, &provided_blocks);
  for(int i = 0 ; i < n * m ; ++i){
	scanf("%d",&temp);
	blocK_height_arr[i] = temp;
	exist_blocks += temp;
  }
  temp =  (provided_blocks + exist_blocks);
  max_height = temp / (n * m);
  for(int height = max_height  ; height >= 0; --height){
	temp = 0;
	for(int i = 0 ; i < n*m ; ++i){
	  temp +=  height - blocK_height_arr[i]  >= 0 ? height - blocK_height_arr[i] : (blocK_height_arr[i] - height) * 2;
	}
	if(min_time > temp){
	  min_time = temp;
	  answer_height = height;
	}
  }
  printf("%d %d", min_time, answer_height);
  return 0;
}
