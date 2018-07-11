s = 'Mahesh Chougule'#string on which we are going to perform operations
n = 5	#number of characters
o = 4	#offset
#returns n characters from left side of the string
def left(s, n):
    return s[:n]

#returns n characters from right side of the string 
def right(s, n):
    return s[-n:]

#returns middle characters of the string
def mid(s, o, n):
    return s[o:o+n]

#returns the reverse string 
def reverse(s):
	return s[::-1]

#count the number of vowels of the string
def count_vowels(s):
	i = 0
	l = len(s) 
	count = 0
	while i<l:
		if s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o'or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O'or s[i]=='U':
			count = count + 1;
			i = i + 1
		else:
			i = i + 1
	return count
#count number of consonants of the string
def count_consonants(s):
        l = len(s)
	j = 0
	count2 = 0
        while j<l:
                if s[j]=='a' or s[j]=='e' or s[j]=='i' or s[j]=='o'or s[j]=='u' or s[j]=='A' or s[j]=='E' or s[j]=='I' or s[j]=='O'or s[j]=='U':
                	j = j + 1
                else:
                        count2 = count2 + 1;
                        j = j + 1			
	return count2

#All the functions call for the functions defined above
str1 = left(s,n)
str2 = right(s,n)
str3 = mid(s,o,n)
str4 = reverse(s)
vowel = count_vowels(s)
conso = count_consonants(s)


print 'Left',str1
print 'Right',str2
print 'Middle',str3
print 'Reversed string:',str4
print 'number of vowels',vowel
print 'number of consonents',conso
