#include <bits/stdc++.h>
#define N_MAX 20

using namespace std;

typedef struct Block{
  int x, y;
  int num;
  bool state;
}Block;

int N;

int Board[N_MAX][N_MAX];

vector<Block> Move_Blocks(int oper, vector<Block> Nums__){
  //oper == 0 -> up

}


void DFS(int cnt, vector<Block> Nums_){
  if(cnt == 10) return;
  vector<Block> Orignal;
  copy(Nums_.begin(), Nums_.end(), Orignal);
  for(int i = 0 ; i < 4 ; ++i){
	DFS(cnt + 1, Move_Blocks(i, vector<Block> Nums_));
  }
}

int main(){
vector<Block> Nums;
  int temp;
  cin >> N;
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < N ; ++j){
	  cin >> temp;
	  if(temp == 0) continue;
	  Board[i][j] = temp;
	  Nums.push_back({.x = i, .y = j, .num = temp, .state = false});
	}
  }
  DFS(0, Nums);
