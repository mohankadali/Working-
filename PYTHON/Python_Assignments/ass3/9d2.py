import sys

path1 = sys.argv[1]
path2 = sys.argv[2]
fp1 = open(path1,"r+")
fp2 = open(path2,"w+")
inp = fp1.read()
fp2.write(inp)
fp2.close()
fp2 = open(path2,"r+")
print fp2.read()
