print 'This is to perform stack operations:'
print 'press 1 to push, 2 to pop, 3 to dispaly, 4 to quit'

x = []
i = 0
choice = 0
while(choice != 4):
	choice = int(input('enter numbers between 1 to 4\n'))
	if choice == 1:
		data = int(input('enter data to be pushed\n'))
		x.append(data)
		i += 1
	elif choice == 2:
		i -= 1
		x.pop(i)
	else:
		print x



