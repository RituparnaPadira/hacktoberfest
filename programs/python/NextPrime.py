def nextPrime(n):
    
    n= n+1
    
    while True:
        
        for i in range(2,n):
            
            if n%i==0:
                break
        else:  #else will execute if loop is exausted without break
            return n
        
        n+=1

t = int(input('Enter number: '))
ans = nextPrime(t)
print(f'Next prime number is {ans}')
