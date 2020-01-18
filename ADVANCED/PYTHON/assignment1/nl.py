def nl_print(file_nm):
        lines = file_nm.readlines();
        i = 0
        for i in range(0,len(lines)):
                print `i`+"\t"+lines[i]

file_nm = open("stack.py", "r")
nl_print(file_nm)                   
