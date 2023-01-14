#include <bits/stdc++.h>
#define STR_MAX 2501

using namespace std;

string str;
bool DP[STR_MAX][STR_MAX];

int DP2[STR_MAX];


int main(){
  int str_len;
  cin >> str;
  str_len = str.length();
  for(int i = 0 ; i < str_len; ++i){
	DP[i][i] = true;
	if(str[i] == str[i+1])
	  DP[i][i+1] = true;
  }
  for(int i = 0 ; i < str_len ; ++i){
	for(int j = 0 ; j + i < str_len ; ++j){
	  int left = j;
	  int right = j + i;
	  if(!DP[left+1][right-1]) continue;
	  if(str[left] != str[right]) continue;
	  DP[left][right] = true;
	}
  }
  DP2[0] = 1;
  for(int i = 1 ; i <str_len ; ++i){
	DP2[i] = STR_MAX;
	for(int j = 0 ; j <= i; ++j){
	  if(!DP[j][i]) continue;
	  if(j < 1)  DP2[i] = 1;
	  else DP2[i] = min(DP2[i], DP2[j-1] + 1);
	}
  }
  cout << DP2[str_len-1];
  return 0;
}

