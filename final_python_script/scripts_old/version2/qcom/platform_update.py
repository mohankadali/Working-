# platform_update.py
# copy the contents from patch to AOSP source code  

import sys
sys.path.append('./python_scripts')
from replace import *
from read_configuration import *
from distutils.dir_util import copy_tree
cwd = os.getcwd()

# reading the configuration variables
data = read_configuration ()

print("platform_update.py executing from : "+ cwd +'/qcom')

source = data['src_dir_device']+'/'+ str(sys.argv[3])+'/'+ 'common'
target = data['dst_dir_device']+'/qcom/common'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")


source = data['src_dir_device']+'/'+ str(sys.argv[3])+'/'+ 'sepolicy'
target = data['dst_dir_device']+ '/' + str(sys.argv[1]) + '/' + 'sepolicy'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")


source = data['src_dir_device']+'/'+ str(sys.argv[3])+'/'+ 'wlan'
target = data['dst_dir_device']+ '/' + str(sys.argv[1]) + '/' + 'wlan'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")


source = data['src_dir_device']+'/'+ str(sys.argv[3])+'/'+ 'qssi'
target = data['dst_dir_device']+ '/' + str(sys.argv[1]) + '/' + 'qssi'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")

source = data['src_dir_device']+'/'+ str(sys.argv[3])+'/'+ str(sys.argv[4])
target = data['dst_dir_device']+ '/' + str(sys.argv[1]) + '/' + str(sys.argv[2])
os.rename (target + '/' + str(sys.argv[4]) + '.mk', target + '/' + str(sys.argv[2]) + '.mk') 
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")

source = data['src_dir_vendor']+'/'+ str(sys.argv[3])+'/build'
target = data['dst_dir_vendor']+ '/' + str(sys.argv[1]) + '/build'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")

source = data['src_dir_vendor']+'/'+ str(sys.argv[3])+'/opensource'
target = data['dst_dir_vendor']+ '/' + str(sys.argv[1]) + '/opensource'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")


source = data['src_dir_vendor']+'/'+ str(sys.argv[3])+'/proprietary'
target = data['dst_dir_vendor']+ '/' + str(sys.argv[1]) + '/proprietary'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")


source = data['src_dir_vendor']+'/nxp'
target = data['dst_dir_vendor']+ '/nxp'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")


source = data['src_dir_vendor']+'/codeaurora'
target = data['dst_dir_vendor']+ '/codeaurora'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")


source = data['src_dir_vendor']+'/google_easel'
target = data['dst_dir_vendor']+ '/google_easel'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")



source = data['src_dir_vendor']+'/google_paintbox'
target = data['dst_dir_vendor']+ '/google_paintbox'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")

#copying kernel directory from older version of vendor to AOSP P
print ("......copying kernel.......................")

source = data['src_dir_kernel']
target = data['dst_dir_path']+ '/kernel/msm-3.18' 
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")

#copying lk directory from older version of vendor to AOSP P
print ("......copying lk.......................")

source = data['src_dir_bootloader']
target = data['dst_dir_path']+ '/bootable/bootloader/lk'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")


#copying qcom  directory from older version of vendor to AOSP P

source = data['src_dir_hardware'] + '/' + str(sys.argv[3])
target = data['dst_dir_hardware']+ '/' + str(sys.argv[1])
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....")

		
	

