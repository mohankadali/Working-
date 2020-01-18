num = input()

def fun1(num):
    if(num is 0):
        return 1
    else:
        return fun1(num) * fun1(num-1)

res = fun1(num)
print res

