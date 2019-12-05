# replace.py 
# this file used to define a replace function for relapce the content.

import os
import json
from shutil import copyfile
from sys import exit
import sys

# below function use four arguments
# target      : filename
# temp_target : temporary file to modify the content 
# src         : content from vendor   
# dst         : content requisted by user   

def replace (target, temp_target, src, dst):
	f_in = target
	f_out = temp_target
	with open(f_in, "rt") as fin:
		with open(f_out, "wt") as fout:
			for line in fin:
				fout.write(line.replace(src, dst))
	os.rename(f_out, f_in)
