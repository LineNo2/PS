#include <stdio.h>
int main(){
  int test_cases;
  int floor, room_number;
  int room_population[15][15]={0,};
  scanf("%d", &test_cases);
	for(int i = 0 ; i <= 14 ; ++i){
	  for(int j = 1 ; j <= 14 ; ++j){
		if( i == 0 ) {
		  room_population[i][j] = j;
		}
		else{
		  for(int k = 1 ; k <= j ; ++k){
			room_population[i][j] += room_population[i-1][k];
		  }
		}
	  }
	}
  for(int test_case = 0 ; test_case < test_cases ; ++test_case){
	scanf("%d\n%d",&floor ,&room_number);
	printf("%d\n", room_population[floor][room_number]);
  }
  return 0;
}
