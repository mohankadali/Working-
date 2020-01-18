import math
area  = []
radii = [1,5,9,6,8,21,3,12]

l = len(radii)

for x in range(0,l):
    area1  = math.pi * (radii[x])*(radii[x])
    area.append(area1)    
print area 






