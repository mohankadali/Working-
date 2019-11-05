from replace import *
from config_file import *


data = config ()

if str(sys.argv[5]) == "qcom":
	target = data['target_qcom_device']+'/common/common_qcom/'
	temp_target = data['target_qcom_device']+'/common/common_qcom/temp.txt'
	
	replace(target+'common.mk', temp_target, '/qcom/common' , '/common/common_qcom')
	replace(target+'common64.mk', temp_target, '/qcom/common' , '/common/common_qcom')
	
	exit(1)
