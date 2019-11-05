
# read_configuration.py 
# this file contains the path configuration variables  
# this function used to read the configuration variables.
import sys
sys.path.append('./python_scripts')

from BuildVariant import *

 
def read_configuration ():

	# source and destination path variables reading from python_scripts/BuildVariant.py

	data = build_configuration ()

	# get the arguments from BuildVariant.py file
	VENDOR_NAME = data['VENDOR_NAME']

	SOURCE_PLATFORM_NAME = data['SOURCE_PLATFORM_NAME']
	SOURCE_PLATFORM_VARIANT_NAME = data['SOURCE_PLATFORM_VARIANT_NAME']

	TARGET_PLATFORM_NAME = data['TARGET_PLATFORM_NAME']
	TARGET_PLATFORM_VARIANT_NAME = data['TARGET_PLATFORM_VARIANT_NAME']
	SOURCE_ANDROID_PATH_DIR = data['SOURCE_ANDROID_PATH_DIR']
	TARGET_ANDROID_PATH_DIR = data['TARGET_ANDROID_PATH_DIR']
	print(TARGET_ANDROID_PATH_DIR)
	
	data = {
	
	"src_dir_device"              : SOURCE_ANDROID_PATH_DIR + "/device/fsl/" + SOURCE_PLATFORM_NAME ,
	"src_dir_vendor"              : SOURCE_ANDROID_PATH_DIR + "/vendor",
	"src_dir_frameworks"          : SOURCE_ANDROID_PATH_DIR + "/frameworks",
	"src_dir_common"              : SOURCE_ANDROID_PATH_DIR + "/device/fsl",
	"src_dir_system"	      : SOURCE_ANDROID_PATH_DIR + "/system",
	"src_dir_external"            : SOURCE_ANDROID_PATH_DIR + "/external",
	"src_dir_build"               : SOURCE_ANDROID_PATH_DIR + "/build",
	"src_dir_device_variant"      : SOURCE_ANDROID_PATH_DIR + "/device/fsl/" + SOURCE_PLATFORM_NAME + "/" + SOURCE_PLATFORM_VARIANT_NAME,
	
	"dst_dir_device"              : TARGET_ANDROID_PATH_DIR + "/device" ,
	"dst_dir_vendor"              : TARGET_ANDROID_PATH_DIR + "/vendor" ,
	"dst_dir_system"	      : TARGET_ANDROID_PATH_DIR + "/system",
	"dst_dir_frameworks"          : TARGET_ANDROID_PATH_DIR + "/frameworks",
	"dst_dir_external"            : TARGET_ANDROID_PATH_DIR + "/external",
	"dst_dir_build"               : TARGET_ANDROID_PATH_DIR + "/build",
	"dst_dir_kernel"              : TARGET_ANDROID_PATH_DIR + "/device/common/common_imx/build/",
	
	"src_mk_AndroidBoard"         : SOURCE_ANDROID_PATH_DIR + "/device/fsl/" + SOURCE_PLATFORM_NAME + "/"+ SOURCE_PLATFORM_VARIANT_NAME + "/AndroidBoard.mk" ,
	"src_mk_Boardconfig"          : SOURCE_ANDROID_PATH_DIR + "/device/fsl/"+ SOURCE_PLATFORM_NAME + "/"+ SOURCE_PLATFORM_VARIANT_NAME + "/BoardConfig.mk" ,
	"src_mk_variant"              : SOURCE_ANDROID_PATH_DIR + "/device/fsl/"+ SOURCE_PLATFORM_NAME + "/"+ SOURCE_PLATFORM_VARIANT_NAME + "/"+ SOURCE_PLATFORM_VARIANT_NAME +".mk" ,
	"src_mk_BoardConfigCommon"    : SOURCE_ANDROID_PATH_DIR + "/device/fsl/" + SOURCE_PLATFORM_NAME + "/BoardConfigCommon.mk", 
	"src_mk_ProductConfigCommon"  : SOURCE_ANDROID_PATH_DIR + "/device/fsl/"+ SOURCE_PLATFORM_NAME + "/ProductConfigCommon.mk",
	"dst_mk_Imxpathconfig"        : TARGET_ANDROID_PATH_DIR + "/device/common/common_imx/imx_path/ImxPathConfig.mk",
	}
	

	return data

