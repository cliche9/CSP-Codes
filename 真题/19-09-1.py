n, m = map(int, input().split())
counts = []
treeNumber = 0
maxLoss = 0

for i in range(n):
    oneTree = list(map(int, input().split()))
    counts.append(sum(oneTree))
    if (oneTree[0] - counts[i] > maxLoss):
        treeNumber = i + 1
        maxLoss = oneTree[0] - counts[i]

print(sum(counts), end=' ')
print(treeNumber, end=' ')
print(maxLoss, end=' ')
