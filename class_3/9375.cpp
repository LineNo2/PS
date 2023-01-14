#include <iostream>
#include <string>
#include <map>

using namespace std;

unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

//ios_base :: sync_with_stdio(false); 
//cin.tie(NULL); 
//cout.tie(NULL);
//
map<string, int> clothes;

int main(){
  int test_cases;
  int n;
  int count;
  string temp_type, temp_name;
  cin >> test_cases;
  for(int cases = 0 ; cases < test_cases ; ++cases){
	cin >> n;
	clothes.clear();
	count = 1;
	if(n == 0) {
	  printf("0\n");
	  continue;
	}
	for(int i = 0 ; i < n ; ++i){
	cin >> temp_name;
	cin >> temp_type;
	if(clothes.find(temp_type) !=  clothes.end())
		++clothes[temp_type]; 
	else{
	  clothes.insert(make_pair(temp_type,1));
	}
	}
	for (auto i = clothes.begin(); i != clothes.end(); i++) {
	  count *= nChoosek(i->second + 1 , 1);
	  //cout << i->second << endl;
	}
	cout << count - 1 << endl;
  }
  return 0;
}

