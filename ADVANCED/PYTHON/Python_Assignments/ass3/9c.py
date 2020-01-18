import sys
fname = sys.argv[1]
fp = open(fname,"r")
string = fp.read()
wc = string.split()
print  len(wc),sys.argv[1]
