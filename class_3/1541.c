#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
  char temp;
  char int_temp[5];
  int int_temp_index = 0;
  int calculated = 0;
  int former_type = 0; // 0 -> operand / 1 -> operator
  int operator_flag = 0 ; // 0 -> + / 1 -> -
  while(( temp = getchar() ) != '\n'){
	if( '0' <= temp && temp <= '9') { 
	  int_temp[int_temp_index++] = temp;
	}
	else if( temp == '+' ) {
	  if( operator_flag == 1 ) calculated -= atoi(int_temp); 
	  else calculated += atoi(int_temp);
	  int_temp_index = 0;
	  memset(int_temp, '\0', sizeof(int_temp));
	}
	else {
	  if(operator_flag) calculated -= atoi(int_temp);
	  else {	
		operator_flag = 1;
		calculated += atoi(int_temp);
	  }
	  int_temp_index = 0;
	  memset(int_temp, '\0', sizeof(int_temp));
	}
  }
  if(operator_flag)	calculated -= atoi(int_temp);
  else calculated += atoi(int_temp);

  printf("%d",calculated);
  return 0;
}
