list1 = []

while(1):
    print "1.Push\t2.Pop\t3.Display\t4.Quit"
    op = raw_input("Enter operation\n")
    if op == "1":
        num = input("Enter a number to be pushed\n")
        list1.append(num)
    if op == "2":
        ele = list1.pop()
        print ele
    if op == "3":
        print list1
    if op == "4":
        break

