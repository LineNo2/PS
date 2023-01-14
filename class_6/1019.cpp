#include <bits/stdc++.h>

using namespace std;

int N;

int Count[10];

int get_0(int m, int k){
  if(k == 0) return 0;
  if(m == 0 && k == 1) return 0 ;
  if(k == 1) return 9;
  return m * k * (int)pow(10,k-1) + get_0(9,k-1);
}

void get_natural(int m, int k){
  for(int i = 1 ; i <= m ; ++i){
	Count[i] += k*(int)pow(10,k-1)*(m+1) + (int)pow(10,k);
  }
  for(int i = m + 1 ; i < 10 ; ++i){
	Count[i] += (m+1)*k*(int)pow(10,k-1);
  }
}

void get_integer(int m, int k){
  for(int i = 0 ; i <= m ; ++i){
	Count[i] += k*(int)pow(10,k-1)*(m+1) + (int)pow(10,k);
  }
  for(int i = m + 1 ; i < 10 ; ++i){
	Count[i] += (m+1)*k*(int)pow(10,k-1);
  }
}

void Rec(int n){
  if(n == 0) return;
  ++Count[n%10];
  Rec(n/10);
}

int get_length(int n){
  if(n == 0) return 0;
  return 1 + get_length(n/10);
}

int main(){
  int Original_N;
  cin >> N;
  Original_N = N;
  int k = get_length(N) - 1;
  int m = N/(int)pow(10,k) - 1;
  N -= (m+1)*(int)pow(10,k);
  //printf("N : %d, m : %d, k : %d)\n",N,m,k);
  Count[0] = get_0(m, k);
  get_natural(m, k);
  Count[m+1] += N + 1;
  for(; k > 0;){
	--k;
	m = N/(int)pow(10, k) - 1;
	N -= (m+1)*(int)pow(10,k);
	//printf("N : %d, m : %d, k : %d)\n",N,m,k);
	Count[m+1] += N + 1;
	get_integer(m, k);
  }
  if(9 <= Original_N  && Original_N <= 99)
	Count[0] = Original_N/10;
  for(int i = 0 ; i < 10 ; ++i)
	cout << Count[i] << " ";
  return 0;
}
  

