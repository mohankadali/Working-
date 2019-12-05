
# read_configuration.py 
# this file contains the path configuration variables  
# this function used to read the configuration variables.
import sys
sys.path.append('./python_scripts')

#from BuildVariant import *

 
def read_configuration ():


	f = open ("./python_scripts/BuildVariant.config", "r")
	keylist = []
	SOURCE_PLATFORM_NAME = ""
	SOURCE_PLATFORM_VARIANT_NAME = ""
	SOURCE_ANDROID_PATH_DIR = ""
	TARGET_ANDROID_PATH_DIR = ""
	VENDOR_NAME = ""
	for line in f:
		if "SOURCE_PLATFORM_NAME" in line:
			keylist = line.split ("=")
			SOURCE_PLATFORM_NAME = str(keylist[1]).strip()

		if "SOURCE_PLATFORM_VARIANT_NAME" in line:
			keylist = line.split ("=")
			SOURCE_PLATFORM_VARIANT_NAME = str(keylist[1]).strip()
		if "SOURCE_ANDROID_PATH_DIR" in line:
			keylist = line.split ("=")
			SOURCE_ANDROID_PATH_DIR = str(keylist[1]).strip()
		if "TARGET_ANDROID_PATH_DIR" in line:
			keylist = line.split ("=")
			TARGET_ANDROID_PATH_DIR = str(keylist[1]).strip()
		if "VENDOR_NAME" in line:
			keylist = line.split ("=")
			VENDOR_NAME = str(keylist[1]).strip()


	
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

