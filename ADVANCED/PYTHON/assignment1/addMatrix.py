
rows = int(input("Enter the rows"))

cols = int(input("Enter the cols"))

mat1 = [[0 for j in range(0)] for i in range(2)]

mat2 = [[0 for j in range(cols)] for i in range(rows)]

add =  [[0 for j in range(cols)] for i in range(rows)]

print mat1
print "Enter elements of frst matrix"
for i in range(rows):
	for j in range(cols):
		mat1[i][j] = int(raw_input())
print "Elemnts of scnd matrix"
for i in range(rows):
	for j in range(cols):
		mat2[i][j] = int(input())

for i in range(rows):
	for j in range(cols):
		add[i][j] = mat1[i][j] + mat2[i][j]

print add," is addition of matrices"




