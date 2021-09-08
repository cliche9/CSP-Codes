n = int(input())

for i in range(n):
    s = input().replace('x', '*').replace('/', '//')
    if eval(s) == 24:
        print('Yes')
    else:
        print('No')