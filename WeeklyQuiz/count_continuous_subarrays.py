from collections import deque

def count_continuous_subarrays(nums):
    n = len(nums)
    left = 0
    min_deque, max_deque = deque(), deque()
    total_subarrays = 0

    for right in range(n):
        # Maintain max deque
        while max_deque and nums[max_deque[-1]] < nums[right]:
            max_deque.pop()
        max_deque.append(right)

        # Maintain min deque
        while min_deque and nums[min_deque[-1]] > nums[right]:
            min_deque.pop()
        min_deque.append(right)

        # If subarray is invalid, move left pointer
        while nums[max_deque[0]] - nums[min_deque[0]] > 2:
            left += 1
            if max_deque[0] < left:
                max_deque.popleft()
            if min_deque[0] < left:
                min_deque.popleft()

        # Count valid subarrays
        total_subarrays += (right - left + 1)

    return total_subarrays

# Input
n = int(input().strip())
nums = list(map(int, input().split()))
print(count_continuous_subarrays(nums))
