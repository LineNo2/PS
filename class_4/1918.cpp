#include <iostream>
#include <stack>
#include <cstring>

typedef struct Oper{
  char oper;
  int priority;
}Oper;

// std::stack<Oper> Oper_stack;

std::stack<char> Oper_stack;

using namespace std;

int oper_to_int(char n){
	if(n == '(') return 0;
  else if(n == '+' || n == '-') return 1;
  return 2;
}

int main(){
  char temp;
  Oper temp_oper;
  temp = getchar();
  while(temp != '\n'){
	temp_oper.priority = 0;
	switch(temp){
	  case '(':
		Oper_stack.push(temp);
		break;
	  case ')':
		while(Oper_stack.top() != '('){
		cout << Oper_stack.top();
		Oper_stack.pop();
		}
		Oper_stack.pop();
		break;
	  case '+':
	  case '-':
	  case '*':
	  case '/':
		if(Oper_stack.empty() == false){
			if(oper_to_int(Oper_stack.top()) > oper_to_int(temp)){
				while(Oper_stack.empty() == false && Oper_stack.top() != '('){
					cout << Oper_stack.top();
					Oper_stack.pop();
				}
			}
			else if(oper_to_int(Oper_stack.top()) == oper_to_int(temp)){
				cout << Oper_stack.top();
				Oper_stack.pop();
			}
		}
		Oper_stack.push(temp);
		break;
	  default:
		cout << temp;
	}
	temp = getchar();
  }
	while(Oper_stack.empty() == false){
			cout << Oper_stack.top();
			Oper_stack.pop();
		  }
  return 0;
}


