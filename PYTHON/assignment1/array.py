num_of_rows = int ( input ('Enter Number of rows: ') )
num_of_cols = int ( input ('Enter Number of columns: ') )
list1 = []

for i in range( 0, num_of_rows ) :
    list1.append([])
    for j in range ( 0, num_of_cols ) :
        list1[i].append ( i * j )

print 'Array elements are:  '
print ( list1 )
