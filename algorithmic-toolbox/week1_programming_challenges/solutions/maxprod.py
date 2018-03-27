# Uses python3

N = int(input().strip())

nums = list(map(int, input().strip().split(' ')))
nums.sort()

print(nums[N- 2] * nums[N - 1])