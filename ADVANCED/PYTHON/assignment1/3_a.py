str1=raw_input ("enter a string:")
vowels=0
space = 0
for i in str1:
      if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u' or i=='A' or i=='E' or i=='I' or i=='O' or i=='U'):
          vowels=vowels+1
      elif i is " ":
          space = space + 1 

print"Number of vowels are:", vowels
#x=len(str1)
#print x
print"no. of cons are:", len(str1) - vowels - space
