#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int n_channel;
int broken_n;
int unbroken_n;
int broken_arr[11] = {0,};
int temp;
int digit, min_value = 987654321;
int answer;

char num_str[7] = "\0";



int get_digit_len(int n){
  if( (n / 10) == 0 ) return 1;
  return get_digit_len(n/10) + 1;
}

int get_clicks(int n){
  if(n == 0 && broken_arr[0] !=0 ) return 987654321;
  return get_digit_len(n) + abs(n_channel - n);
}

void gen_num(int digit, char *num_str_){
  int temp_;
  if(digit > 1){
    for(int i = 0 ; i < unbroken_n ; ++i){
      sprintf(num_str_, "%d", broken_arr[i]);
      gen_num(digit - 1, num_str_ + 1);
  }
  }else{//문제점 : atoi가 "\n"를 0으로 리턴해서 문제가 꼬임
    if(min_value > (temp_ = get_clicks(atoi(num_str)))){
      min_value = temp_;
      answer = atoi(num_str);
    }
  }
}

void check_min(int digit){
  char *ptr;
  ptr = &num_str[0];
  gen_num(digit, ptr);
}

int main(){
  broken_arr[0] = -1;
  scanf("%d\n%d",&n_channel,&broken_n);
  for(int i= 0 ; i < broken_n ; ++i){
	scanf("%d",&temp);
	broken_arr[temp] = 1;
  }
  temp = 0;
  if(broken_arr[0] == -1) broken_arr[temp++] = 0;
  for(int i = 1 ; i < 10 ; ++i){
	if(broken_arr[i] != 1)
	  broken_arr[temp++] = i;
  }
  unbroken_n = temp;
  min_value = abs(n_channel - 100);

  for(int d = (digit = get_digit_len(n_channel) ) ; d <= digit + 2 ; ++d){
    check_min(d);
  }
  printf("%d",min_value);
  return 0;
}


