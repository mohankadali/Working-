def f():
    global s
    print (s)
    s = "in"
    print(s)

s = "out" 

f()
print(s)
