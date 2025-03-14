#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getTotalX' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b


def getTotalX(a, b):
    # Write your code here
    lcm_a = a[0]
    for num in a[1:]:
        lcm_a = (lcm_a * num) // math.gcd(lcm_a, num)
    
    # Find GCD of the second array
    gcd_b = b[0]
    for num in b[1:]:
        gcd_b = math.gcd(gcd_b, num)
    
    # Count multiples of lcm_a that are factors of gcd_b
    count = 0
    multiple = lcm_a
    while multiple <= gcd_b:
        if gcd_b % multiple == 0:
            count += 1
        multiple += lcm_a

    return count


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    fptr.write(str(total) + '\n')

    fptr.close()
