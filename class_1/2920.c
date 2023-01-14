#include <stdio.h>
int main (){
  int temp_scan, temp_former, flag;
  scanf("%d %d",&temp_former, &temp_scan);
  flag = temp_former - temp_scan == 1 ? 1 : temp_former - temp_scan == -1 ? 2 : 3;
  if(flag == 3){
	printf("mixed");return 0;}
  temp_former = temp_scan;
  for(int i = 0 ; i< 6 ;i++){
	scanf("%d",&temp_scan);
	if(temp_former - temp_scan == 1 && flag == 1);
	else if(temp_former - temp_scan == -1 && flag == 2);
	else{
	  printf("mixed");return 0;}
	temp_former = temp_scan; // 이부분이....
  }
  printf("%s", flag == 2 ? "ascending" : flag == 1 ? "descending" : "mixed");
  return 0;
}

