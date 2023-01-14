#include <stdio.h>

typedef struct Oper{
  int x;
  int y;
}Oper;

Oper operators[5][4] = { 
   { { .x = 0, .y = 0  }, { .x = 1 , .y = 0  }, { .x = 0, .y = 1 }, { .x = 1, .y = 1 } }, // 0
   { { .x = 0, .y = 0  }, { .x = 1 , .y = 0  }, { .x = 2, .y = 0 }, { .x = 3, .y = 0 } }, // 1
   { { .x = 0, .y = 0  }, { .x = 1 , .y = 0  }, { .x = 2, .y = 0 }, { .x = 0, .y = 1 } }, // ㄴ 
   { { .x = 0, .y = 0  }, { .x = 1 , .y = 0  }, { .x = 2, .y = 0 }, { .x = 1, .y = 1 } }, // ㅗ
   { { .x = 0, .y = 0  }, { .x = 0 , .y = 1  }, { .x = 1, .y = 1 }, { .x = 1, .y = 2 } }, // S
};

int arr[510][510];
int n, m;

int get_sum(int x, int y, int symmetry, int rotate, int type){
  int sum = 0;
  int temp_x, temp_y;
  int temp;
  for(int i = 0 ; i < 4; ++i){
	temp_x = operators[type][i].x;
	temp_y = operators[type][i].y;
	switch(rotate){
	  case 0:
		break;
	  case 1:
		temp_x *= (-1);
		break;
	  case 2:
		temp_y *= (-1);
		break;
	  case 3:
		temp_x *= (-1);
		temp_y *= (-1);
		break;
	}
	switch(symmetry){
	  case 0:
		break;
	  case 1:
		temp = temp_x;
		temp_x = temp_y;
		temp_y = temp;
		break;
	}
	temp_x += x;
	temp_y += y;
	if( temp_x < 0 || temp_y < 0 || temp_x >= n || temp_y >= m) return -1;
	sum += arr[temp_x][temp_y];
  }
  return sum;
}


int main(){
  int max = 0;
  int temp;
  scanf("%d %d", &n, &m);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < m ; ++j){
	  scanf("%d",&arr[i][j]);
	}
  }
 for(int type = 0 ; type <= 4 ; ++type){
 for(int symmetry = 0 ; symmetry <= 1 ; ++symmetry){
 for(int rotate = 0 ; rotate <= 3; ++rotate){
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < m ; ++j){
	  temp = get_sum(i,j,symmetry,rotate,type);
		// printf("get_sum(%d,%d,%d,%d,%d) = %d\n",i,j,symmetry,rotate,type, temp) ;
	  if(temp > max)
		max = temp;
	}
  }
  }
  }
  }
 printf("%d",max);
  return 0;
}
