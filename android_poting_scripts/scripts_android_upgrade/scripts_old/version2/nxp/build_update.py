# build_update.py
# copy the contents from patch to AOSP build directory   
import sys
sys.path.append('./python_scripts')
from replace import *
from distutils.dir_util import copy_tree
from read_configuration import *
cwd = os.getcwd()

# reading the configuration variables 

data = read_configuration ()


print("build_update.py executing from : "+ cwd +'/nxp')
print("\n")
source = data['src_dir_build']+'/'+'make'+'/core'+'/soong_config.mk'
target = data['dst_dir_build']+'/'+'make'+'/'+'/core'+'/soong_config.mk'


print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copyfile(source,target)
print ("file copied successfuly....\n")


source = data['src_dir_build']+'/'+'soong'+'/android'+'/variable.go'
target = data['dst_dir_build']+'/'+'soong'+'/android'+'/variable.go'


print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copyfile(source,target)
print ("file copied successfuly....")

