from replace import *
from config_file import *


data = config ()

if str(sys.argv[5]) == "qcom":

	source = data['source_qcom_AndroidBoard']
	target = data['target_qcom_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'AndroidBoard.mk'
	temp_target = data['target_qcom_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'
	
	replace(target,temp_target, str(sys.argv[1])+'/common' , '/common/common_qcom')
	replace(target,temp_target, 'bootable/bootloader/lk' , 'device/'+ str(sys.argv[1])+'/uboot')
	replace(target,temp_target, 'kernel' , 'device/'+str(sys.argv[1])+ '/'+ str(sys.argv[2])+'-kernel')
	replace(target,temp_target, '$(TARGET_KERNEL_SOURCE)/AndroidKernel.mk' , 'device/'+str(sys.argv[1])+ '/'+ str(sys.argv[2])+'-kernel/AndroidKernel.mk')
	exit(1)

source = data['source_AndroidBoard']
target = data['target_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'AndroidBoard.mk'
temp_target = data['target_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'

print(str(sys.argv[1]))
print(target)

try:
	copyfile(source, target)
except IOError as e:
	print("Unable to copy file. %s" % e)
	exit(1)
except:
	print("Unexpected error:", sys.exc_info())
	exit(1)

print("\nFile copy done for " + str(sys.argv[1]))

replace(target, temp_target, '/fsl/', '/')
replace(target, temp_target, '/common/', '/common/common_imx/')

