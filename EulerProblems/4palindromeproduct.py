def isPalindrome(product):
    return str(product) == str(product)[::-1]

def largestPalindrome(start=100, end=999):
    maxPalindrome = 0
    for i in range(end, start, -1):
        for j in range(end, start, -1):
            product = i * j
            if isPalindrome(product) and product > maxPalindrome:
                maxPalindrome = product
    return maxPalindrome

print(largestPalindrome())