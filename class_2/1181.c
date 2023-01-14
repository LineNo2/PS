#include <stdio.h>
#include <string.h>
#define MAX "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
int compare_str(char *s1__, char *s2__){
  if(s1__[0] == s2__[0]){
	if(s1__[0] == '\0') return 0;
	else return compare_str( s1__ + 1 ,s2__ + 1);
  }
  return s1__[0] > s2__[0] ? 1 : -1;
}
int compare_words(char *s1_, char *s2_){
  if(strlen(s1_) > strlen(s2_))
	return 1;
  else if(strlen(s1_) < strlen(s2_))
	return -1;
  else {
	return compare_str(s1_,s2_); //strcmp is too slow to compare. 
  }
}

int main(){
  char words_arr[20020][51];
  char temp[51];
  char min[51];
  int num_of_words;
  int index_of_min;
  int result_of_strcmp;
  scanf("%d",&num_of_words);
  for(int i = 0; i < num_of_words ; i++){
	scanf("%s", &words_arr[i][0]);
  }
  for(int i = 0 ; i < num_of_words ; i++){
	if(words_arr[i][0] == '\0') continue;
	strcpy(min,MAX);
	for(int j = i; j < num_of_words ; j++){
	   if(words_arr[j][0] == '\0') continue;
	   if((result_of_strcmp = compare_words(min, words_arr[j])) > 0){
	     index_of_min = j;
	     strcpy(min, words_arr[j]);
		 }
	   else if(result_of_strcmp == 0 && i != j){
		 words_arr[j][0] = '\0';;
	   }
	  }
	  strcpy(temp, words_arr[index_of_min]);
	  strcpy(words_arr[index_of_min],words_arr[i]);
	  strcpy(words_arr[i], temp);
	printf("%s\n",words_arr[i]);
  }
  return 0;
}
/*
	  if(strlen(min) > strlen(words_arr[j])){
		  index_of_min = j;
		  strcpy(min,words_arr[j]);
		  }
  	  else if(strlen(min) == strlen(words_arr[j])){
		if((result_of_strcmp = strcmp(min, words_arr[j])) > 0){
	      index_of_min = j;
		  strcpy(min, words_arr[j]);
	   	}
		else if(result_of_strcmp == 0){
		  words_arr[j][0] = '\0';
		  }
		}
*/
