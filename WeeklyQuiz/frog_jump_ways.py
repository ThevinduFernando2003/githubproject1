def frog_jump_ways(N):
    if N <= 1:
        return 0
    if N == 2:
        return 1  # Only one way: (2)
    if N == 3:
        return 1  # Only one way: (3)

    # DP array to store ways to reach each step
    dp = [0] * (N + 1)
    
    # Base cases
    dp[2] = 1
    dp[3] = 1

    # Fill the dp array using the recurrence relation
    for i in range(4, N + 1):
        dp[i] = dp[i - 2] + dp[i - 3]

    return dp[N]

# Read input
N = int(input().strip())
print(frog_jump_ways(N))
