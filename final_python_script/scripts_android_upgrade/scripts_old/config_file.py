def config ():
	f = open ("python_scripts/BuildVariant.mk", "r")
	keylist = []
	src_manufacturer = ""
	src_device = ""
	src_android_path = ""
	target_android_path = ""
	target_platform = ""

	for line in f:
		if "SOURCE_MANUFACTURER_NAME" in line:
			keylist = line.split (":=")
			src_manufacturer = str(keylist[1]).strip()

		if "SOURCE_DEVICE_NAME" in line:
			keylist = line.split (":=")
			src_device = str(keylist[1]).strip()

		if "SOURCE_ANDROID_PATH" in line:
			keylist = line.split (":=")
			src_android_path = str(keylist[1]).strip()

		if "TARGET_ANDROID_PATH" in line:
			keylist = line.split (":=")
			target_android_path = str(keylist[1]).strip()

		if "TARGET_PLATFORM" in line:
			keylist = line.split (":=")
			target_platform = str(keylist[1]).strip()

	print (src_manufacturer)
	print (src_device)
	print (src_android_path)
	print (target_android_path)
	print (target_platform)

	
	if target_platform == "nxp":	
		data = {
		"source_AndroidBoard"     : src_android_path + "/device/fsl/" + src_manufacturer + "/"+ src_device + "/AndroidBoard.mk" ,
		"target_device"           : target_android_path + "/device" ,
		"target_vendor"           : target_android_path + "/vendor" ,
		"source_Boardconfig"      : src_android_path + "/device/fsl/"+ src_manufacturer + "/"+ src_device + "/BoardConfig.mk" ,
		"source_sabresd"          : src_android_path + "/device/fsl/"+ src_manufacturer + "/"+ src_device + "/"+src_device+".mk" ,
		"source_BoardConfigCommon"    : src_android_path + "/device/fsl/" + src_manufacturer + "/BoardConfigCommon.mk", 
		"source_ProductConfigCommon"  : src_android_path + "/device/fsl/"+ src_manufacturer + "/ProductConfigCommon.mk",
		"target_Imxpathconfig"    : target_android_path + "/device/common/common_imx/imx_path/ImxPathConfig.mk",
		"target_kernel"           : target_android_path + "/device/common/common_imx/build/",
		"SRC_DIR_DEVICE"          : src_android_path + "/device/fsl/" + src_manufacturer ,
		"SRC_DIR_COMMON"             : src_android_path + "/device/fsl",
		"SRC_DIR_DEVICE_NAME"     : src_android_path + "/device/fsl/" + src_manufacturer + "/" + src_device,
		"SRC_DIR_VENDOR"          : src_android_path + "/vendor",
		"SRC_DIR_SYSTEM"	  : src_android_path + "/system",
		"SRC_DIR_FRAMEWORKS"       : src_android_path + "/frameworks",
		"TARGET_DIR_SYSTEM"	  : target_android_path + "/system",
		"TARGET_DIR_FRAMEWORKS"       : target_android_path + "/frameworks",
                 
		"TARGET_DIR_EXTERNAL"       : target_android_path + "/external",
		"TARGET_DIR_BUILD"       : target_android_path + "/build",
		"SRC_DIR_EXTERNAL"       : src_android_path + "/external",
		"SRC_DIR_BUILD"       : src_android_path + "/build"
		}
	
	elif target_platform == "qcom":
		
		data = {
       	"source_qcom_AndroidBoard"     :  src_android_path + "/device/" + src_manufacturer + "/"+ src_device + "/AndroidBoard.mk" ,
		"source_qcom_Boardconfig"      : src_android_path + "/device/"+ src_manufacturer + "/"+ src_device + "/BoardConfig.mk" ,		
		"source_qcom_product"          : src_android_path + "/device/" + src_manufacturer + "/"+ src_device + "/"+src_device +".mk" ,
		"source_qcom_BoardConfigVendor"    : src_android_path + "/vendor/"+src_manufacturer+"/proprietary/common/"+ src_device +"BoardConfigVendor.mk", 
		"source_qcom_device-vendor"  : src_android_path + "/vendor/"+src_manufacturer+"/proprietary/common/config/device-vendor.mk",
		"source_qcom_kernel"		  : src_android_path + "/kernel/msm-3.18",
		"source_qcom_bootloader"			: src_android_path + "/bootable/bootloader/lk",
		"SRC_DIR_hardware"          : src_android_path + "/hardware",		
		"TARGET_DIR_hardware"          : target_android_path + "/hardware",		
		"target_qcom_vendor"           : target_android_path + "/vendor" ,
		"target_qcom_device"           : target_android_path + "/device" ,
		"SRC_DIR_VENDOR"          : src_android_path + "/vendor",
		"SRC_DIR_device"          : src_android_path + "/device"
		}

	return data

