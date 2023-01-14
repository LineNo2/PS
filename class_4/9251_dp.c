#include <stdio.h>
#include <string.h>
#define MAX 1000
#define ALPHA 26

char s1[MAX], s2[MAX];
int max = 0;
int s1_len, s2_len;
int d[MAX];
int dp[MAX];
int former_pos[ALPHA];

int find_chr_reverse(char key, int end_s2){
  for(int i = end_s2 - 1 ; i >= 0 ; --i){
	if(s2[i] == key) return i;
  }
  return -2;
}

int main(){
  char temp[MAX];
  scanf("%s\n%s",s1,temp);
  if(strlen(s1) >= strlen(temp)) strcpy(s2, temp);
  else  { strcpy(s2,s1); strcpy(s1,temp); }
  s1_len = strlen(s1);
  s2_len = strlen(s2);
  char key;
  int key_idx;
  int start;
  for(int i = 0 ; i < ALPHA ; ++i)
	former_pos[i] = -1;
  for(int i = 0 ; i < s1_len ; ++i){
	key = s1[i];
	key_idx = s1[i] - 'A';
	start = former_pos[key_idx];
	// d[i] = -2;
	// if(start == -2) continue;
	for(int j = start + 1;  j < s2_len ; ++j){
	  if(s2[j] == key) { former_pos[key_idx] = j ; break; }
	}
	// if(former_pos[key_idx] != start)
	  d[i] = former_pos[key_idx];
	//printf("%c : %d\n", key, d[i]);
  }
  for(int i = 0; i < s1_len ; ++i){
	if(d[i] == -1) continue;
	dp[i]= 0;
	for(int j = 0 ;j < i ; ++j){
	  if(d[i] > d[j]){
		if(dp[i] >= dp[j]) continue;
		dp[i] = dp[j];
	  }
	}
	dp[i]++;
	if(dp[i] > max ) max = dp[i];
  }

  printf("%d",max);
  return 0;
}
  //for(int i = 0 ; i < ALPHA ; ++i)
  //  former_pos[i] = -1;
  //for(int i = s1_len - 1 ; i >= 0 ; --i){
  //  if(former_pos[s1[i] - 'A'] == -2) {d[i] = -2; continue;}
  //  if(former_pos[s1[i] - 'A'] == -1){
  //    former_pos[s1[i] - 'A'] = find_chr_reverse(s1[i], s2_len);
  //    d[i] = former_pos[s1[i] - 'A'];
  //  }
  //  else{
  //    former_pos[s1[i] - 'A'] = find_chr_reverse(s1[i], former_pos[s1[i] - 'A']);
  //    d[i] = former_pos[s1[i] - 'A'];
  //  }
  //}
  /*for(int i = 0; i < s1_len ; ++i){
	//printf("%c : %d\n",s1[i], d[i]);
	if(d[i] == -2) continue;
	printf("%d ",d[i]);
  } */
