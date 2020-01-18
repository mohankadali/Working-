fp = open("file.txt","r+")
offset = input("Enter the offset\n")
string = raw_input("Enter the string to be inserted\n")

fp.seek(offset)
print fp.write(string)
fp.close()
