from collections import OrderedDict as Dic

Dic.dict1 = {}

while(1):
    print "1.Push\t2.Pop\t3.Displa\t4.Quit"
    op = raw_input("Enter operation\n")
    if op == "1":
        key = raw_input("Enter the key to be pushed\n")
        value = raw_input("Enter the value to be pushed\n")
        Dic.dict1[key] = value
    if op == "2":
        lstkey = Dic.dict1.keys()[-1]
        ele = Dic.dict1.pop(lstkey)
        print ele
    if op == "3":
        print Dic.dict1
    if op == "4":
        break

