string = raw_input("Enter a string\n")
#string.sort(iiii)
list1 = []
for  i in range(len(string)):
    list1.append(string[i])
list1.sort()
print list1
string = ""
for i in range(len(list1)):
    string = string + str(list1[i])
print string
