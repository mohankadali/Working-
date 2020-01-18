n = raw_input("Enter file name\n")
fp = open(n,"r+")
sw = raw_input("Enter a word to search\n")
rw = raw_input("Enter a word to replace\n")

whole = fp.read()
print whole
whole = whole.replace(sw,rw)
fp = open(n,"w+")
fp.write(whole)
fp.close()
