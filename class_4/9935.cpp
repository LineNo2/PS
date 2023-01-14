#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str, bomb;
int bomb_len;
int str_len;
vector<char> stack;

int main(){
  int flag;
  char bomb_last;
  cin >> str >> bomb;
  bomb_len = bomb.length();
  str_len = str.length();
  bomb_last = bomb.back();
  for(int i = 0, idx = -1 ; i < str_len ; ++i){
    stack.push_back(str[i]);
	++idx;
    if(stack.back() == bomb_last){
	  flag = 0;
	  for(int j = 1 ; j < bomb_len ; ++j){
		if( idx - j < 0 || stack[idx - j] != bomb[(bomb_len - 1) - j] ) {
		  flag = 1;
		  break;
		}
	  }
	  if(flag == 0){
		for(int j = 0 ; j < bomb_len ; ++j){
		  stack.pop_back();
		  --idx;
		}
	  }
	  }
	}
  if(stack.empty()) cout << "FRULA";
  else{  
    for(int i = 0 ; i < stack.size(); ++i){
	  cout << stack[i];
  }
  }
  return 0;
}
