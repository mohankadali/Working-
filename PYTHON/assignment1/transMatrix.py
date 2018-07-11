rows = int(input("Enter the rows"))

cols = int(input("Enter the cols"))

mat = [[0 for j in range(cols)] for i in range(rows)]

trans =  [[0 for j in range(rows)] for i in range(cols)]


print "Enter elements of matrix"
for i in range(rows):
	for j in range(cols):
		mat[i][j] = int(raw_input())

for i in range(rows):
	for j in range(cols):
		if i != j :
			trans[j][i] = mat[i][j]
		else :
			trans[i][j] = mat[i][j]

print trans," is add ition of matrices"

