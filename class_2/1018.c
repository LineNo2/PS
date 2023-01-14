#include <stdio.h>
int map_arr[51][51];
int temp_map_arr[8][8];
int paint_checker(int color_of_first_){
  int sum_of_value;
  if(temp_map_arr[0][0] == color_of_first_)
	sum_of_value = 0;
  else sum_of_value = 1;
  temp_map_arr[0][0] = color_of_first_;
  for(int i = 0 ; i < 8 ; ++i){
	for(int j = 0 ; j < 8 ; ++j){
	  if(j == 0){
		if(i > 0){
		  if(temp_map_arr[i][j] == temp_map_arr[i-1][j]){
			if(temp_map_arr[i][j] == 1)
			  temp_map_arr[i][j] = 0;
			else
			  temp_map_arr[i][j] = 1;
			++sum_of_value;
		  }
		}
	  }
	  else{
		if(temp_map_arr[i][j] == temp_map_arr[i][j-1]){
			if(temp_map_arr[i][j] == 1)
			  temp_map_arr[i][j] = 0;
			else
			  temp_map_arr[i][j] = 1;
			++sum_of_value;
		}
	  }
	}
  }
  return sum_of_value;
}
int main(){
  int pos_x, pos_y;
  int min_value=64;
  int temp_int;
  char temp_char;
  scanf("%d %d\n",&pos_x, &pos_y);
  for(int i = 0 ; i < pos_x; ++i){
	for(int j = 0 ; j < pos_y; ++j){
	  temp_char = getchar();
	  map_arr[i][j] = temp_char == 'B' ? 0 : 1; //Black -> 0, White -> 1
	}
	getchar();
  }
for(int i = 0 ; i <= pos_x - 8; ++i){
  for(int j = 0 ; j <= pos_y - 8; ++j){
	for(int k = 0 ; k < 8 ; ++k){
	  for(int l = 0 ; l < 8 ; ++l){
		temp_map_arr[k][l] = map_arr[i+k][j+l];
	  }
	}
	min_value = min_value > (temp_int = paint_checker(0)) ? temp_int : min_value;
	for(int k = 0 ; k < 8 ; ++k){
	  for(int l = 0 ; l < 8 ; ++l){
		temp_map_arr[k][l] = map_arr[i+k][j+l];
	  }
	}
	min_value = min_value > (temp_int = paint_checker(1)) ? temp_int : min_value;
  }
}
printf("%d", min_value);
return 0;
}



