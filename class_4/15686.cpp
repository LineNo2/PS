#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int a){
  return a > 0 ? a : -a;
}

int max(int a, int b){
  return a > b ? a : b;
}

typedef struct Point{
  int x;
  int y;
}Point;

int N,M;

int ans = 987654321;

vector<Point> chicken;
int num_of_chickens;
int num_of_elims;
vector<Point> house;

vector<int> dist[100];

bool check[14];

int get_min_dist(int house){
  int min = 987654321;
  for(int i = 0 ; i < num_of_chickens ; ++i){
	if(check[i]) continue;
	if(min > dist[house][i]) min = dist[house][i];
  }
  return min;
}

void get_ans(){
  int sum = 0;
  for(int i = 0 ; i < house.size(); ++i){
	sum += get_min_dist(i);
  }
  if(sum < ans) ans = sum;
}

void select_elim_chickens(int idx, int key){
  if(num_of_elims == idx) {get_ans(); return;}
  for(int i = key ; i < num_of_chickens ; ++i){
	check[i] = true;
	select_elim_chickens(idx + 1, i + 1);
	check[i] = false;
  }
}

int main(){
  int temp;
  cin >> N >> M;
  for(int i = 0 ; i < N ; ++i){
	for(int j = 0 ; j < N ; ++j){
	  cin >> temp;
	  if(temp == 1) house.push_back({.x = i , .y = j});
	  else if(temp == 2) chicken.push_back({.x = i , .y = j});
	}
  }
  num_of_chickens = chicken.size();
  num_of_elims = num_of_chickens - M;
  for(int i = 0 ; i < house.size() ; ++i){
	int house_x = house[i].x;
	int house_y = house[i].y;
	for(int j = 0 ; j < chicken.size() ; ++j){
	  dist[i].push_back( abs(house_x - chicken[j].x) + abs(house_y - chicken[j].y));
	}
  }
  select_elim_chickens(0,0);
  cout << ans;
  return 0;
}
  



