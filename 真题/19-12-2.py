n = int(input())

position = []

for i in range(n):
    position.append(list(map(int, input().split())))

def isLegal(point):
    if position.count([point[0] + 1, point[1]]) and \
       position.count([point[0] - 1, point[1]]) and \
       position.count([point[0], point[1] + 1]) and \
       position.count([point[0], point[1] - 1]):
       return True
    return False 

offset = [-1, 1]
result = [0, 0, 0, 0, 0]

for point in position:
    if isLegal(point):
        count = 0
        for i in offset:
            if position.count([point[0] + i, point[1] + i]):
                count += 1
            if position.count([point[0] - i, point[1] + i]):
                count += 1
        result[count] += 1

for count in result:
    print(count)
