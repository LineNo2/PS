#include <stdio.h>
#include <queue>

typedef struct Point{
  int x;
  int count;
}Point;

std::queue<Point> Q;

int main(){
  int n, m;
  int st, ed;
  int ladder[110] = {0,};
  int snake[110] = {0,};
  int is_visited[110] = {0,};
  Point temp1, temp2;
  scanf("%d %d",&n, &m);
  for(int i = 0 ; i < n; ++i){
	scanf("%d %d",&st, &ed); 
	ladder[st] = ed;
  }
  for(int i = 0 ; i < m ; ++i){
	scanf("%d %d",&st, &ed);
	snake[st] = ed;
  }
  temp1.x = 1;
  temp1.count = 0;
  Q.push(temp1);
  while(Q.empty() == false){
	temp1 = Q.front();
	Q.pop();
	if(temp1.x > 100) continue;
	if(is_visited[temp1.x] == 1) continue;
	is_visited[temp1.x] = 1;
	if(temp1.x == 100) {
	  printf("%d", temp1.count);
	  return 0;
	}
	for(int i = 6; i >= 1; --i){
	  if(ladder[temp1.x + i] > 0)
		Q.push((Point){.x = ladder[temp1.x + i]  , .count = temp1.count + 1});
	  else if(snake[temp1.x + i] > 0)
		Q.push((Point){.x = snake[temp1.x + i]  , .count = temp1.count + 1});
	  else
		Q.push((Point){.x = temp1.x + i , .count = temp1.count + 1});
	}
  }
}



