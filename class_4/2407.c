#include <stdio.h>
#include <string.h>
#include <math.h>

#define CIPHER_CNT 18


long long CIPHER = pow(10,CIPHER_CNT);

typedef struct BigInt{
  long long high;
  long long low;
}BigInt;

BigInt ll_to_bi(long long li){
  return {0,li};
}

int main(){
  int n, m;

}
