import re

#number = input("Enter number\n")
def isprime(number):
    prime = 0
    for i in range(2,(number/2)+1):
        if ((number%i) == 0):
            prime = 1
            break
    if prime == 1:
        print "Number is not prime"    
    else:
        print "Number is Prime"

#isprime(number)



#number = raw_input("Enter number to check whether it is armstrong\n")

def armstrong(number):
    num1 = 0
    #print number[0]
    for i in range(len(number)):
        num1 = (int(number[i])**len(number)) + num1
    if int(number) == num1:
        print "Number is armstrong"
    else:
        print "Number is not armstrong"
#armstrong(number)



#ip_addr = raw_input("Enter ip address\n")
def isipaddr(ip):
    notip = 0
    check = re.match("^(\d{0,3})\.(\d{0,3})\.(\d{0,3})\.(\d{0,3})$", ip)
    if not check:
        print "Starting"
        print "Not a valid ip"
    else:
        list1 = ip.split(".")
        for i in range(len(list1)):
            if (int(list1[i]) < 0) or (int(list1[i]) > 255):
                print "Not a valid ip"
                notip = 1 
                break
        if notip == 0:
            print "Valid ip"
        
#isipaddr(ip_addr)


#year = input("Enter a year\n")
def isleap(year):
    if (year % 400) == 0:    
        print "Leap year"
    elif (year % 100 ) == 0:
        print "First"
        print "Not leap year"
    elif (year % 4 ) == 0:
        print "Leap year"
    else:
        print "Not leap year"
#isleap(year)   



#date = raw_input("Enter a date\n")
def isdate(date):
    check = re.match("^(\d{1,2})-(\d{1,2})-(\d{1,4})$",date)
    if not check:
        print "Starting"
        print "Not a valid date"
    else:
        print "In else"
        list1 = date.split("-")
        #for i in range(3):
        if (int(list1[1]) < 0) or (int(list1[1]) > 12):
            print "Not a valid date"

        elif int(list1[1]) == 2:
            if isleap(int(list1[2])):
                if (int(list1[0]) < 1) or (int(list1[0]) > 29):
                     print "Not a valid date"
                else:
                    print "Valid date"
            else:
                #type(
                if (int(list1[0]) < 1) or (int(list1[0]) > 28):
                    print "Not a valid date"
                else:
                    print "Valid date"
        elif (int(list1[1]) == 8) or not(int(list1[1]) % 2 == 0):
            if (int(list1[0]) < 0) or (int(list1[0]) > 31):
                print "Not a valid date"
            else:
                print "Valid date"
        elif (int(list1[1]) % 2 ) == 0:
            if (int(list1[0]) < 0) or (int(list1[0]) > 30):
                print "Not a valid date"
            else:
                print "Valid date"
    
#isdate(date)        

