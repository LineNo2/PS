#include <iostream>
#include <map>
#include <string>

using namespace std;



map<string,string> dict;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  string s1, s2;
  cin >> n;
  cin >> m;
  //scanf("%d %d",&n, &m);
  for(int i =0 ; i  < n; ++i){
	cin >> s1; 
	cin >> s2;
	//scanf("%s %s",&s1, &s2);
	dict.insert(make_pair(s1,s2));
  }
  for(int i = 0 ; i < m ; ++i){
	//scanf("%s",&s1);
	cin >> s1;
	cout << dict[s1] <<endl;
	//printf("%s",dict[s1]);
  }
  return 0;
}


