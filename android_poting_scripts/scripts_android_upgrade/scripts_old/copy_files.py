from replace import *
from distutils.dir_util import copy_tree
from config_file import *

data = config ()

# copying files for qcom

if str(sys.argv[5]) == "qcom":
	source = data['SRC_DIR_device']+'/'+ str(sys.argv[3])+'/'+ 'common'
	target = data['target_qcom_device']+'/common'+'/common_qcom'
	copy_tree(source,target)

	source = data['SRC_DIR_device']+'/'+ str(sys.argv[3])+'/'+ 'sepolicy'
	target = data['target_qcom_device']+ '/' + str(sys.argv[1]) + '/' + 'sepolicy'
	copy_tree(source,target)

	source = data['SRC_DIR_device']+'/'+ str(sys.argv[3])+'/'+ 'wlan'
	tarsource_qcom_kernelget = data['target_qcom_device']+ '/' + str(sys.argv[1]) + '/' + 'wlan'
	copy_tree(source,target)

	source = data['SRC_DIR_device']+'/'+ str(sys.argv[3])+'/'+ 'qssi'
	target = data['target_qcom_device']+ '/' + str(sys.argv[1]) + '/' + 'qssi'
	copy_tree(source,target)

	source = data['SRC_DIR_device']+'/'+ str(sys.argv[3])+'/'+ str(sys.argv[4])
	target = data['target_qcom_device']+ '/' + str(sys.argv[1]) + '/' + str(sys.argv[2])
	copy_tree(source,target)
	os.rename (target + '/' + str(sys.argv[4]) + '.mk', target + '/' + str(sys.argv[2]) + '.mk') 

	source = data['SRC_DIR_VENDOR']+'/'+ str(sys.argv[3])+'/build'
	target = data['target_qcom_vendor']+ '/' + str(sys.argv[1]) + '/build'
	copy_tree(source,target)

	source = data['SRC_DIR_VENDOR']+'/'+ str(sys.argv[3])+'/opensource'
	target = data['target_qcom_vendor']+ '/' + str(sys.argv[1]) + '/opensource'
	copy_tree(source,target)

	source = data['SRC_DIR_VENDOR']+'/'+ str(sys.argv[3])+'/proprietary'
	target = data['target_qcom_vendor']+ '/' + str(sys.argv[1]) + '/proprietary'
	copy_tree(source,target)
	os.remove (data['target_qcom_vendor']+ '/' + str(sys.argv[1]) + '/proprietary/common/config/device-vendor.mk')

	source = data['SRC_DIR_VENDOR']+'/'+ str(sys.argv[3])+'/proprietary/common/' + str(sys.argv[4]) + '/BoardConfigVendor.mk'
	target = data['target_qcom_vendor']+ '/' + str(sys.argv[1]) + '/' +  str(sys.argv[2]) + '/BoardConfigVendor.mk'
	copyfile(source,target)
	os.remove (data['target_qcom_vendor']+'/'+ str(sys.argv[3])+'/proprietary/common/' + str(sys.argv[4]) + '/BoardConfigVendor.mk')

	source = data['source_qcom_kernel']
	target = data['target_qcom_device']+ '/' + str(sys.argv[1]) + '/' + str(sys.argv[2]) + '-kernel' 
	copy_tree(source,target)

	source = data['source_qcom_bootloader']
	target = data['target_qcom_device']+ '/' + str(sys.argv[1]) + '/uboot'
	copy_tree(source,target)

	source = data['SRC_DIR_hardware'] + '/' + str(sys.argv[3])
	target = data['TARGET_DIR_hardware']+ '/' + str(sys.argv[1])
	copy_tree(source,target)
		
	source = data['SRC_DIR_VENDOR']+'/'+ str(sys.argv[3])+'/proprietary/common/config/device-vendor.mk'
	target = data['target_qcom_vendor']+ '/' + str(sys.argv[1]) + '/' + str(sys.argv[2]) + '/device-vendor.mk'
	copyfile(source,target)
	
#	os.remove (data['target_qcom_device'] + '/' + str(sys.argv[1]) + '/' + str(sys.argv[2]) + '/' + str(sys.argv[4])+'.mk')
	os.remove (data['target_qcom_device'] + '/' + str(sys.argv[1]) + '/' + str(sys.argv[2]) + '/device.mk')
	exit(1)

############################################################################################

# copying files for nxp

