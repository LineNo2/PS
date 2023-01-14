#include <stdio.h>
#define MAX 10000

int preorder[MAX];
int idx = 0;

int search_bigger_than_parent(int parent_idx, int range){
  for(int i = parent_idx + 1 ; i < range ; ++i){
	if(preorder[parent_idx] < preorder[i]) return i;
  }
  return -1;
}

void postorder(int p, int end){
  //printf("f(%d,%d) -> %d\n",p, end,preorder[p]); 
  if(p >= idx || p >= end) return;
  int parent = preorder[p];
  if(p == end - 1) {
	printf("%d\n",parent); 
	return;
  }
  int right_child_idx = search_bigger_than_parent(p, end);
  int left_child_idx = p + 1;
  if(right_child_idx != -1) {
  if(p+1 != right_child_idx ) {
	postorder(left_child_idx, right_child_idx);
  }
  postorder(right_child_idx , end);
  }else{
	postorder(left_child_idx, end);
  }
  printf("%d\n",parent);
  return;
}

int main(){
  int temp;
  while(scanf("%d",&preorder[idx++]) != EOF );
  idx--;
  postorder(0,idx);
  return 0;
}


