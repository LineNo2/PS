#include <stdio.h>
int gcd(int a,int b){
  return b == 0 ? a : gcd(b, a%b);
}
int lcd(int a,int b){
  return (a * b / gcd(a,b));
}
int main(){
  int num_a, num_b;
  scanf("%d %d", &num_a, &num_b);
  printf("%d\n%d",gcd(num_a,num_b), lcd(num_a, num_b));
  return 0;
}
