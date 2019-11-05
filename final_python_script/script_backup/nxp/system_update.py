# system_update.py 
# copy the contents from patch to AOSP system directory 

import sys
sys.path.append('./python_scripts')

from replace import *
from distutils.dir_util import copy_tree
from read_configuration import *
cwd = os.getcwd()

# reading the configuration variables
data = read_configuration ()

print("external_update.py executing from : "+ cwd +'/nxp'+"\n")

# need to update fs_mgr in AOSP system directory for fstab   

source = data['src_dir_system']+'/'+'core'+'/'+'fs_mgr'
target = data['dst_dir_system']+'/'+'core'+'/'+'fs_mgr'

print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")

# need to add bpt tools in AOSP system directory for partitions    

source = data['src_dir_system']+'/'+'tools'+'/'+'bpt'
target = data['dst_dir_system']+'/'+'tools'+'/'+'bpt'

print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")




	

