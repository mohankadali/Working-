a = [[10,20],[30,40]]

b = [[1,2],[3,4]]
sum  = [[0,0],[0,0]]
for var in range(2):
    for var1 in range(2):
        sum[var][var1] = a[var][var1] + b[var][var1] 

print sum

