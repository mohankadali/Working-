string = raw_input("Enter a string\n")
Capital = string.capitalize()
print Capital

cent = string.center(12,"*")
print cent

count = string.count("is",5,10)
print count

str1 = string.encode('base64', 'strict')
print str1
str1 = str1.decode('base64', 'strict')
print str1

text = "Python programming is easy to learn."
result = text.endswith('learn.')
print result
result = text.endswith('learn.', 1,5)
print(result)

str2 = "harika\tge\tharika"
str1 = str2.expandtabs(10)
print str2
print str1

result = string.find("is")
print result
result = string.find("is",6,10)
print result
result = string.rfind("is")
print result
result = string.rfind("is",19,28)
print result


ind =  string.index("is",2,6)
print "ind is\n", ind

alp = "12as kl"
alp1 = "12askl"
print alp.isalnum()
print alp1.isalnum()


num = "123"
print num.isdigit()
num = "adf"
print num.isdigit()
num = "as12"
print num.isdigit()

str1 = "abcdf"
print str1.islower()
str1 = "Avdsfd"
print str1.islower()
str1 = "12sf"
print str1.islower()

str1 = "    "
print str1.isspace()
str1 = ""
print str1.isspace()
str1 = " "
print str1.isspace()
str1 = " a "
print str1.isspace()

str1 = "global edge"
print str1.istitle()
print str1.title()
str2 = "Global Edge"
print str2.istitle()
str1 = "global ed'ge"
print str1.istitle()
print str1.title()


str1 = "GLOBAL"
print str1.isupper()
str1 = "Global"
print str1.isupper()
str1 = "GLOB123"
print str1.isupper()


str1 = "harika"
seper = ' '
print seper.join([str1] * 3)

str1 = "harika"
width = 5
print str1.ljust(width)
print str1.ljust(width,"*")
width = 10
fillchar = "*"
print str1.ljust(width,fillchar)
print str1.ljust(width)

str1 = "HARIKA"
print str1.lower()
str1 = "HariKA"
print str1.lower()


str1 = "      harika"
print str1
print str1.lstrip()


str1 = "first name and last name and full name"
print str1.partition("and")
print str1.partition("quick") 

str1 = "first name and last name and full name"
print str1.replace("and","with")
str1 = "harika"
print str1.replace("a"," ")
print str1.replace("a","b")


print string.rindex("is",2,9)


str1 = "harika"
print str1.rjust(10,"*")
print str1.rjust(10)
print str1.rjust(2)


str1 = "first name and last name and full name"
print str1.rpartition("and")
print str1.rpartition("quick") 


str1 = "first name and last name and full name"
print str1.rsplit()
print str1.rsplit(" ",2)

str1 = "first name and last name and full name"
print str1.split()
print str1.split(" ",2)

str1 = "first name\nsecond name\n third name\n"
a = []
a = str1.splitlines()
print "AFter splitting\n",a
a = str1.splitlines(True)
print a

str1 = "first name and last name and full name"
print str1.startswith("first name")
print str1.startswith(" ")
print str1.startswith("name",6)
print str1.startswith("name and",7,11)

str1 = "    harika   "
print str1.strip()
str1 = "harika swethfa"
print str1.strip("harika")
str1 = "android is awesome"
print str1.strip("an")
print str1.strip("omed")


str1 = "OBject oRiEnted"
print str1.swapcase()

print str1.upper()

print str1.zfill(20)
print str1.zfill(3)


