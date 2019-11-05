from replace import *
from config_file import *

data = config ()

if str(sys.argv[5]) == "qcom":
	source = data['source_qcom_Boardconfig']
	target = data['target_qcom_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'BoardConfig.mk'
	temp_target = data['target_qcom_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'
	
	replace (target, temp_target, '$(QCPATH)/common', 'vendor/' + str(sys.argv[1]))
	replace (target, temp_target, '/' + str(sys.argv[3]), '/' + str(sys.argv[1]))
	replace (target, temp_target, '/' + str(sys.argv[4]), '/' + str(sys.argv[2]))
	replace (target, temp_target, '/common', '/common/common_qcom')

	replace (target, temp_target, '$(TARGET_PRODUCT)', str(sys.argv[2]))

	replace (target, temp_target, '$(TARGET_BOARD_PLATFORM)', str(sys.argv[2]))
	exit(1)


source = data['source_Boardconfig']
target = data['target_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'BoardConfig.mk'
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

pro_config = 'vendor'+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'BoardConfigVendor.mk'
replace (target, temp_target, 'device/fsl/'+str(sys.argv[3]) +'/BoardConfigCommon.mk', pro_config)

replace (target, temp_target, '/'+str(sys.argv[4]), '/'+ str(sys.argv[2]))

replace (target, temp_target, '/'+str(sys.argv[3]), '/'+ str(sys.argv[1]))

replace (target, temp_target, '/fsl/', '/')
replace(target, temp_target, '/common/', '/common/common_imx/')
