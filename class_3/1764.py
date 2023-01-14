import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dict_n = {}
dict_ans = []
count = 0
for i in range(n):
    temp = input().rstrip()
    dict_n[temp] = 1
for i in range(m):
    temp = input().rstrip()
    try:
        if dict_n[temp] == 1:
            count += 1
            dict_ans.append(temp)
    except:
        continue
print(count)
dict_ans.sort()
for i in range(count):
    print(dict_ans[i])

