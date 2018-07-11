str1 = "GE GE GE GE"

import re
print re.findall("GE",str1)
print re.findall("^GE",str1)
print re.findall("GE",str1)
print re.findall("^GE",str1)
print re.findall("GE$",str1)
print re.findall("^GE$",str1)

str2 = "abcd abbcd abbbcd acd"
print re.findall("ab*cd",str2)
print re.findall("ab+cd",str2)
print re.findall("ab-cd",str2)
