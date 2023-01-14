#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int priority;
  struct Node *next;
}Node;

typedef struct Queue{
  struct Node *front, *rear;
  int len;
}Queue;

void InitQueue(Queue *queue);
int IsEmpty(Queue *queue);
void Enqueue(Queue *queue, int data);
int Dequeue(Queue *queue);
void ClearQueue(Queue *queue);

int main() {
  int num_of_cases;
  int num_of_doc, queried_doc;
  int temp;
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
	  scanf("%d",&temp);
	  Enqueue(new_queue,temp); 
	}
	for(int i = 1 ;; i++){
	  search = new_queue->front;
	  while(1){
		if(search->priority > queried_doc){
		  flag = 1;
		  break;
		}
		search = search->next;
		if(search == new_queue->front){
		  flag = 0;
		  break;
		}
	  }	
	  temp = Dequeue(new_queue);
	  if(flag){
		Enqueue(new_queue, temp);
	  }
	  else if(temp == queried_doc){
		printf("%d\n",i);
		ClearQueue(new_queue);
		break;
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

void Enqueue(Queue *queue, int data){
  Node *elem;
  elem = (Node *)malloc(sizeof(Node));
  elem->priority = data;
  if(IsEmpty(queue)){
	queue->front = elem;
  }
  else{
	queue->rear->next = elem;
  }
  queue->rear = elem;
  queue->len++;
}

int Dequeue(Queue *queue){
  int result = 0;
  Node *elem;
  if(IsEmpty(queue)){
	return result;
  }
  elem = queue->front;
  result = elem->priority;
  queue->front = elem->next;
  free(elem);
  queue->len--;
  return result;
}

void ClearQueue(Queue *queue){
  Node *index, *temp;
  index = queue->front;
  while(1){
	free(index);
	temp = index->next;
	index = temp;
  }
  free(index);
  free(temp);
  free(queue);
}

  


