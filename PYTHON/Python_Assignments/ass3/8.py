num = input("Enter number\n")
fibo = []
fibo.append(0)
fibo.append(1)
[fibo.append(fibo[i-1]+fibo[i-2]) for i in range(2,num)]
print fibo
