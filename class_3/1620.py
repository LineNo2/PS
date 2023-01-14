import sys
input = sys.stdin.readline

n, q = map(int, input().split())
dict_name = {}
dict_num = []
for i in range(n):
    temp = input()
    dict_name[temp] = i + 1
    dict_num.append(temp)
for i in range(q):
    temp = input().rstrip()
    if temp.isdigit():
        print(dict_num[int(temp)-1])
    else:
        print(dict_name[temp])

