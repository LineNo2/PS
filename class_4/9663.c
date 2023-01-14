#include <stdio.h>
int n;
int count;

void print_arr(int arr[][15]);
int search_ans(int arr[][15]);



int (*get_checked_arr(int arr[][15], int arr_next[][15], int x, int y))[15]{

  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  arr_next[i][j] = arr[i][j];
	}
  }
  for(int i = 0 ; i < n ; ++i){
    if(arr_next[x][i] == 2) return NULL;
	  arr_next[x][i] = 1;
  }
  for(int i = 0 ; i < n ; ++i){
    if(arr_next[i][y] == 2) return NULL;
	  arr_next[i][y] = 1;
  }
  for(int i = (-1) * n ; i < n ; ++i){
	if(x - i < 0 || y - i < 0 || x - i >= n || y - i >= n) continue;
  if(arr_next[x-i][y-i] == 2) return NULL;
	arr_next[x-i][y-i] = 1;
  }
  for(int i = (-1) * n ; i < n ; ++i){
	if(x - i < 0 || y + i < 0 || x - i >= n || y + i >= n) continue;
  if(arr_next[x-i][y+i] == 2) return NULL;
	arr_next[x-i][y+i] = 1;
  }
  arr_next[x][y] = 2;
  return arr_next;
}

void n_queen(int arr[][15], int queen, int x){
  int arr_next[15][15];
  int (*arr_ptr)[15];
	for(int j = 0 ; j < n ; ++j){
	  if(arr[x][j] == 0){
		arr_ptr = get_checked_arr(arr, arr_next, x, j);
    if(arr_ptr == NULL) continue;
    if(queen == n-1){
		  // print_arr(arr_ptr);
      ++count;
    }else{
		  n_queen(arr_ptr, queen + 1, x + 1);
    }
	  }
  }
}

void print_arr(int arr[][15]){
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  printf("%d ",arr[i][j]);
	}
	printf("\n");
  }
  printf("\n");
}

int main(){
  int arr [15][15];
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j)
      arr[i][j] = 0;
  n_queen(arr, 0, 0);
  printf("%d",count);
  return 0;
}

