fib_dict = {}

def fibo_recur(n):
    if n == 1 or n == 2 : return 1
    if n == 0 : return 0
    fib_n = fib_dict.get(n)
    if fib_n != None:
        return fib_n%1000000007
    if n % 2 == 0:
        a = n//2
        fib_a = fib_dict.get(a)
        if fib_a == None:
            fib_a = fibo_recur(a)
            fib_dict[a] = fib_a
        fib_1 = fib_dict.get(a-1)
        if fib_1 == None:
            fib_1 = fibo_recur(a-1)
            fib_dict[a-1] = fib_1
        temp = fib_a + fib_1
        fib_dict[a+1] = temp
        fib_dict[n] = fib_1*fib_a%1000000007 +temp*fib_a%1000000007
    else:
        a = (n-1)//2
        b = n - a
        fib_a = fib_dict.get(a)
        if fib_a == None:
            fib_a = fibo_recur(a)
            fib_dict[a] = fib_a
        fib_b = fib_dict.get(b)
        if fib_b == None:
            fib_b = fibo_recur(b)
            fib_dict[b] = fib_b
        fib_dict[n] =fib_a*fib_a%1000000007 + fib_b*fib_b%1000000007
    return fib_dict[n] 
    
n = int(input().split()[0])
print(fibo_recur(n)%1000000007)
