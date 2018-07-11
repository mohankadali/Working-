fp = open("file.txt","r")
count = 0
for line in fp:
        count += 1
print count
fp.close( )
