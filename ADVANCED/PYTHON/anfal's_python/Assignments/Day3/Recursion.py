print "enter option : "
print "1]. factorial 2]. fibonacci 3]. gcd 4]. lcm " 
op = input()
if op == 1:
	def fact_num(num) :
		if num == 1 : 
			return num;
		else :
			return num * fact_num(num-1)
	print "enter number : "
	num = input()
	print fact_num(num)
elif op == 2:
	def fibonacci(num):
	    if(num <= 1):
        	return num
    	    else:
        	return(fibonacci(num-1) + fibonacci(num-2))
	print "enter n value "
	num = input()
	for i in range(num):
	    print fibonacci(i)
elif op == 3:
	def gcd(num1,num2):
	    	if(num2 == 0):
        		return num1
	    	else:
        		return gcd(num2,num1%num2)
	
	print "Enter num1 value:"
	num1 = input()
	print "Enter num2 value:"
	num2 = input()
	print gcd(num1,num2)
elif op == 4:
	def lcm(a,b):
		lcm.multiple=lcm.multiple+b
    		if((lcm.multiple % a == 0) and (lcm.multiple % b == 0)):
		        return lcm.multiple;
		else:
		        lcm(a, b)
			return lcm.multiple
	lcm.multiple=0
	print "enter num1 value"
	num1 = input()
	print "enter num2 value"
	num2 = input()
	if(num1 > num2):
    		LCM=lcm(num2, num1)
	else:
	 	LCM=lcm(num1, num2)
	print (LCM)
else :
	print "Wrong option"	
