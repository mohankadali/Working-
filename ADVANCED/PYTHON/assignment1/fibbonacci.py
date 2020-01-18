def fibbo(num):
	pre = 1
	pre_pre = 0
	cur = 0
	print pre
	while(cur < num):
		cur = pre + pre_pre
		if(cur<num):
			print cur
		pre_pre = pre
		pre = cur

i = input("Enter limit for fibbonacci")
fibbo(i)
