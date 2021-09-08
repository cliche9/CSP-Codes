n = int(input())

nums = list(map(int, input().split()))

nums.sort()

length = len(nums)
middle = 0
if length % 2 == 0:
    middle = (nums[length // 2 - 1] + nums[length // 2]) / 2
    if middle % 1 == 0.0:
        middle = int(middle)
    else:
        middle = format(middle, ".1f")
else:
    middle = nums[length // 2]

print('%d %s %d' % (nums[-1], str(middle), nums[0]))