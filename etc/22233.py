import sys
input = sys.stdin.readline

def sol():
    _ = int(input())
    arr = list(map(int, input().split()))
    DP = [ [arr[0]] for _ in range(2)]
    ans = 0 
    for idx, value in enumerate(arr[1:]):
        DP[0].append(max(value, value +  DP[0][idx]))
        DP[1].append(max(DP[1][idx] + value, DP[0][idx]))
    ans = max(map(max, DP))
    print(DP)
    print(ans)

sol()