#source = data['SRC_DIR_VENDOR']+'/'+'nxp-opensource'+'/'+'kernel_imx'
#target = data['target_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'-'+'kernel'
#copy_tree(source,target)
#print ("file copied successfuly from" + str(source) + "to" + str(target))

source = data['SRC_DIR_DEVICE']+'/'+  str(sys.argv[4])
target = data['target_device']+ '/' + str(sys.argv[1]) + '/' + str(sys.argv[2])
copy_tree(source,target)
os.rename (target + '/' + str(sys.argv[4]) + '.mk', target + '/' + str(sys.argv[2]) + '.mk') 



source = data['SRC_DIR_DEVICE']+'/'+'init.recovery.freescale.rc' 
target = data['target_device']+'/'+str(sys.argv[1])+'/'+'init.recovery.freescale.rc'
copyfile(source, target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_DEVICE']+'/'+'etc'
target = data['target_device']+'/'+str(sys.argv[1])+'/'+'etc'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))



source = data['SRC_DIR_DEVICE']+'/'+'sepolicy'
target = data['target_device']+'/'+str(sys.argv[1])+'/'+'sepolicy'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_COMMON']+'/'+'common'
target = data['target_device']+'/'+'common'+'/'+'common_imx'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))



#source = data['SRC_DIR_VENDOR']+'/'+'nxp-opensource'+'/'+'uboot-imx'
#target = data['target_device']+'/'+str(sys.argv[1])+'/'+'uboot'
#copy_tree(source,target)
#print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_VENDOR']+'/'+'nxp-opensource'+'/'+'fsl_imx_demo'
target = data['target_vendor']+'/'+'nxp-opensource'+'/'+'fsl_imx_demo'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))

source = data['SRC_DIR_VENDOR']+'/'+'nxp-opensource'+'/'+'imx'
target = data['target_vendor']+'/'+'nxp-opensource'+'/'+'imx'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_VENDOR']+'/'+'nxp-opensource'+'/'+'imx-lib'
target = data['target_vendor']+'/'+'nxp-opensource'+'/'+'imx-lib'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_VENDOR']+'/'+'nxp-opensource'+'/'+'imx-mkimage'
target = data['target_vendor']+'/'+'nxp-opensource'+'/'+'imx-mkimage'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_VENDOR']+'/'+'nxp-opensource'+'/'+'libdrm-imx'
target = data['target_vendor']+'/'+'nxp-opensource'+'/'+'libdrm-imx'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))

source = data['SRC_DIR_VENDOR']+'/'
target = data['target_vendor']+'/'
#copy_tree(source,target)
myCmd = "cp -rf " + source + "nxp" + " " + target + "/"
os.system (myCmd)
print ("file copied successfuly from" + str(source) + "to" + str(target))

#fstab files copying into AOSP code



source = data['SRC_DIR_SYSTEM']+'/'+'core'+'/'+'fs_mgr'
target = data['TARGET_DIR_SYSTEM']+'/'+'core'+'/'+'fs_mgr'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_SYSTEM']+'/'+'tools'+'/'+'bpt'
target = data['TARGET_DIR_SYSTEM']+'/'+'tools'+'/'+'bpt'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_FRAMEWORKS']+'/'+'av'
target = data['TARGET_DIR_FRAMEWORKS']+'/'+'av'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))

source = data['SRC_DIR_EXTERNAL']+'/'+'tinyalsa'+'/include'+'/tinyalsa'+'/asoundlib.h'
target = data['TARGET_DIR_EXTERNAL']+'/'+'tinyalsa'+ '/include'+'/tinyalsa'+'/asoundlib.h'
copyfile(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_EXTERNAL']+'/'+'cyw-fmac-fw'
target = data['TARGET_DIR_EXTERNAL']+'/'+'cyw-fmac-fw'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_EXTERNAL']+'/'+'cyw-fmac-nvram'
target = data['TARGET_DIR_EXTERNAL']+'/'+'cyw-fmac-nvram'
copy_tree(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))


source = data['SRC_DIR_BUILD']+'/'+'make'+'/core'+'/soong_config.mk'
target = data['TARGET_DIR_BUILD']+'/'+'make'+'/'+'/core'+'/soong_config.mk'
copyfile(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))

source = data['SRC_DIR_BUILD']+'/'+'soong'+'/android'+'/variable.go'
target = data['TARGET_DIR_BUILD']+'/'+'soong'+'/android'+'/variable.go'
copyfile(source,target)
print ("file copied successfuly from" + str(source) + "to" + str(target))
