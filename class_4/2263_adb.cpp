#include <iostream>
#include <unistd.h>
#include <stack>
#include <algorithm>
#define MAX 100001

using namespace std;

typedef struct Node{
  int parent;
  int left_child;
  int right_child;
}Node;

int inorder[MAX];
int postorder[MAX];
int inorder_index[MAX];
Node nodes[MAX];

int n;
int root;

//p1 : inorder index, p2 : postorder index , add : range
void print_preorder(int p1, int p2, int add){
  if(add < 0 || p1 + add >= n || p2 + add >= n) return;
  if(add == 0) {
	printf("%d ",inorder[p1]);
	return;
  }
  int root_index = inorder_index[postorder[p2+add]];
  int temp_add = root_index - p1 - 1;
  printf("%d ",postorder[p2+add]);
  print_preorder(p1,p2,temp_add);
  print_preorder(p1+temp_add+2,p2+temp_add+1,add-temp_add-2);
  return;

}

int main(){
  Node temp;
  int temp_input;
  scanf("%d",&n);
  for(int i = 0 ; i < n ;++i){
	scanf("%d",&temp_input);
	inorder_index[temp_input] = i;
	inorder[i] = temp_input;
  }
  for(int i = 0 ; i < n ;++i){
	scanf("%d",&postorder[i]);
  }
  print_preorder(0,0,n-1);
  //  for(int i = 1 ; i <= n; ++i)
    //  printf("\np - %d : %d - lc : %d , rc : %d\n",nodes[i].parent, i, nodes[i].left_child, nodes[i].right_child);
  return 0;
}


