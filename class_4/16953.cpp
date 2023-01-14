#include <iostream>
#include <queue>
#define MAX_10 100000000
#define MAX_2 500000000

using namespace std;

typedef struct Point{
  int x;
  int count;
}Point;

int A, B;

int get_next_value(int n, int toggle){
  switch(toggle){
	case 0:
	  if( n <= MAX_10 ) n = n * 10 + 1;
    else n = -1;
    break;
	case 1:
	  if( n <= MAX_2 ) n *= 2;
    else n = -1;
    break;	  
  }
  if( n > B ) n = -1;
  return n;
}

int main(){
  int temp;
  int cur_count;
  int next_value;
  cin >> A >> B;
  queue<Point> Q;
  Q.push({.x = A, .count = 1});
  while(!Q.empty()){
	temp = Q.front().x;
	cur_count = Q.front().count;
	Q.pop();
	for(int i = 0 ; i < 2 ; ++i){
	  next_value = get_next_value(temp, i);
	  if(next_value == -1) continue;
	  if(next_value == B) { cout << cur_count + 1 ; return 0; }
	  Q.push({.x = next_value, .count = cur_count + 1});
	}
  }
  cout << -1;
  return 0;
}

