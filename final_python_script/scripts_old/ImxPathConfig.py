from replace import *
from config_file import *

data = config ()

if str(sys.argv[5]) == "qcom":
    print ("Copy done for qualcomm")
    exit(1)

target_1 = data['target_Imxpathconfig']
target = data['target_kernel']
temp_target = data['target_kernel']+'temp.txt'

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

