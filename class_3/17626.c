#include <stdio.h>
#include <math.h>

int arr[50001] ={0,};
int d[4] = {1,1,2,3};

int count_four_square(int n, int k){
  int temp;
  temp = n - pow(k,2);
  if(temp < 4) return d[temp];
  return 1 + count_four_square(temp, (int)sqrt(temp));
}
int main(){
  int n;
  int answer = 5;
  int temp;
  int sqrt_n;
  scanf("%d",&n);
  sqrt_n = (int)sqrt(n);
  for(int i = sqrt_n ; i >= 1 ; --i ){
	if( (temp = count_four_square(n,i)) < answer)
	  answer = temp;
  }
  printf("%d",answer);
  return 0;
}
