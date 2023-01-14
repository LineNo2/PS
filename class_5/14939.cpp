#include <bits/stdc++.h>
#define N_MAX 10

using namespace std;

typedef struct Point{
  int x, y;
  Point operator + (Point &p){
	return {.x = x + p.x, .y = y + p.y};
  }
  bool isInIndex(){
	return (x >= 0 && y >= 0 && x < N_MAX && y < N_MAX);
  }
  bool getArrayValue(bool arr[][N_MAX]){
	return (isInIndex() && arr[x][y]);
  }
  void editArrayValue(bool value, bool arr[][N_MAX]){
	if(!isInIndex()) return;
	arr[x][y] = value;
  }
}Point;

bool Map[N_MAX][N_MAX];

bool Col[N_MAX];

bool captureCol[N_MAX];

FILE *fp;

Point Direction_oper[4] = {
  {.x = -1, .y = 0},
  {.x = 0, .y = 1},
  {.x = 1, .y = 0},
  {.x = 0, .y = -1}};

bool checkDirectionValid(Point p, int direction){
  if(!p.isInIndex()) return false;
  if(p.getArrayValue(Map)){// check diagonal
	if((p+Direction_oper[ (direction+7)% 8 ]).getArrayValue(Map) &&
		((p+Direction_oper[ (direction+1)%8 ]).getArrayValue(Map) ) )
	  return true;
  }
  else{
	if( (p+Direction_oper[(direction+4)%8]).getArrayValue(Map) && 
		(p+Direction_oper[ (direction+6)%8 ]).getArrayValue(Map) &&
		(p+Direction_oper[ (direction+2)%8 ]).getArrayValue(Map) ) 
	  return true;
  }
  return false;
}

int ans = 0;

void printMap(){
  for(int i = 0 ; i < N_MAX ; ++i){
	for(int j = 0 ; j < N_MAX ; ++j){
	  fprintf(fp,"%d", Map[i][j]);
	}
	fprintf(fp,"\n");
  }
}

void toggleSwitch(Point p){
  p.editArrayValue(!p.getArrayValue(Map), Map);
  for(int i = 0 ; i < 4 ;++i){
	Point temp = p + Direction_oper[i];
	temp.editArrayValue(!temp.getArrayValue(Map), Map);
  }
}

bool checkCol(int x){
  for(int i = 0 ; i < 10 ; ++i)
	if(Map[x][i]) return false;
  return true;
}

void DFS(int x, int y, int cnt){
  if(cnt == 10){
	if(Col[p.y - 1]) return;
	if(checkCol(p.y - 1)) Col[p.y - 1] = true;
	printMap();
	for(int i = 0 ; i < N_MAX ; ++i){
	  captureCol[i] = Map[i][p.y];
	}
	return;
  }
  if(cnt == 9) {p.x = 0;++p.y;}
  else ++p.x;
  toggleSwitch(p);
  DFS(p, cnt+1);
  toggleSwitch(p);
  DFS(p, cnt+1);
}

int main(){
  char temp;
  for(int i = 0 ; i < N_MAX ; ++i){
	for(int j = 0 ; j < N_MAX ; ++j){
	  temp = getchar();
	  if(temp == 'O')  Map[i][j] = true;
	}
	getchar();
  }
  fp = fopen("output.txt","w+");
  for(int i = 0 ; i < 9 ; ++i){
	DFS({.x=i,.y=0}, 0);
	if(!Col[i]) { cout << -1; return 0; }
	for(int j = 0 ; j < 10 ; ++j)
	  Map[j][i+1] = captureCol[j];
  }
  for(int i = 0 ; i < N_MAX; ++i)
	for(int j = 0 ; j < N_MAX ; ++j)
	  if(Map[i][j]) { cout << -1; return 0;}
  cout << ans;
  return 0;
}

/*
bool DFS(Point p, int direction, int cnt){
 if(!p.isInIndex()) return false;
  //fprintf(fp,"DFS( {%d, %d} , %d, %d)\n",p.x,p.y,direction,cnt);
  if(cnt == 0){ // begin search
	if(p.getArrayValue(Map) &&
		(p+Direction_oper[0]).getArrayValue(Map) &&
		(p+Direction_oper[2]).getArrayValue(Map) &&
		(p+Direction_oper[4]).getArrayValue(Map) &&
		(p+Direction_oper[6]).getArrayValue(Map)  ){
	  //fprintf(fp,"DFS( {%d, %d} , %d, %d)\n",p.x,p.y,direction,cnt);
	  toggleSwitch(p);
	  ++ans;
	  return true;
	}
	for(int i = 0 ; i < 8 ; ++i){
	  bool return_value = false;;
	  if(checkDirectionValid(p,i))
		return_value = DFS(p + Direction_oper[i], i , 1);
	  if(return_value){
		toggleSwitch(p);
		return true;
	  }
	}
	return false;
  }
  if( direction % 2 ) { // !diagonal
	if(p.getArrayValue(Map)) return false;
	if( (p + Direction_oper[ (direction + 6) % 8 ]).getArrayValue(Map) &&
		(p + Direction_oper[ (direction + 2) % 8 ]).getArrayValue(Map) ){
	  if( (p + Direction_oper[direction]).getArrayValue(Map) ){
		ans += cnt;
		//fprintf(fp,"last - 3\n");
		toggleSwitch(p);
		return true;
	  }
	  bool return_value =  DFS(p + Direction_oper[direction], direction, cnt + 1);
	  if(return_value){
		//fprintf(fp,"last - 2\n");
		toggleSwitch(p);
	  }
	  return return_value;
	}
	return false;
  }
  if(!p.getArrayValue(Map)) return false;
  if( (p + Direction_oper[ (direction + 7)%8 ]).getArrayValue(Map) &&
	  (p + Direction_oper[ (direction + 1)%8 ]).getArrayValue(Map) ){
	ans += cnt;
	//fprintf(fp,"last - 1\n");
	toggleSwitch(p);
	return true;
  }
  bool return_value = DFS(p + Direction_oper[direction], direction, cnt + 1);
  if(return_value) {
	//fprintf(fp, "last\n");
	toggleSwitch(p);
  }
  return return_value;
}*/
