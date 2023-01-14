#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int n , k;

typedef struct Visted_Info{
	int count;
	int min_dist;
}Visted_Info;

Visted_Info is_visited[MAX];
queue<int> Q;

int oper(int oper, int n){
  switch(oper){
	case 0:
	  return n * 2;
	case 1:
	  return n + 1;
	case 2:
	  return n - 1;
  }
	return -1;
}

int main(){
  int temp;
  int next_index;
	int next_dist;
	int ans_dist = MAX;
  cin >> n >> k;
	if(n == k ) {cout << "0\n1"; return 0;}
	for(int i = 0 ; i < MAX ; ++i){
	is_visited[i].min_dist = -1;
	}
  Q.push(n);
  is_visited[n].min_dist = 0;
	++is_visited[n].count;
  while(!Q.empty()){
	temp = Q.front();
	Q.pop();
	for(int i = 0 ; i <= 2; ++i){
	next_index = oper(i,temp);
	if(next_index == temp) continue;
	next_dist = is_visited[temp].min_dist + 1;
	if(next_dist > ans_dist) {
		cout << is_visited[k].min_dist << "\n" << is_visited[k].count; 
		return 0;
		}
	if(next_index < MAX && next_index >= 0 
	&& ( is_visited[next_index].min_dist == -1 
	|| is_visited[next_index].min_dist == next_dist) )
	{
	  if(next_index == k && ans_dist == MAX)
		{
			ans_dist = next_dist;
	  }
	  Q.push(next_index);
	  is_visited[next_index].min_dist = next_dist;
		++is_visited[next_index].count;
	}
	}
	}
}



