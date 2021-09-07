n = int(input())

fallenTree = []
counts = []

for i in range(n):
    oneTree = list(map(int, input().split()))
    counts.append(oneTree[1])
    hasFallen = 0
    for j in range(2, oneTree[0] + 1):
        if oneTree[j] > 0:
            if counts[i] != oneTree[j]:
                hasFallen = 1
            counts[i] = oneTree[j]
        else:
            counts[i] += oneTree[j]
    fallenTree.append(hasFallen)

res = 0

for i in range(1, n - 1):
    if (fallenTree[i - 1] and fallenTree[i] and fallenTree[i + 1]):
        res += 1

if (fallenTree[n - 1] and fallenTree[0] and fallenTree[1]):
    res += 1

if (fallenTree[n - 2] and fallenTree[n - 1] and fallenTree[0]):
    res += 1

print(sum(counts), end=' ')
print(sum(fallenTree), end=' ')
print(res)