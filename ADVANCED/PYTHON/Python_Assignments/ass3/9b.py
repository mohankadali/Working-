import sys

path1 = sys.argv[1] 
path2 = sys.argv[2]
fp = open(path1,"r")
string = fp.read()
fp1 = open(path2,"w+")
fp1.write(string)
