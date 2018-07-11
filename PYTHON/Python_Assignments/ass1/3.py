inpstring = raw_input("Enter a string\n")
vcount = 0
vowels = ['a','e','i','o','u']
for letter in inpstring:
    if letter in vowels:
        vcount = vcount + 1
print "Vowels count is", vcount 
print "Consonants count is", len(inpstring) - vcount

reversestr = ""
for i in range(len(inpstring)-1,-1,-1):
    reversestr = reversestr + inpstring[i] 
if inpstring == reversestr:
    print "String is palindrome"
else:
    print "String is not palindrome"

if not(inpstring[i] in vowels):
    piglatin = inpstring[1:]
    piglatin = piglatin+(inpstring[0])+"ay"
    print piglatin
else:
    print "String is starting with vowel"

