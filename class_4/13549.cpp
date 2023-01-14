#include <iostream>
#include <deque>
#define MAX 100001

using namespace std;

int n, k;
bool is_visited[MAX] = {false,};
int dist[MAX];
deque<int> deq; 

int main(){
  int temp;
  int next_index, cur_index;
  cin >> n >> k;
  deq.push_front(n);
  is_visited[n] = true;
  while(!deq.empty()){
	temp = deq.front();
	deq.pop_front();
	cur_index = temp;
	if(cur_index == k ) { //escape
		cout << dist[cur_index]; 
		return 0;
	}
	next_index = cur_index * 2;	
	if(next_index < MAX && next_index >= 0 && !is_visited[next_index]) {
		is_visited[next_index] = true;
		dist[next_index] = dist[cur_index];
	  deq.push_front(next_index);
	}
	next_index = cur_index - 1;
	if(next_index < MAX && next_index >= 0 && !is_visited[next_index]) {
		is_visited[next_index] = true;
		dist[next_index] = dist[cur_index] + 1;
		deq.push_back(next_index);
	}
	next_index = cur_index + 1;	
	if(next_index < MAX && next_index >= 0 && !is_visited[next_index]) {
		is_visited[next_index] = true;
		dist[next_index] = dist[cur_index] + 1;
		deq.push_back(next_index);
	}
  }
}
