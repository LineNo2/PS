#include <stdio.h>

int n, k;
unsigned int LAN_arr[10010];
unsigned int max = 0, temp;
int longest_length;
int length, i;

unsigned int binary_search(unsigned int start, unsigned int end){
  if(start > end) return end;
  temp = 0;
  length = (start + end) / 2;
  for(i = 0 ; i < n ; ++i){
	temp += LAN_arr[i] / length;
  }
  if( temp >= k ) 
	return binary_search(length + 1, end);
  else
	return binary_search(start, length - 1);

}
int main(){
  scanf("%d %d",&n, &k);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d", &temp);
	if(max < temp)
	  max = temp;
	LAN_arr[i] = temp;
  }
  printf("%d",binary_search(1, max));
  return 0;
}



