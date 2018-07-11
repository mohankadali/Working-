x = open("sample.txt")

c =0

for var in x:
    w = var.split()
    c = c + len(w)
print c 

