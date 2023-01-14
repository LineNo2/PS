n, r = input().split()
n = int(n) 
r = int(r) 
d = [[0 for i in range(101)] for j in range(101)]
d[1][0] = 1
d[1][1] = 1
for i in range(2,n+1):
    d[i][0] = 1
    for j in range(1,i):
        # print("d[" + str(i-1) + "][" + str(j-1) + "] = " + str(d[i-1][j-1]))
        # print("d[" + str(i-1) + "][" + str(j) + "] = " + str(d[i-1][j]))
        d[i][j] = (d[i-1][j-1] + d[i-1][j])
        # print("d[" + str(i) + "][" + str(j) + "] = " + str(d[i][j]))
    d[i][i] = 1
print(d[n][r])
