#include <stdio.h>
#include <stdlib.h>
typedef struct Data{
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
  int num_of_cards;
  int dequeued_num;
  Data temp;
  int flag = 0;
  scanf("%d",&num_of_cards);
  Queue *new_queue;
  new_queue = (Queue*)malloc(sizeof(Queue));
  InitQueue(new_queue);
  for(int i = 1 ; i <= num_of_cards ; ++i){
    temp.number = i;
	Enqueue(new_queue, temp);	
  }
  while((temp = Dequeue(new_queue)),temp.number != -1){
	if(flag){
	  flag = 0;
	  Enqueue(new_queue, temp);
	}
	else{
	  flag = 1;
	}
	dequeued_num = temp.number;
  }
  printf("%d",dequeued_num);
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
  while(Dequeue(queue).number != -1);
}

  


