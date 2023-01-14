#include <stdio.h>
#include <math.h>

int abs(int n){
    if(n >= 0) return n;
    return n * (-1);
}


int main(){
    int test_cases;
    int M,N,x,y;
    int temp;
    int key;
    int min_value, max_value;
    int min_remainder, max_remainder;
    int minus;
    scanf("%d",&test_cases);
    for(int cases = 0 ; cases < test_cases ; ++cases){
        scanf("%d %d %d %d",&M, &N, &x, &y);
        key = -1;
        if(M > N) {min_value = N; min_remainder = y; max_remainder = x; max_value = M;}
        else {min_value = M; min_remainder = x; max_value = N; max_remainder = y;}
        for(int i = 0 ; i < max_value ; ++i){
            temp = i * min_value + min_remainder;
            if(temp % max_value == max_remainder%max_value){
                key = temp;
                break;
            }
        }
        if(key == -1){
            printf("-1\n");
            continue;
        }
        printf("%d\n", key);
    }
    return 0;
}
