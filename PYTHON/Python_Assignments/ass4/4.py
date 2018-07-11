#! /usr/bin/python
import sys

if sys.argv[1] == "head":
    try:
        fp = open(sys.argv[2],"r+")
        str1 = fp.read()
        list1 =  str1.split("\n")
        try:
            for i in range(10):
                print list1[i]
        except IndexError:
                pass
    except IOError:
        print "File not found"
elif sys.argv[1] == "tail":
    try:
        fp = open(sys.argv[2],"r+")
        str1 = fp.read()
        list1 =  str1.split("\n")
        list2 = []
        cnt = 0
        for j in reversed(list1):
            if cnt == 11:
                break
            list2.append(j)
            cnt += 1
        try:
            for i in reversed(list2):
                print i
        except:
            pass
    except IOError:
        print "File not found"
elif sys.argv[1] == "nl":
    try:
        fp = open(sys.argv[2],"r+")
        str1 = fp.read()
        list1 =  str1.split("\n")
        try:
            cnt = 1
            for i in range(len(list1) - 1):
                print "\t"+str(cnt)+" "+list1[i]
                cnt += 1
        except IndexError:
                pass
    except IOError:
        print "File not found"
else:
    print "Entered wrong option"
