fd = open("sample.txt")

'''
for var in fd:
        print var 
'''

res = fd.readlines()
print res
print len(res)
