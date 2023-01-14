#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int num_counts[1000010];

int main(){
  int test_cases;
  int n;
  char inst;
  int temp;
  scanf("%d",&test_cases);
  for(int case_ = 0 ; i < test_cases ; ++case_){
	scanf("%d",&n);
	memset(num_counts, 0, sizeof(num_counts));
	for(int i = 0 ; i < n ; ++i){
	  scanf("%c %d",&inst, &temp);
	  if(inst == 'I'){
		pq1.push(temp);
		pq2.push(temp);
	  }
	  else if(inst =='D'){
		if(temp == 1){
		  if(pq1.empty() == false){
			while(poped_num[temp] != 0){

			}
		  printf("%d",pq1.top());
		  
	}

  }
