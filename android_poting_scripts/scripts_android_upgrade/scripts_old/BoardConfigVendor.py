from replace import *
from config_file import *

data = config ()

if str(sys.argv[5]) == "qcom":
	target = data['target_qcom_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'BoardConfigVendor.mk'
	temp_target = data['target_qcom_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'
   
	replace (target, temp_target, '/' + str(sys.argv[3]), '/'+ str(sys.argv[1]))
	replace (target, temp_target, '/' + str(sys.argv[4]), '/'+ str(sys.argv[2]))
	exit(1)

source = data['source_BoardConfigCommon']
target = data['target_vendor']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'BoardConfigVendor.mk'
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

replace (target, temp_target, '/fsl/'+str(sys.argv[3]), '/'+ str(sys.argv[1]))
