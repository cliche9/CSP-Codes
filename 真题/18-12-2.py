r, y, g = map(int, input().split())

n = int(input())

def getTime(k, t, time):
    # 直接通过
    if k == 0:
        return t
    # 红灯
    elif k == 1:
        if t > time:
            return t - time
        else:
            return getTime(3, g, time - t)
    # 黄灯
    elif k == 2:
        if t > time:
            return t - time + r
        else:
            return getTime(1, r, time - t)
    # 绿灯
    else:
        if t > time:
            return 0
        else:
            return getTime(2, y, time - t)

res = 0
for i in range(n):
    k, t = map(int, input().split())
    res += getTime(k, t, res % (r + g + y))

print(res)