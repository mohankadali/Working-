year = input()

if(year % 4 is 0):
#    print "leap year"
 
    if((year%100 is not 0) or (year%400 is 0)):
        print "leap year"
    else:
        print "not a leap year"
else:
    print "not a leap year"





