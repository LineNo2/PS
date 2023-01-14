#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node *front;
Node *rear;

int queue_size = 0;

int is_empty(){
  return queue_size == 0;
}

void push(int n){
  Node *elem;
  elem = (Node*)malloc(sizeof(Node));
  elem->data = n;
  if(is_empty())
	front = elem;
  else
  rear->next = elem;
  rear = elem;
  ++queue_size;
}


int pop(){
  int temp;
  if(is_empty()) return -1;
  temp = front->data;
  front = front->next;
  --queue_size;
  return temp;
}

int print_size(){
  return queue_size;
}

int print_front(){
  if(is_empty()) return -1;
  return front->data;
}

int print_back(){
  if(is_empty()) return -1;
  return rear->data;
}


int main(){
  char input[20];
  char *ptr;
  int n;
  int temp;
  scanf("%d\n",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%s", &input[0]);
	if(strcmp(input,"push") == 0){
	  scanf("%d\n", &temp);
	  push(temp);
	}
	else if(strcmp(input, "front") == 0)
	  printf("%d\n", print_front());
	else if(strcmp(input, "back") == 0)
	  printf("%d\n", print_back());
	else if(strcmp(input, "size") == 0)
	  printf("%d\n", print_size());
	else if(strcmp(input, "empty") == 0)
	  printf("%d\n", is_empty());
	else if(strcmp(input, "pop") == 0)
	  printf("%d\n", pop());
  }
  return 0;
}


