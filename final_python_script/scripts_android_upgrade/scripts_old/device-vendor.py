from replace import *
from config_file import *

data = config ()

if str(sys.argv[5]) == "qcom":
	target = data['target_qcom_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'device-vendor.mk'
	temp_target = data['target_qcom_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'

	replace(target, temp_target, '/'+str(sys.argv[3]), '/'+ str(sys.argv[1]))
   
	exit(1)

source = data['source_ProductConfigCommon']
target = data['target_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'device-vendor.mk'
temp_target = data['target_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'

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

print("\nFile copy done!\n")

replace(target, temp_target, '/'+str(sys.argv[3]), '/'+ str(sys.argv[1]))
replace(target, temp_target, '/fsl/', '/')
replace(target, temp_target, '/common/', '/common/common_imx/')
