def factorial(num):
    if num > 0:
        return num * factorial(num - 1)
    else:
        return 1

def recur_fibo(n):
    if n <= 1:
        return n
    else:
        return(recur_fibo(n-1) + recur_fibo(n-2))


def gcd(num1,num2):
    div = num1 %  num2
    if div != 0:
        num1 = num2
        num2 = div
        gcd(num1,num2)
    else:
        print num2
gcd(num1,num2)

def lcm(num1,num2):
    if num1 > num2:
        greater = num1
    else:
        greater = num
    if ((greater % num1 == 0) and (greater % num2 == 0)):
        lcm = greater
        break
    greater += 1
    return lcm


inp = input("Enter a number\n")
if inp <= 0:
     print("enter a positive integer")
else:
    print("Sequence of Fibonacci:")
    for i in range(inp):
        print(recur_fibo(i))
