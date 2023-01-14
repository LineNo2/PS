#include <iostream>
#include <map>

std::map<int, int> m;

int main(){
  m.insert(std::make_pair(2,1));
  m.insert(std::make_pair(3,1));
  printf("%d",m[2]);
  printf("%d",m[1]);
  return 0;
}
