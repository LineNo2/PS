#include <stdio.h>
#include <math.h>

int main() {
    int n;
    char temp;
    long long hash_sum=0;
    long long M = 1234567891;
    int r = 31;
    scanf("%d\n",&n);
    for( int i = 0 ; i < n ;++i){
        temp = getchar();
        hash_sum += (long long)(pow(r,i)*(temp-'a' + 1));
        }
    printf("%lld",hash_sum%M);
    return 0;
    }
