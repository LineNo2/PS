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
Node nodes[MAX];

int n;
int root;

int search_from_postorder(int i1, int i2, int n){
  for(int i = i1 ; i <= i2 ; ++i)
	if(n == postorder[i]) return i;
  return -1;
}
int get_subtrees_root(int ps){
  while(nodes[ps].parent != 0){
    ps = nodes[ps].parent;
  }
  return ps;
}

//p1 : inorder index, p2 : postorder index , add : range
int in_post_to_pre(int p1, int p2, int add){ // return P's index;
  int next;
  int parent_index;
  int next_p1, next_p2;
  int left_child_index = 0;
  if(add < 0 || p1 + add >= n || p2 + add >= n) return -1;
  if(add == 0) return p1;
  //printf("f(%d,%d,%d)\n\n",p1,p2,add);
	int temp_add = add;
	int temp_p1 = p1;
	int temp_p2 = p2;
	//printf("%d == %d ?\n",inorder[temp_p1],postorder[temp_p2]);
	while(inorder[temp_p1] == postorder[temp_p2] && temp_add > 0){
	  nodes[inorder[temp_p1+1]].left_child = inorder[temp_p1];
    nodes[inorder[temp_p1]].parent = inorder[temp_p1+1];
	  ++temp_p1;
	  ++temp_p2;
	  --temp_add;
	}
	parent_index = temp_p1;
	next_p1 = parent_index + 1;
	next_p2 = temp_p2;
  next = search_from_postorder(next_p2, next_p2 + add, inorder[parent_index]);
  temp_add = next - next_p2 - 1;

  //printf("f(%d, %d, %d) + ",next_p1,next_p2,temp_add);
  int right_child_index = in_post_to_pre(next_p1, next_p2, temp_add);
  // 오른쪽 트리를 전부 탐색.
  if(temp_add == -1) {
    return parent_index;
  }
  int right_child_value = get_subtrees_root(inorder[right_child_index]);
	// nodes[inorder[parent_index]].right_child = inorder[right_child_index];
  // nodes[inorder[right_child_index]].parent = inorder[parent_index];
  nodes[inorder[parent_index]].right_child = right_child_value;
  nodes[right_child_value].parent = inorder[parent_index];
  next_p1 += temp_add + 1;
  next_p2 += temp_add + 2; 
  temp_add = p2 + add - next_p2;
  //printf(" f(%d,%d,%d)\n",next_p1, next_p2, temp_add); 

  int former_parent_index = in_post_to_pre(next_p1, next_p2, temp_add);
  // 부모 트리를 탐색.
  if(former_parent_index != -1){
  // if(nodes[inorder[former_parent_index]].left_child == 0){	
  nodes[inorder[former_parent_index]].left_child = inorder[parent_index];
  nodes[inorder[parent_index]].parent = inorder[former_parent_index];
  // }
  //nodes[inorder[parent_index]].parent = inorder[former_parent_index];
  }
  else{
	root = inorder[parent_index];
	//printf("root : %d", root);
  }
	return parent_index;
 // return former_parent_index;
}

void preorder_search(int cur){
  if( cur == 0 ) return;
  printf("%d ", cur);
  preorder_search(nodes[cur].left_child);
  preorder_search(nodes[cur].right_child);
}

int main(){
  Node temp;
  scanf("%d",&n);
  for(int i = 0 ; i < n ;++i){
	scanf("%d",&inorder[i]);
  }
  for(int i = 0 ; i < n ;++i){
	scanf("%d",&postorder[i]);
  }
  in_post_to_pre(0,0,n-1);
  preorder_search(get_subtrees_root(1));
  //  for(int i = 1 ; i <= n; ++i)
    //  printf("\np - %d : %d - lc : %d , rc : %d\n",nodes[i].parent, i, nodes[i].left_child, nodes[i].right_child);
  return 0;
}


