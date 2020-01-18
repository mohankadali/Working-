ip = raw_input()

var = ip.split('.')
print var

i = 0
l = len(var)
print l
if(l is 4):
    while(i<l):
        var[i] = int(var[i])
        if(var[i] >= 0 and var[i] <= 255 ):
            i = i+1 
            if(i == 4):
                print "valid"
        else:
            print "not valid"
            break

else:
    print "not valid"
