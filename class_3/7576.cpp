#include <iostream>
#include <queue>

int arr[1001][1001];
//bool is_visited[1001][1001];
int x_max, y_max;

typedef struct Pos{
  int x;
  int y;
}Pos;

std::queue<Pos> q;

void print_arr(){
  int flag = 0;
  for(int i = 0 ; i < y_max ; ++i){
	for(int j = 0 ; j < x_max ; ++j){
	  printf("%d ",arr[j][i]);
	}
	printf("\n");
  }
  printf("\n");
}


int main(){
  Pos temp;
  int count = 0;
  int day;
  int tot_tom = 0, no_tom = 0;
	int temp_int;
  scanf("%d %d",&y_max,&x_max);
  for(int i = 0 ; i < x_max ; ++i)
	for(int j = 0 ; j < y_max ; ++j){
	  scanf("%d",&temp_int);
	  if(temp_int == -1) ++no_tom;
	  else if(temp_int == 1) {
			temp.x = i;
		  temp.y = j;
		  ++count;
		  q.push(temp);
			++tot_tom;
		}
	  arr[i][j] = temp_int;
	}
	//여기서 걍 count를 세서 큐에 바로 담아버린다.
	if(q.empty()){
		printf("%d", ( (x_max * y_max) - no_tom ) == tot_tom ? day : -1);
		return 0;
	}
  Pos temp1, temp2;
  int temp_count;
  for(day = 0 ;; ++day){
	// print_arr();
	temp_count = 0;
  	for(int i = 0 ; i < count ; ++i){
		temp1 = q.front();
		arr[temp1.x][temp1.y] = 2;
		q.pop();
		if(temp1.x >= 1){
			temp2.x = temp1.x -1;
		  temp2.y = temp1.y;
		  if(arr[temp2.x][temp2.y] == 0){
			arr[temp2.x][temp2.y] = 1;
			q.push(temp2);
			++temp_count;
			++tot_tom;
		  }
		}
		if(temp1.y >= 1){
		  temp2.x = temp1.x;
		  temp2.y = temp1.y - 1;
			if(arr[temp2.x][temp2.y] == 0){
			arr[temp2.x][temp2.y] = 1;
			q.push(temp2);
			++temp_count;
			++tot_tom;
		  }
		}
		if(temp1.x + 1 < x_max){
			temp2.x = temp1.x + 1;
		  temp2.y = temp1.y;
	 	  if(arr[temp2.x][temp2.y] == 0){
			arr[temp2.x][temp2.y] = 1;
			q.push(temp2);
			++temp_count;
			++tot_tom;
		  }
		}
		if(temp1.y + 1 < y_max){
		  temp2.x = temp1.x;
		  temp2.y = temp1.y + 1;
	 	  if(arr[temp2.x][temp2.y] == 0){
			arr[temp2.x][temp2.y] = 1;
			q.push(temp2);
			++temp_count;
			++tot_tom;
		  }
		}
		}
		if(q.empty()) break;
		count = temp_count;
  }
  printf("%d", ( (x_max * y_max) - no_tom ) == tot_tom ? day : -1);
  return 0;
}


