import re

pswd = raw_input("Enter password\n")
check = 1
while(check):
    if len(pswd) < 8 and len(pswd) > 16:
        break
    elif not re.search("[a-z A-Z]",pswd):
        break
    elif not re.search("[0-9]",pswd):
        break
    elif not re.search("[!@#$%^&*()_+]",pswd):
        break
    else:
        print "Valid password"
        check = 0
        break
if check:
    print "Not a valid Password"
