#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

int main(){
  int n, k;
  Node *p, *first;
  Node *temp;

  scanf("%d %d",&n, &k);

  p = (Node*)malloc(sizeof(Node));
  p->data = 1;
  first = p;

  for(int i = 2 ; i <= n ; ++i){
	p->next = (Node*)malloc(sizeof(Node));
	p = p->next;
	p->data = i;
  }
  p->next = first;
  printf("<");
  for(int i = 0 ; i < n - 1 ; ++i){
	for(int j = 0 ; j < k - 1 ; ++j)
	  p = p->next;
	temp = p;
	p = p->next;
	printf("%d, ",p->data);
	temp->next = p->next;
	p = temp;
  }
  printf("%d>",p->data);
  return 0;
}
	
	  
	
