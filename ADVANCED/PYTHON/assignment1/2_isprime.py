num = input()

c = 0 
for var in range(1,num+1):
    if(num % var is 0):
        c = c+1
       # var = var + 1
if(c is 2):
    print "yes"
else:
    print "no"




