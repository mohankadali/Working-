# external_update.py
# copy the contents from patch to AOSP external directory 
import sys
sys.path.append('./python_scripts')
from replace import *
from distutils.dir_util import copy_tree
from read_configuration import *
cwd = os.getcwd()

# reading the configuration variables
data = read_configuration ()

print("external_update.py executing from : "+ cwd +'/nxp' +"\n")

# need to update asoundlib.h in AOSP external directory for audio tinyalsa  

source = data['src_dir_external']+'/'+'tinyalsa'+'/include'+'/tinyalsa'+'/asoundlib.h'
target = data['dst_dir_external']+'/'+'tinyalsa'+ '/include'+'/tinyalsa'+'/asoundlib.h'

print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copyfile(source,target)
print ("file copied successfuly....\n")

# need to add cyw-fmac-fw in AOSP external directory for wifi

source = data['src_dir_external']+'/'+'cyw-fmac-fw'
target = data['dst_dir_external']+'/'+'cyw-fmac-fw'

print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")

# need to add cyw-fmac-nvram in AOSP external directory for wifi

source = data['src_dir_external']+'/'+'cyw-fmac-nvram'
target = data['dst_dir_external']+'/'+'cyw-fmac-nvram'

print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")


