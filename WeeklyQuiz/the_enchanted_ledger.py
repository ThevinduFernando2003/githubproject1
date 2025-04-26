def four_sum(nums, target):
    nums.sort()  # Sort the numbers to use the two-pointer approach
    n = len(nums)
    result = []

    for i in range(n - 3):  # First fixed number
        if i > 0 and nums[i] == nums[i - 1]:  # Skip duplicates
            continue

        for j in range(i + 1, n - 2):  # Second fixed number
            if j > i + 1 and nums[j] == nums[j - 1]:  # Skip duplicates
                continue

            left, right = j + 1, n - 1  # Two-pointer search
            while left < right:
                current_sum = nums[i] + nums[j] + nums[left] + nums[right]

                if current_sum == target:
                    result.append([nums[i], nums[j], nums[left], nums[right]])

                    # Move both pointers and skip duplicate values
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1

                elif current_sum < target:
                    left += 1  # Increase sum by moving left pointer

                else:
                    right -= 1  # Decrease sum by moving right pointer

    return result

# Read input
nums = eval(input().strip())  # Read the list of numbers
target = int(input().strip())  # Read the target sum

# Compute result
output = four_sum(nums, target)

# Print result
print(output)
