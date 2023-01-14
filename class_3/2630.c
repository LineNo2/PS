#include <stdio.h>
#include <math.h>


int paper[129][129];
int paper_type[2];


int inspect_paper(int n, int x, int y){
  int temp = paper[x][y];
  for(int i = x ; i < x + n; ++i){
	for(int j = y ; j < y + n ; ++j){
	  if(temp != paper[i][j]) return 0;
	}
  }
  return 1;
}

void cut_paper(int n, int x, int y){
  if(inspect_paper(n, x, y)){
	++paper_type[paper[x][y]];
	return;
  }
  if(inspect_paper(n/2, x, y)){
	++paper_type[paper[x][y]];
  }else{ cut_paper(n/2, x, y); }

  if(inspect_paper(n/2, x, y + n/2)){
	++paper_type[paper[x][y + n/2]];
  }else{ cut_paper(n/2, x, y + n/2); }

  if(inspect_paper(n/2, x + n/2, y)){
	++paper_type[paper[x + n/2][y]];
  }else{ cut_paper(n/2, x + n/2, y); }

  if(inspect_paper(n/2, x + n/2, y + n/2)){
	++paper_type[paper[x + n/2][y + n/2]];
  }else{ cut_paper(n/2, x + n/2, y + n/2); }
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; ++i){
	for(int j = 0 ; j < n ; ++j){
	  scanf("%d",&paper[i][j]);
	}
  }
  cut_paper(n, 0, 0);
  printf("%d\n%d", paper_type[0], paper_type[1]);

}
