#include <stdio.h>
#define MAX 100000

int max(int a, int b){
  return a > b ? a : b;
}
int min(int a, int b){
  return a < b ? a : b;
}

int main(){
  char temp[3];
  int d_max[2][3];
	int d_min[2][3];
  int n;
  scanf("%d\n",&n);
  for(int i = 0 ; i < n ; ++i){
	if(i != n - 1)
	scanf("%c %c %c\n",&temp[0], &temp[1], &temp[2]);
	else
	scanf("%c %c %c",&temp[0], &temp[1], &temp[2]);
	if(i == 0){
	  for(int j = 0 ; j < 3; ++j){
		d_max[0][j] = temp[j] - '0';
		d_min[0][j] = temp[j] - '0';
	  }
	  continue;
	}
	//max
	d_max[1][0] = max(d_max[0][0], d_max[0][1]) + temp[0] - '0';
	d_max[1][1] = max(max(d_max[0][0], d_max[0][1]),d_max[0][2]) + temp[1] - '0';
	d_max[1][2] = max(d_max[0][1], d_max[0][2]) + temp[2] - '0';
	d_max[0][0] = d_max[1][0];
	d_max[0][1] = d_max[1][1];
	d_max[0][2] = d_max[1][2];
	//min
	d_min[1][0] = min(d_min[0][0], d_min[0][1]) + temp[0] - '0';
	d_min[1][1] = min(min(d_min[0][0], d_min[0][1]),d_min[0][2]) + temp[1] - '0';
	d_min[1][2] = min(d_min[0][1], d_min[0][2]) + temp[2] - '0';
	d_min[0][0] = d_min[1][0];
	d_min[0][1] = d_min[1][1];
	d_min[0][2] = d_min[1][2];
  }
  printf("%d ", max(max(d_max[0][0], d_max[0][1]),d_max[0][2]));
	printf("%d", min(min(d_min[0][0], d_min[0][1]),d_min[0][2]));
  return 0;
}
