#include <iostream>
#include <queue>
#include <string.h>

typedef struct Elem{
  int n;
  int former_n;
}Elem;

std::queue<Elem> Q;

int is_visited[10010]={0,};
int prob, ans;

int oper_D(int n){
  return 2 * n % 10000;
}
int oper_S(int n){
  if(n == 0) return 9999;
  return n - 1;
}
int oper_L(int n){
  int temp;
  temp = n / 1000;
  n = (n - temp * 1000) * 10 + temp;
  return n;
}
int oper_R(int n){
  int temp;
  temp = n % 10;
  n = n / 10 + temp * 1000;
  return n;
}

void print_answer(int n){
  char answer[10000] = {0,};
  int temp = is_visited[n] - 1;
  int length;
  for(length = 0 ; n != prob; ++length){
    temp = is_visited[n] - 1;
    if(oper_D(temp) == n) { strcat(answer + length, "D"); n = temp; }
    else if(oper_S(temp) == n) { strcat(answer + length, "S"); n = temp; }
    else if(oper_L(temp) == n) { strcat(answer + length, "L"); n = temp; }
    else if(oper_R(temp) == n) { strcat(answer + length, "R"); n = temp; }
  }
  for(int i = length - 1 ; i >= 0 ; --i )
  printf("%c",answer[i]);
  printf("\n");
}

int main(){
  int n;
  Elem temp_front, temp_elem;
  scanf("%d",&n);
 // printf("%d %d %d %d",oper_D(n), oper_S(n), oper_L(n), oper_R(n));
  for(int i = 0 ; i < n ; ++i){
	while(Q.empty() == false){
	  Q.pop();
	}
	memset(is_visited, 0, sizeof(is_visited));
	scanf("%d %d",&prob, &ans);
	temp_elem.former_n = prob;
	temp_elem.n = prob;
	Q.push(temp_elem);
	while(Q.empty() == false){
	  temp_front = Q.front();
	  Q.pop();
	  // printf("searching -> %d\n",temp_front.n);
	  if( is_visited[temp_front.n] > 0 ) continue; 
	  is_visited[temp_front.n] = temp_front.former_n + 1;
	  if(temp_front.n == ans)  break; 
	  Q.push( (Elem){.n = oper_D(temp_front.n), .former_n = temp_front.n} );
	  Q.push( (Elem){.n = oper_S(temp_front.n), .former_n = temp_front.n} );
	  Q.push( (Elem){.n = oper_L(temp_front.n), .former_n = temp_front.n} );
	  Q.push( (Elem){.n = oper_R(temp_front.n), .former_n = temp_front.n} );
	}
	print_answer(ans);
  }
  return 0;
}

