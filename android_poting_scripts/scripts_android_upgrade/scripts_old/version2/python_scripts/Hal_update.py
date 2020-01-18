# Hal_update.py
# this file is common for all the vendors and depends on vendor name argument it will execute the vendor specific python scripts 

import os
import sys
from distutils.dir_util import copy_tree

cwd = os.getcwd()

# executing python scripts for NXP

if str(sys.argv[5]) == "nxp":
	cmd = 'python3 '+cwd+'/nxp/hal_update.py'+' '+ str(sys.argv[1]) +' '+str(sys.argv[2])+' '+str(sys.argv[3])+' '+str(sys.argv[4])+' '+str(sys.argv[5])
	if os.system(cmd) == 0:
		print("hal_update.py exicuted.........\n")
	else:
		print("hal_update.py failed !!!!\n")
		exit(1)


# executing python scripts for qcom

elif str(sys.argv[5]) == "qcom":
	cmd = 'python3 '+cwd+'/qcom/hal_update.py'+' '+ str(sys.argv[1]) +' '+str(sys.argv[2])+' '+str(sys.argv[3])+' '+str(sys.argv[4])+' '+str(sys.argv[5])
	if os.system(cmd) == 0:
		print("hal_update.py exicuted.........\n")
	else:
		print("hal_update.py failed !!!!\n")
		exit(1)

# if vendor name is not present will move to else condition

else:
        print ("platform is not supported.....\n")

