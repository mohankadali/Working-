# BuildVariant.py ####
# This file contains the porting specific command line arguments 
 
import sys
def build_configuration ():
		data = {

		# it specifies the vendor name for porting  
		"VENDOR_NAME" : "nxp11",

		# predefined variant name 
		"SOURCE_PLATFORM_NAME" : "imx8m",
		"SOURCE_PLATFORM_VARIANT_NAME" : "evk_8mq",

		# user defined variant name
		"TARGET_PLATFORM_NAME" : "imx8m",
		"TARGET_PLATFORM_VARIANT_NAME" : "evk_mq",

		# path to patch source 
		"SOURCE_ANDROID_PATH_DIR" : "/Android/patch_source_nxp",

		# path to AOSP source code 
		"TARGET_ANDROID_PATH_DIR" : "/home/krishna/AOSP_P_IMX_PORT/my_IMX"

		}
		return data


