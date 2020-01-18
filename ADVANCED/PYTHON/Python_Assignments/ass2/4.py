list1 = [[1,2],[3 ,4],[5 ,6]]
result = [[0,0,0],[0,0,0]]

def transpose(list1, result):
    for i in range(len(list1)):
        for j in range(len(list1[0])):
            result[j][i] = list1[i][j]
    print "Transpose"
    for r in result:
        print(r)
transpose(list1,result)


list2 = [[7,8],[9,10],[11,12]]
add1 = [[0,0],[0,0],[0,0]]


def add(list1, list2):
    for i in range(len(list1)):
        for j in range(len(list1[0])):
            add1[i][j] = list1[i][j] + list2[i][j]
    print "Addition"
    for r in add1:
        print r
add(list1,list2)


list2 = [[7,8],[9,10]]
add1 = [[0,0],[0,0],[0,0]]
print list1,list2
result = [[0,0],[0,0],[0,0]]
for i in range(len(list1)):
    for j in range(len(list2[0])):
        for k in range(len(list2)):
            result[i][j] += list1[i][k] * list2[k][j]
for r in result:
    print(r)
