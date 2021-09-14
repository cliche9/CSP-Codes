r, y, g = map(int, input().split())

n = int(input())

res = 0
for i in range(n):
    k, t = map(int, input().split())
    if k == 0:
        res += t
    elif k == 1:
        res += t
    elif k == 2:
        res += t + r

print(res) 