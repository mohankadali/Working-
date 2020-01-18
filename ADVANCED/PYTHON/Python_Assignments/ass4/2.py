def histogram(list1):
    out = ['+','-']
    for i in range(len(list1)):
        if list1[i] > 0:
            print [out[0] for i in range(list1[i])]
        elif list1[i] < 0:
            print  [out[1] for i in range((list1[i] - 2*list1[i]))]
        else:
            print "Entered 0"
print "Enter values of a list"
inp = [int(x) for x in raw_input().split()]
print inp
histogram(inp)
