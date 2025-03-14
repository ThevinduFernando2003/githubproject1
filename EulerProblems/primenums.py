'''def is_prime(num):
    if num < 2:
        return False
    for i in range(1, int(num**0.5) +1):
        if num % i == 0:
            return False
    return True

def primenumber(limit):
    primes = []
    for num in range(2, limit+1):
        if is_prime(num):
            primes.append(num)
    return primes'''

def largest_prime_factor(n):
    i = 2  # Smallest prime
    while i * i <= n:
        if n % i == 0:
            n //= i  # Reduce n
        else:
            i += 1
    return n

num = 600851475143
print(largest_prime_factor(num))