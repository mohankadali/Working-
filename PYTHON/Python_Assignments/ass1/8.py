import re

inp = "size Hharzia mize Jjfdjizt fize Eeta"
#inp = raw_input("Enter the input\n")
list1 =  map(lambda inp:inp,inp.split())
print list1
list2 = filter(lambda x: x[-3:] == "ize",list1)
print list2


list2 = filter(lambda x: 'z' in x,list1)
print list2

list2 = filter(lambda x: 'zt' in x,list1)
print list2

list2 = filter(lambda x: x.istitle(),list1)
print list2

#list2 = filter(lambda x: x.title(),list1)
#print list2


