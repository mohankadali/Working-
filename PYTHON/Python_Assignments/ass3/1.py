fp = open("file.txt","r")

count = 0
for line in fp:
    for word in line.split():
        count = count + 1
print count 
