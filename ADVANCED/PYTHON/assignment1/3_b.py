str1 = raw_input('Enter String: ')
l = len(str1) - 1
i = 0
flag = 0
while(l > i):
    if(str1[i] == str1[l]):
        i = i + 1
        l = l - 1
        flag = 1
    else:
        flag = 0
        break
if(flag == 0):
    print 'Not a palindrome'
else:
    print 'string is palindrome'

