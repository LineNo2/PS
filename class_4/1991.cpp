#include <iostream>
#include <stack>

using namespace std;

typedef struct Node{
  int parent;
  int left_child;
  int right_child;
}Node;

Node nodes[27];

stack<int> visit_stack;

void preorder_traverasal(int pointer){
	printf("%c",pointer + '@');
	if(nodes[pointer].left_child != 0)
	preorder_traverasal(nodes[pointer].left_child);
	if(nodes[pointer].right_child != 0)
	preorder_traverasal(nodes[pointer].right_child);	
}

void inorder_traverasal(int pointer){
	if(nodes[pointer].left_child != 0)
	inorder_traverasal(nodes[pointer].left_child);
	printf("%c",pointer + '@');
	if(nodes[pointer].right_child != 0)
	inorder_traverasal(nodes[pointer].right_child);	
}

void postorder_traverasal(int pointer){

	if(nodes[pointer].left_child != 0)
	postorder_traverasal(nodes[pointer].left_child);
	if(nodes[pointer].right_child != 0)
	postorder_traverasal(nodes[pointer].right_child);		printf("%c",pointer + '@');
}

int main(){
  char temp;
  char parent, left_child, right_child;
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; ++i){
	cin >> parent >> left_child >> right_child;
	if(left_child != '.'){
	  nodes[parent - '@'].left_child = left_child - '@';
	  nodes[left_child - '@'].parent = parent - '@';
	}
	if(right_child != '.'){
	  nodes[parent - '@'].right_child = right_child - '@';
	  nodes[right_child - '@'].parent = parent - '@';
	}
  }
  preorder_traverasal(1);
	printf("\n");
	inorder_traverasal(1);
	printf("\n");
	postorder_traverasal(1);
  return 0;
}
