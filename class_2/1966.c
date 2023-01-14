#include <stdio.h>
#include <stdlib.h>
typedef struct Data{
  int priority;
  int number;
}Data;
typedef struct Node{
  struct Data data;
  struct Node *next;
}Node;

typedef struct Queue{
  struct Node *front, *rear;
  int len;
}Queue;

void InitQueue(Queue *queue);
int IsEmpty(Queue *queue);
void Enqueue(Queue *queue, Data data);
Data Dequeue(Queue *queue);
void ClearQueue(Queue *queue);

int main() {
  int num_of_cases;
  int num_of_doc, queried_doc;
//  int priority_of_docs_arr[110];
  int temp, front_priority;
  Data temp_data;
  Data front_data;
  int flag;
  Node *search;
  scanf("%d",&num_of_cases);
  for(int c = 0 ; c < num_of_cases ; ++c){
	Queue *new_queue;
	flag = -1;
	new_queue = (Queue*)malloc(sizeof(Queue));
	InitQueue(new_queue);
	scanf("%d %d", &num_of_doc, &queried_doc);
	for(int i = 0 ; i < num_of_doc ; ++i){
	  scanf("%d",&temp_data.priority);
	  temp_data.number = i;
	  Enqueue(new_queue,temp_data); 
	}
	for(int i = 1 ;;){
	  search = new_queue->front;
	  front_data = search->data;
	  while(1){
		if(search->data.priority > front_data.priority){
		  flag = 1;
		  break;
		}
		if(search == new_queue->rear){
		  flag = 0;
		  break;
		}
		search = search->next;
	  }	
	  Dequeue(new_queue);
	  if(flag){
		Enqueue(new_queue, front_data);
	  }
	  else if(front_data.number  == queried_doc ){
		printf("%d\n",i);
		ClearQueue(new_queue);
		break;
	  }
	  else{
		++i;
	  }
	}
  }
  return 0;
}

void InitQueue(Queue *queue){
  queue->front = queue->rear = NULL;
  queue->len = 0;
}

int IsEmpty(Queue *queue){
  return  queue->len == 0;;
}

void Enqueue(Queue *queue, Data data){
  Node *elem;
  elem = (Node *)malloc(sizeof(Node));
  elem->data= data;
  if(IsEmpty(queue)){
	queue->front = elem;
  }
  else{
	queue->rear->next = elem;
  }
  queue->rear = elem;
  queue->len++;
}

Data Dequeue(Queue *queue){
  Data result;
  result.priority = -1;
  result.number = -1;
  Node *elem;
  if(IsEmpty(queue)){
	return result;
  }
  elem = queue->front;
  result = elem->data;
  queue->front = elem->next;
  free(elem);
  queue->len--;
  return result;
}

void ClearQueue(Queue *queue){
  while(Dequeue(queue).priority != -1);
}

  


