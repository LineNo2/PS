#include <iostream>
#include <queue>
#include <map>

using namespace std;
priority_queue<int> pq1;
priority_queue<int,vector<int>,greater<int>> pq2;
map<int,int> count_of_nums;

int main(){
  int test_cases;
  int n;
  char inst;
  int temp;
  int temp_poped_value;
  
  scanf("%d",&test_cases);
  for(int case_ = 0 ; case_ < test_cases ; ++case_){
	scanf("%d",&n);
	while(pq1.empty() != true && pq2.empty() != true){
	  pq1.pop();
	  pq2.pop();
	  count_of_nums.clear();
	}
	for(int i = 0 ; i < n ; ++i){
	  scanf("\n%c %d",&inst, &temp);
	  if(inst == 'I'){
		pq1.push(temp);
		pq2.push(temp);
		if(count_of_nums.find(temp) != count_of_nums.end()){
		  ++count_of_nums[temp];
		}
		else{
		  count_of_nums.insert(make_pair(temp,1));
		}
		//printf("pushed %d : %dth\n",temp, count_of_nums[temp]);
	  }
	  else if(inst =='D'){
		if(temp == 1){
		  while(1){
		  if(pq1.empty()) {
			//printf("EMPTY\n");
			break;
		  }
		  temp_poped_value = pq1.top(); 
		  pq1.pop();
		  if(count_of_nums[temp_poped_value] > 0){
			--count_of_nums[temp_poped_value];
			//printf("poped -> %d\n",temp_poped_value);
			break;
		  }
		  else continue;
		  }
		}
		else if(temp == -1){
		  while(1){
		  if(pq2.empty()) {
			//printf("EMPTY\n");
			break;
		  }
		  temp_poped_value = pq2.top(); 
		  pq2.pop();
		  if(count_of_nums[temp_poped_value] > 0){
			--count_of_nums[temp_poped_value];
			//printf("poped -> %d\n",temp_poped_value);
			break;
		  }
		  else continue;
		  }
		}
	  }
	}
	  int flag = 0;
	  while(1){
		if(pq1.empty()) {flag = 1; break;}
		if(count_of_nums[temp_poped_value = pq1.top()] > 0){
		  printf("%d ", temp_poped_value);
		  break;
		}
		else{
		  pq1.pop();
		}
	  }
	  if( flag == 1 ) {
		printf("EMPTY\n");
		continue;
	  }
	  else{
	  while(1){
		if(pq2.empty()) {flag = 1; break;}
		if(count_of_nums[temp_poped_value = pq2.top()] > 0){
		  printf("%d\n", temp_poped_value);
		  break;
		}
		else{
		  pq2.pop();
		}
	  }
	  }
  }
  return 0;
}
