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

print("platform_update.py executing from : "+ cwd +'/nxp'+"\n")


#copying uboot directory from older version of vendor to AOSP P
print ("......copying uboot......................\n")
source = data['src_dir_vendor']+'/'+'nxp-opensource'+'/'+'uboot-imx'
target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+'uboot'
print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")



#copying kernel directory from older version of vendor to AOSP P
print ("......copying kernel.......................\n")
source = data['src_dir_vendor']+'/'+'nxp-opensource'+'/'+'kernel_imx'
target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'-'+'kernel'
print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n") 



#copying varinat directories and files 
source = data['src_dir_device']+'/'+  str(sys.argv[4])
target = data['dst_dir_device']+ '/' + str(sys.argv[1]) + '/' + str(sys.argv[2])
print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
os.rename (target + '/' + str(sys.argv[4]) + '.mk', target + '/' + str(sys.argv[2]) + '.mk')
print ("file copied successfuly....\n")



source = data['src_dir_device']+'/'+'init.recovery.freescale.rc'
target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+'init.recovery.freescale.rc'
print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copyfile(source,target)
print ("file copied successfuly....\n")



# copying etc directory 
source = data['src_dir_device']+'/'+'etc'
target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+'etc'
print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")



# copying sepolicy directory
source = data['src_dir_device']+'/'+'sepolicy'
target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+'sepolicy'
print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")



# copying common directory 
source = data['src_dir_common']+'/'+'common'
target = data['dst_dir_device']+'/'+'common'+'/'+'common_imx'
print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")
	


# copying vendor  nxp-opensource directory 
source = data['src_dir_vendor']+'/'+'nxp-opensource'+'/'+'fsl_imx_demo'
target = data['dst_dir_vendor']+'/'+'nxp-opensource'+'/'+'fsl_imx_demo'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....\n")

source = data['src_dir_vendor']+'/'+'nxp-opensource'+'/'+'imx'
target = data['dst_dir_vendor']+'/'+'nxp-opensource'+'/'+'imx'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....\n")

source = data['src_dir_vendor']+'/'+'nxp-opensource'+'/'+'imx-lib'
target = data['dst_dir_vendor']+'/'+'nxp-opensource'+'/'+'imx-lib'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly...\n")

source = data['src_dir_vendor']+'/'+'nxp-opensource'+'/'+'imx-mkimage'
target = data['dst_dir_vendor']+'/'+'nxp-opensource'+'/'+'imx-mkimage'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....\n")

source = data['src_dir_vendor']+'/'+'nxp-opensource'+'/'+'libdrm-imx'
target = data['dst_dir_vendor']+'/'+'nxp-opensource'+'/'+'libdrm-imx'
print ("source path:="+str(source))
print ("target path:="+str(target))
copy_tree(source,target)
print ("file copied successfuly....\n")


# copying vendor nxp directory 
source = data['src_dir_vendor']+'/'
target = data['dst_dir_vendor']+'/'
print ("source path:="+str(source))
print ("target path:="+str(target))
myCmd = "cp -r " + source + "nxp" + " " + target + "/"
os.system (myCmd)
print ("file copied successfuly....\n")



#AndroidBoard file changes
source = data['src_mk_AndroidBoard']
target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'AndroidBoard.mk'
temp_target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'
replace(target, temp_target, '/fsl/', '/')
replace(target, temp_target, '/common/', '/common/common_imx/')



# BoardConfigVendor file changes
source = data['src_mk_BoardConfigCommon']
target = data['dst_dir_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'BoardConfigVendor.mk'
temp_target = data['dst_dir_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'
copyfile(source, target)
replace (target, temp_target, '/fsl/'+str(sys.argv[3]), '/'+ str(sys.argv[1]))



#Boardconfig file changes
source = data['src_mk_Boardconfig']
target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'BoardConfig.mk'
temp_target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'

pro_config = 'vendor'+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'BoardConfigVendor.mk'
replace (target, temp_target, 'device/fsl/'+str(sys.argv[3]) +'/BoardConfigCommon.mk', pro_config)
replace (target, temp_target, '/'+str(sys.argv[4]), '/'+ str(sys.argv[2]))
replace (target, temp_target, '/'+str(sys.argv[3]), '/'+ str(sys.argv[1]))
replace (target, temp_target, '/fsl/', '/')
replace(target, temp_target, '/common/', '/common/common_imx/')
	


# device_vendor file changes        
source = data['src_mk_ProductConfigCommon']
target = data['dst_dir_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'device-vendor.mk'
copyfile(source, target)
temp_target = data['dst_dir_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'
replace(target, temp_target, '/'+str(sys.argv[3]), '/'+ str(sys.argv[1]))
replace(target, temp_target, '/fsl/', '/')
replace(target, temp_target, '/common/', '/common/common_imx/')



#ImxPathConfig file changes
target_1 = data['dst_mk_Imxpathconfig']
target = data['dst_dir_kernel']
temp_target = data['dst_dir_kernel']+'temp.txt'

with open(target_1,"r+") as f:
	new_f = f.readlines()
	f.seek(0)
	for line in new_f:
        	if "KERNEL_IMX_PATH" not in line and "UBOOT_IMX_PATH" not in line:
            		f.write(line)

	f.truncate()

uboot = 'UBOOT_IMX_PATH := device/'+str(sys.argv[1])+'/uboot'
kernel = 'KERNEL_IMX_PATH := device/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'-'+'kernel'
with open(target_1, 'r+') as fh:
 	for line in fh:
       		print(kernel, file=fh)
        	print(uboot, file=fh)
       		break

replace(target + 'kernel.mk', temp_target, '/fsl/common/', '/common/common_imx/')
replace(target + 'kernel.mk', temp_target,'/kernel_imx', '')
replace(target + 'dtbo.mk', temp_target, '/kernel_imx', '')
replace(target + 'uboot.mk', temp_target, '/uboot-imx', '')


#evk_8mq_drm file changes
if str(sys.argv[1]) == 'imx8m':
	target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'evk_8mq_drm.mk'
	temp_target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'
	replace (target, temp_target, '/fsl/'+str(sys.argv[3])+'/'+str(sys.argv[4]), '/'+ str(sys.argv[1])+'/'+str(sys.argv[2]))

#variant.mk
source = data['src_mk_variant']
target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+str(sys.argv[2])+'.mk'
temp_target = data['dst_dir_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'

pro_config = 'vendor'+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'device-vendor.mk'
replace(target, temp_target, 'device/fsl/'+ str(sys.argv[3]) +'/ProductConfigCommon.mk', pro_config)
replace(target, temp_target, str(sys.argv[4]), str(sys.argv[2]))

replace(target, temp_target, '/' + str(sys.argv[3]), '/'+ str(sys.argv[1]))
replace(target, temp_target, 'common', 'common/common_imx')
replace(target, temp_target, '/fsl/', '/')


