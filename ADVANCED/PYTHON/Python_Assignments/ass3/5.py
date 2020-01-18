import shutil
import sys

dir1 = raw_input("Enter source path\n") 
dir2 = raw_input("Enter dest path\n")

try:
    shutil.copytree(dir1,dir2)
except:
    print "directory is not copied"
