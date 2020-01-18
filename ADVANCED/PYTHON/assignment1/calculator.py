import math

print '1.Simple\n 2.Scientific\n 3.Exit'
print 'Enter your choice:'
num = input();
if(num == 1):
	print 'Enter first number:\t'
	num1 = input();
	print 'Enter second number:\t'
	num2 = input();
	print ' 1. Addition\n 2. Substraction\n 3. Multiplication\n 4. Division\n'
	print 'Enter your choice:'
	z = input();
	if z == 1:
		print num1+num2
	elif z == 2:
		print num1-num2
	elif z == 3:
	        print num1*num2
	elif z == 4:
	        print num1/num2
	else:
		print "wrong choice"
	
elif(num == 2):
	print '1. sin\n2. cos\n3. power of\n4. sqaure root'
	print 'Enter your choice:'
	z = input();
	if z == 1:
		print 'Enter number:\t'
		num1 = input();
		print 'Sin value for given number is: ',math.sin(num1)
	elif z == 2:
		print 'Enter number:\t'
		num1 = input();
		print 'Cosine value for given number is: ',math.cos(num1)
	elif z == 3:
		print 'Enter number:\t'
		num1 = input();
		print 'Enter number:\t'
		num2 = input();
	        print 'Power value for given number is: ',pow(num1, num2)
	elif z == 4:
		print 'Enter number:\t'
		num1 = input();
		print 'Square root of given number is: ',math.sqrt(num1)
	else:
		print "wrong choice"
	


