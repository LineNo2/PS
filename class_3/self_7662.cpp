#include <stdio.h>

unsigned int heap[100010];
int cur_index = -1;

int get_parent(int index);
int get_left_child(int index);
int get_right_child(int index);
void swap_nodes_data(int index1, int index2);
int return_min_node(int a, int b);
int return_max_node(int a, int b);

int is_empty(){
  return cur_index == -1;
}

int return_min_node(int a, int b){
  if( heap[a] > heap[b] ) return b;
  else return a;
}

int return_max_node(int a, int b){
  if( heap[a] > heap[b] ) return b;
  else return b;
}

void insert_min(int data){
  heap[++cur_index] = data;
  int temp_index = cur_index;
  while(temp_index != 0){
	if( heap[temp_index] < heap[get_parent(temp_index)] ){
	  swap_nodes_data(temp_index, get_parent(temp_index));
	}
  temp_index = get_parent(temp_index);
	// else break;
  }
}

unsigned int delete_elem_min(){
  unsigned int answer;
  int temp_index, temp;
  if(is_empty()) return 0;
  answer = heap[0];
  heap[0] = heap[cur_index];
  heap[cur_index--] = 4294967294;
  temp_index = 0;
  while(temp_index <= cur_index){
  temp = return_min_node(get_left_child(temp_index), get_right_child(temp_index) );
	if(heap[temp_index] > heap[temp] ){
	  if(temp > cur_index) break;
	  swap_nodes_data(temp_index, temp);
	  temp_index = temp;
	}
	else break;
  }
  return answer;
}


int get_parent(int index){
  return (index - 1)/2;
}

int get_left_child(int index){
  return index * 2 + 1;
}

int get_right_child(int index){
  return index * 2 + 2;
}

void swap_nodes_data(int index1, int index2){
  unsigned int temp;
  temp =  heap[index1]; 
  heap[index1] = heap[index2];
  heap[index2] = temp;
}



int main(){
  int testcases;
  int n;
  char inst;
  int temp;
  scanf("%d",&testcases);
  for(int cases = 0 ; cases < testcases ; ++cases){
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
	  scanf("%c %d",&inst ,&temp);
	  if(inst == 'I'){}
	  else if(inst =='D'){}
	}
  return 0;
  }
}
