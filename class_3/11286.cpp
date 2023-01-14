#include <iostream>
#include <queue>

int abs(int n){
	return n > 0 ? n : -1 * n;
}

using namespace std;

struct cmp{
	bool operator()(int n1, int n2){
	if(abs(n1) > abs(n2))
		return true;
	else if(abs(n1) == abs(n2)){
		if(n1 > n2)
		return true;
		else
		return false;
	}
	return false;
}
};

priority_queue<int, vector<int>, cmp> pq;

int main(){
  int n;
  int temp;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	scanf("%d",&temp);
	if(temp == 0){
	  if(pq.empty()){
		printf("0\n");
	  }
	  else{
		printf("%d\n",pq.top());
		pq.pop();
	  }
	}else{
	  pq.push(temp);
	}
  }
  return 0;
}



