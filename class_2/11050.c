#include <stdio.h>

int factorial(int n){
    if ( n == 1 ) return 1;
    else return n*factorial(n-1);
    }

int main()
    {
    int n, r;
    scanf("%d %d", &n,&r);
    printf("%d",factorial(n)/(factorial(n-r)*factorial(r)));
    return 0;
    }
