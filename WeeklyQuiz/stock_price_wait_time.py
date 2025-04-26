def stock_wait_days(n, prices):
    result = [0] * n  # Initialize result array with zeros
    stack = []  # Monotonic stack to store indices
    
    for i in range(n):
        while stack and prices[i] > prices[stack[-1]]:
            prev_index = stack.pop()  # Get the last index from stack
            result[prev_index] = i - prev_index  # Calculate the waiting days
        stack.append(i)  # Push current index to stack
    
    print(" ".join(map(str, result)))

# Read input
n = int(input())
prices = list(map(int, input().split()))

# Call function
stock_wait_days(n, prices)


