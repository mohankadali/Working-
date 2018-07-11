def tail_print(file_nm):
        lines = file_nm.readlines();
	len_line = len(lines)
        i = 0
        for i in range((len_line-10),len_line):
                print lines[i]

file_nm = open("stack.py", "r")
tail_print(file_nm)
                   
