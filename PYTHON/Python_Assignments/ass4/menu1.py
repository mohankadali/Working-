import ops
import math
#try:
fp = open("ops1.txt", "r")
inp = ["sin","cos","powerof","squareroot"]
inp1 = ["+","-","\*","/"]

try:
    for line in fp:
        list1 = line.split()
        if list1[1] in inp1:
            list1[0] = int(list1[0])
            list1[2] = int(list1[2])
        else:
            list1[1] = int(list1[1])
        if list1[1] == "+":
            ops.add(list1[0],list1[2])
        if list1[1] == "-":
            ops.sub(list1[0],list1[2])
        if list1[1] == "\*":
            ops.mul(list1[0],list1[2])
        if list1[1] == "/":
            ops.div(list1[0],list1[2])
        if not(list1[1] in inp1):
            st1 = [i for i in inp if i in list1]
            if st1[0] == inp[0]:
                ops.sine(list1[1])
            if st1[0] == inp[1]:
                ops.cosine(list1[1])
            if st1[0] == inp[2]:
                ops.powerof(list1[1],int(list1[2]))
            if st1[0] == inp[3]:
                ops.squareroot(list1[1])
except:
    print "File not found"
