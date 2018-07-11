str1 = "GoE GjE GgE G7E"
import re
#print re.findall("GE",str1)
#print re.findall("^GE",str1)
#print re.findall("GE$",str1)
print re.findall("G[a-zA-Z]E",str1)
print re.findall("G.E",str1)
