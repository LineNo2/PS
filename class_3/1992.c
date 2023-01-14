#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int paper[129][129];
int paper_type[2];


int inspect_paper(int n, int x, int y){
  int temp = paper[x][y];
  for(int i = x ; i < x + n; ++i){
	for(int j = y ; j < y + n ; ++j){
	  if(temp != paper[i][j]) return 0;
	}
  }
  return 1;
}

char* cut_paper(int n, int x, int y){
  static char* answer_string;
  char* buffer;
  char* answer_buffer;
  buffer = (char*) malloc(pow(n,2));
  answer_buffer = (char*) malloc(pow(n,2) * 3);
  int index = 0;
  if(inspect_paper(n, x, y)){
	sprintf(buffer, "%d", paper[x][y]);
	answer_string = buffer;
	return answer_string;
  }
  strcat(answer_buffer, "(");
  index++;
  if(inspect_paper(n/2, x, y)){
	sprintf(buffer, "%d", paper[x][y]);
	strcat(answer_buffer + index++, buffer);
  }else{ 
	buffer = cut_paper(n/2, x, y); 
	strcat(answer_buffer + index, buffer);
	index += strlen(buffer);
  }

  if(inspect_paper(n/2, x, y + n/2)){
	sprintf(buffer, "%d", paper[x][y + n/2]);
	strcat(answer_buffer + index++, buffer);
  }else{ 
	buffer = cut_paper(n/2, x, y + n/2); 
	strcat(answer_buffer + index, buffer);
	index += strlen(buffer);
  }

  if(inspect_paper(n/2, x + n/2, y)){
	sprintf(buffer, "%d", paper[x + n/2][y]);
	strcat(answer_buffer + index++, buffer);
  }else{ 
	buffer = cut_paper(n/2, x + n/2, y); 
	strcat(answer_buffer + index, buffer);
	index += strlen(buffer);
  }

  if(inspect_paper(n/2, x + n/2, y + n/2)){
	sprintf(buffer, "%d", paper[x + n/2][y + n/2]);
	strcat(answer_buffer + index++, buffer);
  }else{ 
	buffer = cut_paper(n/2, x + n/2, y + n/2); 
	strcat(answer_buffer + index, buffer);
	index += strlen(buffer);
  }
  strcat(answer_buffer + index, ")");
  answer_string = answer_buffer;
  
  return answer_string;
}

int main(){
  int n;
  char temp;
  scanf("%d\n",&n);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  temp = getchar();
	  paper[i][j] = temp - '0';
	}
	getchar();
  }
  printf("%s", cut_paper(n, 0, 0));
  return 0;
}

