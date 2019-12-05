from replace import *
from config_file import *


data = config ()

if str(sys.argv[5]) == "qcom":
	target = data['target_qcom_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+str(sys.argv[2])+'.mk'
	temp_target = data['target_qcom_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'
	
	replace(target, temp_target, '/' + str(sys.argv[3]), '/' + str(sys.argv[1]))
	replace(target, temp_target, '/' + str(sys.argv[4]), '/' + str(sys.argv[2]))
	replace(target, temp_target, '/' + str(sys.argv[2]) + '/' + str(sys.argv[2]), '/' + str(sys.argv[4]) + '/' + str(sys.argv[4]))
	replace(target, temp_target, ':= ' + str(sys.argv[4]), ':= '+ str(sys.argv[2]))
	
	replace (target, temp_target, '/qcom/common', '/common/common_qcom')

	target =  data['target_qcom_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/AndroidProducts.mk' 
	replace (target, temp_target, str(sys.argv[4]), str(sys.argv[2]))

	exit(1)

source = data['source_sabresd']
target = data['target_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+str(sys.argv[2])+'.mk'
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

pro_config = 'vendor'+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'device-vendor.mk'
replace(target, temp_target, 'device/fsl/'+ str(sys.argv[3]) +'/ProductConfigCommon.mk', pro_config)

replace(target, temp_target, str(sys.argv[4]), str(sys.argv[2]))

replace(target, temp_target, '/' + str(sys.argv[3]), '/'+ str(sys.argv[1]))
replace(target, temp_target, 'common', 'common/common_imx')
replace(target, temp_target, '/fsl/', '/')

