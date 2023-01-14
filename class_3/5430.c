#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){
  int test_cases;
  char temp[100010];
  char temp_char;
  int arr_length;
  int arr[100010];
  int st, end;
  int cursor, flag = 0;
  int tot_D, tot_length;
  scanf("%d\n",&test_cases);
  for(int cases = 0 ; cases < test_cases ; ++cases){
	tot_D = 0;
	for(flag = 0;temp_char = getchar(), temp_char != '\n'; ++flag){
	  if(temp_char == 'D') ++tot_D;
	  temp[flag] = temp_char;
	}
	tot_length = flag;
	temp[tot_length + 1] = '\0';
	scanf("%d\n",&arr_length);
	memset(arr, 0 ,sizeof(arr));
	getchar();
	for(int i = 0 ; i < arr_length ; ++i){
	  for(int j = 0 ; j <= 3 ; ++j){
		temp_char = getchar();
		if(temp_char == ',' || temp_char == ']') break;
		arr[i] *= 10;
		arr[i] += temp_char - '0';
	  }
	}
	getchar();
	if(arr_length == 0) getchar();
	if( tot_D > arr_length ) {printf("error\n"); continue;}
	else if( tot_D == arr_length ) { printf("[]\n"); continue;}
	flag = 0;
	cursor = 0;
	st = 0;
	end = arr_length - 1;
	for(int i = 0 ; i < tot_length ; ++i){
	  switch(temp[i]){
		case 'R':
		  if(flag == 0){
			flag = 1;
			cursor = end;
		  }
		  else{
			flag = 0;
			cursor = st;
		  }
		  break;
		case 'D':
		  if(st > end) {printf("error\n");flag = -1;break;}
		  if(flag == 0){
			  st += 1;
			  cursor = st;
			}
		  else{
			end -= 1;
			cursor = end;
		  }
		  break;
	  }
	}
	if(flag == -1) continue;
	printf("[");
	if(flag == 1){
	  for(int i = end ; i > st ; --i){
		printf("%d,",arr[i]);
	  }
	  printf("%d]\n",arr[st]);
	}
	else{
	  for(int i = st; i < end ; ++i){
		printf("%d,",arr[i]);
	  }
	  printf("%d]\n",arr[end]);
	}
  }
  return 0;
}
