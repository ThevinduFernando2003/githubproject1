def binary(nums,start, end):
    middle = (start+end)//2
    
    if nums[middle]== 0 :
        return middle
    elif nums[middle] > 0:
        return binary(nums, start, middle-1)
    else:
        return binary(nums, middle+1, end)

def findDepth(n, nums):
    return binary(nums, 0, n-1)
    
    
n = int(input())
nums = list(map(int, input().split()))
result = findDepth(n, nums)
print(result+1)