                #### map using function ####


'''
import math
radd = [1,5,9,6,8,21,3,12]
def area(r):
    return math.pi * (r ** 2)

#area1 = list(map(area,radd))
area1 =  (map(area,radd))
print area1
'''

                #### map using lambda ####


'''
import math
radd = [1,5,9,6,8,21,3,12]
area1 = map(lambda r : math.pi * (r ** 2),radd)
print type(area1)
'''

                ####  filters usisg lambda ####
'''
list1 = [1,5,9,6,8,21,3,12]
div3 = filter(lambda x : (x % 3) is 0 ,list1)
print div3

'''
                ####  filters usisg functions  ####
'''
list1 = [1,5,9,6,8,21,3,12]
def fun(x):
    if(x % 3 is 0):
        return x

div3 = filter(fun,list1)

print div3
''' 


                ####  reduce usisg lambda  ####

list1 = [1,2,3,4,5,6,7,8,9]

res = reduce ( lambda x,y: x+y ,list1[2:5])

print res











            
































