#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int Data;
}Node;

typedef struct Heap{
  Node * node;
  int capacity;
  int usedsize;
}Heap;

Heap* H;

Heap* heap_init(int size)
{
  Heap* new_heap = (Heap*)malloc(sizeof(Heap));
  new_heap->capacity = size;
  new_heap->usedsize = 0;
  new_heap->node = (Node*)malloc(sizeof(Node) * size);
  return new_heap;
}

int get_parent(int index){
  return (int)((index - 1) / 2);
