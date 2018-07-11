def armstrong(num):
	div = 0
	sum_of = 0
	temp = num
	while(temp > 0):
		sum_of =sum_of + ((temp%10) * (temp%10) * (temp%10))
		temp = temp/10
	if(sum_of == num):
		return num
	return 0

i = 0
res = 0
for i in range(1, 500):
	res = armstrong(i)
	if(res != 0):
		print res
