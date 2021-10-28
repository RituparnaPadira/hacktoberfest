def fibonacci(n):
    a = 1
    b = 1
    if n < 0:
        print("Incorrect input")
    elif n == 0:
        return a
    elif n == 1:
        return b
    else:
        for i in range(2, n):
            c = a + b
            a = b
            b = c
        return b

t = int(input('Enter n: '))
ans = fibonacci(t)
print(f'The {t}th fibonacci number is {ans}')
