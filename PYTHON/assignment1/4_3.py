#Factorial program using recursion
def factorial(n):
   """Function to return the factorial
   of a number using recursion"""
   if n == 1:
       return n
   else:
       return n*factorial(n-1)

#Fibonacci series 
def fibonacci(n):
    if(n <= 1):
        return n
    else:
        return(fibonacci(n-1) + fibonacci(n-2))

n = int(input("Enter number of terms:"))
print("Fibonacci sequence:")

for i in range(n):
    print fibonacci(i)

#greatest common divisor 
from fractions import gcd
def gcd_of_mn(m,n):
	x = gcd(m,n)
	return x
#least common multiple 
def lcm_of_mn(a, b):
     return a * b / gcd(a, b)



num = input('Enter number to calculate factorioal')
fact = factorial(num)
print 'Factorial of number is:',fact

m = input('Enter value for m: ')
n = input('Enter value for n: ')
gcommon = gcd_of_mn(m,n)
print 'GCD for m and n: ',gcommon

lcommon = lcm_of_mn(m,n)
print 'LCM for m and n: ',lcommon





