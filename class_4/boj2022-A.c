#include <stdio.h>
#include <string.h>
#include <math.h>

int check[10];

int find(int num, int d){
  memset(check,0,sizeof(check));
  while(num != 0){
	if(check[num%d] > 0) return 0;
	++check[num%d];
	num = num/d;
  }
  for(int i = 0 ; i < d ; ++i){
    if(check[i] == 0 ) return 0;
  }
  return 1;
}

int main() {
  int n, d;
  int max=0;
  int min=0;
  scanf("%d %d",&n ,&d);
  for(int i = d - 1 ; i >= 0 ; --i){
    if(i == d - 1){
      min += 1*pow(d,i);
    }
    else if(i == d - 2){
      min += 0;
    }
    else {
      min += ((d-1) - i)*pow(d,i);
    }
	max += i*pow(d, i);
  }
  // printf("%d %d\n", min ,max);
  if(n < min){printf("%d",min);return 0;}
  for(int i = n + 1 ; i <= max ; ++i){
	if(find(i, d) == 1){
	  printf("%d", i);
	  return 0;
	}
  }
  printf("-1");
  return 0;
}

/* 에이 시발 틀린이유가 나만 보려고 한 max 출력때문이라는게 말이되냐ㅋㅋㅋ*/