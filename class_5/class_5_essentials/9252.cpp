#include <bits/stdc++.h>
#include <cstring>
#define STRLEN_MAX 1001

using namespace std;

string str1, str2;

int DP[STRLEN_MAX][STRLEN_MAX];

char ans_string[STRLEN_MAX] = {'\0',};
int former_value = 0;

int main(){
  cin >> str1 >> str2;
  for(int i = 1 ; i <= str1.length() ; ++i){
	for(int j = 1 ; j <= str2.length() ; ++j){
	  if(str1[i-1] == str2[j-1]) {
			DP[i][j] = DP[i-1][j-1] + 1;
			int cur_DP = DP[i][j];
		}
	  else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
	}
  }
	int ans_length = DP[str1.length()][str2.length()] ;
  cout << ans_length << endl;
	int i = str1.length(), j = str2.length(), temp = ans_length;
	while(i > 0 && j > 0){
		if(DP[i][j] == DP[i][j-1]) --j;
		else if(DP[i][j] == DP[i-1][j]) --i;
		else {
			 ans_string[temp--] = str1[i-1];
			  --i; --j; 
		}
	}
  for(int i = 1 ; i <= ans_length ; ++i){
	cout << ans_string[i];
  }
  return 0;
}

