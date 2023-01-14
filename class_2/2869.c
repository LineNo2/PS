#include <stdio.h>
int main(){
  long long up, down, n;
  scanf("%lld %lld %lld",&up,&down,&n);
  printf("%lld", (n - up)/(up - down) +  ( (n - up)%(up-down) ? (long long)2 : (long long)1) );
  return 0;
}
