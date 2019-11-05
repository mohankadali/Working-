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

