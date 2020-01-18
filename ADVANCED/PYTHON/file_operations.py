fd = open("sample.txt","r+")

str = fd.read(10);
print str
position = fd.tell()
print "currentposition :",position
