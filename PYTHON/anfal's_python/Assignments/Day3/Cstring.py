print "your option : "
print "1]. left most 2]. right most 3]. midle 4]. str_rev 5]. count_vol 6]. find"
op = input()
if op == 1 :
	def left_n_str(str1, num) :
		return str1[ : num]
	print "enter string :"
	str1 = raw_input()
	print "enter number : "
	num = input()
	print left_n_str(str1,num)
elif op == 2:
	def right_n_str(str1, num) :
		return str1[(len(str1)-num) : ]
	print "enter string :"
	str1 = raw_input()
	print "enter number : "
	num = input()
	print right_n_str(str1,num)
elif op == 3:
	def mid_str(str1, p, n) :
		return str1[p : n]
	print "enter string :"
	str1 = raw_input()
	print "enter numbers for p & n : "
	p = input()
	n = input()
	print mid_str(str1,p,n)
elif op == 4:
	def rev_str(str1):
		return str1[::-1]
	print "enter string :"
	str1 = raw_input()
	print "reverse string : ", rev_str(str1)
elif op == 5 :
	print "enter string : "
	str1 = raw_input()
	vol_str = "aeiouAEIOU"
	vol_count = 0
	leng = len(str1)
	for i in vol_str:
		a = str1.count(i)
		vol_count += a
	print "volwels count in string : ", vol_count
	print "consonants count in string : ", leng - (vol_count)
elif op == 6:
	def count_indices(str1, sub):
		s_str = str1.split();
		start = 0
		arr = []
   		for word in s_str:
			while str1[start] == ' ' :
				start += 1
			if word == sub:
        			arr.append(start) 
			start += len(word)
		return arr
	print "enter main string : "
	str1 = raw_input()
	print "enter sub string : "
	str2 = raw_input() 
	print count_indices(str1, str2)
else :
	print "Wrong option"



	

