import os
import json
from shutil import copyfile
from sys import exit
import sys

def replace (target, temp_target, src, dst):
	f_in = target
	f_out = temp_target
	with open(f_in, "rt") as fin:
		with open(f_out, "wt") as fout:
			for line in fin:
				fout.write(line.replace(src, dst))
	os.rename(f_out, f_in)
