#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Members_info{
  int index;
  int age;
  char name[200];
}Members_info;

bool compare(const Members_info& p1, const Members_info& p2){
  if(p1.age == p2.age)
	return p1.index < p2.index;
  else 
	return p1.age < p2.age;
}

int main(){
  int n;
  Members_info arr[100010];
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d %s", &arr[i].age, &arr[i].name[0]);
	arr[i].index = i;
  }
  
  sort(arr, arr+n, compare);
  for(int i = 0 ; i < n ; ++i){
	printf("%d %s\n", arr[i].age, arr[i].name);
  }
  return 0;
}

  
