#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  int sum = 0, temp;
  int mode, mode_sum[8010]={0,};
  int mode_num;
  int num_arr[500050];
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
	scanf("%d",&temp);
	sum += temp;
	num_arr[i] = temp;
	++mode_sum[temp + 4000]; // 0 -> -4000 / 4000 -> 0 / 8000 -> 4000
  }
  sort(num_arr,num_arr+n);
  if(sum > 0){
    if(sum % n >= (float)(n / 2.0))
	    printf("%d\n",sum/n + 1);
    else
	    printf("%d\n", sum/n);
  }
  else{
    sum = sum * (-1);
    if(sum % n >= (float)(n / 2.0))
      printf("%d\n", (sum/n + 1) * (-1));
    else
      printf("%d\n",(sum/n) * (-1));
  }
  printf("%d\n",num_arr[n/2]);
  mode = -1;
  for(int i = 0; i <= 8000 ; i++){
	if(mode < mode_sum[i])
	  mode = mode_sum[i];
  }
  sum = 0;
  for(int i = 0; i <= 8000 ; i++){
	if(mode == mode_sum[i]){
	  mode_num = i;
    if(sum)
      break;
	  sum = 1;
	}
  }
  printf("%d\n", mode_num - 4000);
  printf("%d\n", num_arr[n - 1] - num_arr[0]);
  return 0;
}
	  
