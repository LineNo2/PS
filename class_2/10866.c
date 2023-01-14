#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  int data;  
  struct Node *node_front;
  struct Node *node_back;
}Node;

Node *front = NULL;
Node *rear = NULL;

int deck_size = 0;

int is_empty(){
  return deck_size == 0;
}

void push_front(int n){
  Node *elem;
  elem = (Node*)malloc(sizeof(Node));
  elem->data = n;
  if(is_empty()){
	front = elem;
	rear = elem;
  }
  else{
	elem->node_back = front;
	front->node_front = elem;
	front = elem;
  }
  ++deck_size;
}

void push_back(int n){
  Node *elem;
  elem = (Node*)malloc(sizeof(Node));
  elem->data = n;
  if(is_empty()){
	front = elem;
	rear = elem;
  }
  else{
	rear->node_back = elem;
	elem->node_front = rear;
	rear = elem;
  }
  ++deck_size;
}


int pop_front(){
  int temp;
  if(is_empty()) return -1;
  temp = front->data;
  front = front->node_back;
  --deck_size;
  return temp;
}

int pop_back(){
  int temp;
  if(is_empty()) return -1;
  temp = rear->data;
  rear = rear->node_front;
  --deck_size;
  return temp;
}

int print_size(){
  return deck_size;
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
	if(strcmp(input,"push_back") == 0){
	  scanf("%d\n", &temp);
	  push_back(temp);
	}
	else if(strcmp(input,"push_front") == 0){
	  scanf("%d\n", &temp);
	  push_front(temp);
	}
	else if(strcmp(input, "front") == 0)
	  printf("%d\n", print_front());
	else if(strcmp(input, "back") == 0)
	  printf("%d\n", print_back());
	else if(strcmp(input, "size") == 0)
	  printf("%d\n", print_size());
	else if(strcmp(input, "empty") == 0)
	  printf("%d\n", is_empty());
	else if(strcmp(input, "pop_front") == 0)
	  printf("%d\n", pop_front());
	else if(strcmp(input, "pop_back") == 0)
	  printf("%d\n", pop_back());
  }
  return 0;
}

