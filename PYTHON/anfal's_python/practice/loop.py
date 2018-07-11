var = 0
while var <= 100 :
	if var % 2 == 0 :
		print "even numbers : ", var
		var += 1
	elif var == 99 or var == 89 or var == 79 or var == 69 or var == 59 or var == 49 or var == 39 or var == 29 or var == 19 or var == 9:  
		var += 1
		continue
	else :
		print "odd numbers : ", var
		var += 1

print "bye ....!!"

