#include <iostream>
#include <queue>

int arr[101][101][101];
//bool is_visited[1001][1001];
int x_max, y_max, z_max;

typedef struct Pos{
  int x;
  int y;
  int z;
}Pos;

std::queue<Pos> q;

void print_arr(){
  int flag = 0;
  for(int k = 0 ; k < z_max ;++k){
  for(int i = 0 ; i < y_max ; ++i){
	for(int j = 0 ; j < x_max ; ++j){
	  printf("%d ",arr[k][j][i]);
	}
	printf("\n");
  }
  printf("\n");
}
}

Pos oper[6] = { 
	{.x = 1, .y = 0, .z = 0}, 
	{.x = -1, .y = 0, .z = 0}, 
	{.x = 0, .y = 1, .z = 0}, 
	{.x = 0, .y = -1, .z = 0},
	{.x = 0, .y = 0, .z = 1},
	{.x = 0, .y = 0, .z = -1}
};

int main(){
  Pos temp;
  int count = 0;
  int day;
  int tot_tom = 0, no_tom = 0;
	int temp_int;
  scanf("%d %d %d",&y_max,&x_max,&z_max);
  for(int h = 0 ; h < z_max ; ++h){
  for(int i = 0 ; i < x_max ; ++i){
	for(int j = 0 ; j < y_max ; ++j){
	  scanf("%d",&temp_int);
	  if(temp_int == -1) ++no_tom;
	  else if(temp_int == 1) {
			temp.x = i;
		  temp.y = j;
			temp.z = h;
		  ++count;
		  q.push(temp);
			++tot_tom;
		}
	  arr[h][i][j] = temp_int;
	}
  }
  }
	//여기서 걍 count를 세서 큐에 바로 담아버린다.
	if(q.empty()){
		printf("%d", ( (x_max * y_max * z_max) - no_tom ) == tot_tom ? day : -1);
		return 0;
	}
  Pos temp1, temp2;
  int temp_count;
  for(day = 0 ;; ++day){
	// print_arr();
	temp_count = 0;
  	for(int i = 0 ; i < count ; ++i){
		temp1 = q.front();
		arr[temp1.z][temp1.x][temp1.y] = 2;
		q.pop();
		for(int j = 0 ; j < 6 ; ++j){
			temp2.x = temp1.x - oper[j].x;
			temp2.y = temp1.y - oper[j].y;
			temp2.z = temp1.z - oper[j].z;
			if(temp2.x < 0 || temp2.y < 0 || temp2.z < 0) continue;
			if(temp2.x >= x_max || temp2.y >= y_max || temp2.z >= z_max) continue;
			if(arr[temp2.z][temp2.x][temp2.y] == 0){
			arr[temp2.z][temp2.x][temp2.y] = 1;
			q.push(temp2);
			++temp_count;
			++tot_tom;
		  }
		}
		}
		if(q.empty()) break;
		count = temp_count;
  }
  printf("%d", ( (x_max * y_max * z_max) - no_tom ) == tot_tom ? day : -1);
  return 0;
}


