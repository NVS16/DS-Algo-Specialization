from sympy import fibonacci as f

def period(b):
    for i in range(1, b*b+1):
        if f(i)%b == 0 and f(i+1)%b == 1:
            return(i)

b = int(input().strip())

print(period(b))