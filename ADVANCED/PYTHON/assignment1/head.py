def head_print(file_nm):
	lines = file_nm.readlines();
	i = 0
	for i in range(0,10):
		print lines[i]

file_nm = open("stack.py", "r")
head_print(file_nm)
