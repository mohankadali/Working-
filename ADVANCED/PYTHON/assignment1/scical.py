#to print calculator ,menu

import os
import scicalop
import math
import pdb
#pdb.set_trace()

y = z = 0
x = int(input('1. simple calc\
               2. sci calc\
               3. exit\n'))
os.system('clear')
ch = "y"
while ( ch is "y"):
    if x == 1:
	        	y = int(input('simple calc-------------------\n1. add\
            	    	                               2. sub\
	                                               3. mul\
                                                       4. div\
                                                       5. terminate\n'))
                	if y == 1:
                		print 'enter a, b values to add'
        	        	a = int(input('enter a value\n'))
                		b = int(input('enter b value\n'))
            	        	print 'sum of numbers is:', scicalop.add(a, b)
                	elif y == 2:
	                	print 'enter a, b values to sub'
            	        	a = int(input('enter a value\n'))
	                 	b = int(input('enter b value\n'))
                		print 'sub of numbers is:', scicalop.sub(a, b)
                	elif y == 3:
                		print 'enter a, b values to mul'
                		a = int(input('enter a value\n'))
                		b = int(input('enter b value\n'))
                		print 'mul of numbers is:', scicalop.mul(a, b)
                        elif y == 4:
	                 	print 'enter a, b values to divide'
                		a = int(input('enter a value\n'))
                		b = int(input('enter b value\n'))
                		print 'div of numbers is:', scicalop.div(a, b)
    if x == 2:
		z = int(input('sci calc-----------------------\n1. sin\
               2. cos\
               3.power of\
               4. square root\
	       5. go back\n'))
	        if z == 1:
	        	degrees = int(input('enter degrees to find sine \n'))
  	            	print 'sine if given degree is:', scicalop.sine(degrees)
            	elif z == 2:
	        	degrees = int(input('enter degrees to find cos \n'))
		        print 'cos of given degree is:', scicalop.cosine(degrees)
	        elif z == 3:
		        num = int(input('enter number to find power \n'))
		        p = int(input('enter power\n'))
    	  	        print 'power of given number is:', scicalop.power(num, p)
                elif z == 4:
		        num = int(input('enter number to find sqrt\n'))
		        print 'sqrt of given number is:', scicalop.sqrot(num)
    if x == 3:
        break
    print "if u want to continue press Y"
    ch = raw_input()
print "THANK YOU"		
		
		


