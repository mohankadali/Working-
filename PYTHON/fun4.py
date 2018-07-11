list = [12,24,35,70,73,89,120,155]

x = len(list)

for var in range(x):
    if( list[var] % 2 is 0 and list[var] % 5 is 0 ):
        continue
    else:
        print list[var]



