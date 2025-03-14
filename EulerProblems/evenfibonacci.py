def fibonacci(limit):
    lister = [1,2]
    while lister[-1] + lister[-2] <= limit:
        lister.append(lister[-1] + lister[-2])
    return lister

def evenfib():
    sum = 0
    fib_list = fibonacci(4000000)
    for num in fib_list:
        if( num % 2 == 0):
            sum += num
    return sum

even_fib_sum = evenfib()
print(even_fib_sum)