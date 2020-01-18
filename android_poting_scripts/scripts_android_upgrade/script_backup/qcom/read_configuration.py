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
	"src_dir_kernel"              : SOURCE_ANDROID_PATH_DIR + "/kernel/msm-3.18",
        "src_dir_bootloader"          : SOURCE_ANDROID_PATH_DIR + "/bootable/bootloader/lk",
        "src_dir_hardware"            : SOURCE_ANDROID_PATH_DIR + "/hardware",
        "src_dir_vendor"              : SOURCE_ANDROID_PATH_DIR + "/vendor",
        "src_dir_device"              : SOURCE_ANDROID_PATH_DIR + "/device",
        "dst_dir_hardware"            : TARGET_ANDROID_PATH_DIR + "/hardware",   
        "dst_dir_vendor"              : TARGET_ANDROID_PATH_DIR + "/vendor" ,
        "dst_dir_device"              : TARGET_ANDROID_PATH_DIR + "/device" ,
        "dst_dir_path"                : TARGET_ANDROID_PATH_DIR ,
	"src_mk_AndroidBoard"         : SOURCE_ANDROID_PATH_DIR + "/device/" + SOURCE_PLATFORM_NAME + "/"+ SOURCE_PLATFORM_VARIANT_NAME + "/AndroidBoard.mk" ,
	"src_mk_Boardconfig"          : SOURCE_ANDROID_PATH_DIR + "/device/"+ SOURCE_PLATFORM_NAME + "/"+ SOURCE_PLATFORM_VARIANT_NAME + "/BoardConfig.mk" ,		
	"src_mk_variant"              : SOURCE_ANDROID_PATH_DIR + "/device/" + SOURCE_PLATFORM_NAME + "/"+ SOURCE_PLATFORM_VARIANT_NAME + "/"+SOURCE_PLATFORM_VARIANT_NAME +".mk" ,
	"src_mk_BoardConfigVendor"    : SOURCE_ANDROID_PATH_DIR + "/vendor/"+ SOURCE_PLATFORM_NAME +"/proprietary/common/"+ SOURCE_PLATFORM_VARIANT_NAME +"BoardConfigVendor.mk", 
	"src_mk_device-vendor"        : SOURCE_ANDROID_PATH_DIR + "/vendor/"+ SOURCE_PLATFORM_NAME +"/proprietary/common/config/device-vendor.mk"
	}

	return data

