#variant_creation.py
# Variant_creation.py file includes all sub python files required for porting  

import os
import sys
sys.path.append('./python_scripts')
from replace import *
from distutils.dir_util import copy_tree

f = open ("./python_scripts/BuildVariant.config", "r")
keylist = []
SOURCE_PLATFORM_NAME = ""
SOURCE_PLATFORM_VARIANT_NAME = ""
TARGET_PLATFORM_NAME = ""
TARGET_PLATFORM_VARIANT_NAME = ""
VENDOR_NAME = ""
for line in f:
	if "SOURCE_PLATFORM_NAME" in line:
		keylist = line.split ("=")
		SOURCE_PLATFORM_NAME = str(keylist[1]).strip()

	if "SOURCE_PLATFORM_VARIANT_NAME" in line:
		keylist = line.split ("=")
		SOURCE_PLATFORM_VARIANT_NAME = str(keylist[1]).strip()
	if "TARGET_PLATFORM_NAME" in line:
		keylist = line.split ("=")
		TARGET_PLATFORM_NAME = str(keylist[1]).strip()
	if "TARGET_PLATFORM_VARIANT_NAME" in line:
		keylist = line.split ("=")
		TARGET_PLATFORM_VARIANT_NAME = str(keylist[1]).strip()
	if "VENDOR_NAME" in line:
		keylist = line.split ("=")
		VENDOR_NAME = str(keylist[1]).strip()
print (VENDOR_NAME)
print (SOURCE_PLATFORM_NAME)
print (SOURCE_PLATFORM_VARIANT_NAME)
print (TARGET_PLATFORM_NAME)
print (TARGET_PLATFORM_VARIANT_NAME)





print( "populating new device.....\n")
cmd = 'sh '+'device/common/populate-new-device.sh '+' '+TARGET_PLATFORM_NAME+' '+TARGET_PLATFORM_VARIANT_NAME
target = 'device/common/populate-new-device.sh' 
temp_target = 'device/common/temp.txt'
replace(target, temp_target, 'full_', '')
replace(target, temp_target,  'touch device/$1/$2-kernel/kernel', '')

if os.system(cmd) == 0:
	print( "populate-new-device.sh executed successfully...\n")
else: 
	print( "populate-new-device.sh execution failed !\n")
	exit(1)


# executing Platform_update.py to copy the content from patch source like kernel,uboot,BoardConfig.mk etc...

print( "updating platform and BSP.....\n")

cmd = 'python3 ' +   './python_scripts/Platform_update.py ' +' '+ TARGET_PLATFORM_NAME +' '+ TARGET_PLATFORM_VARIANT_NAME +' '+ SOURCE_PLATFORM_NAME + ' '+ SOURCE_PLATFORM_VARIANT_NAME + ' '+VENDOR_NAME

if os.system(cmd) == 0:
	print (" platfrom_update.py executed successfully...\n")
else:
	print (" platform_update.py failed !\n")
	exit(1)

# executing System_update.py to copy the content from patch to AOSP system directory   
print ("updating system directory.....\n")

cmd = 'python3 ' +   './python_scripts/System_update.py ' + ' '+TARGET_PLATFORM_NAME +' '+ TARGET_PLATFORM_VARIANT_NAME +' '+ SOURCE_PLATFORM_NAME + ' '+SOURCE_PLATFORM_VARIANT_NAME + ' '+VENDOR_NAME

if os.system(cmd) == 0:

	print("System_update.py executed successfully...\n")
else:
	print( "System_update.py failed !\n")
	exit(1)


# executing Build_update.py to copy the content from patch to AOSP build directory

print ("Updating build directory.....\n")
	
cmd = 'python3 ' +   './python_scripts/Build_update.py ' +' '+ TARGET_PLATFORM_NAME  +' '+TARGET_PLATFORM_VARIANT_NAME +' '+SOURCE_PLATFORM_NAME +' '+SOURCE_PLATFORM_VARIANT_NAME + ' '+VENDOR_NAME

if os.system(cmd) == 0:

	print( "Build_update.py executed successfully...\n")
else:
	print( "Build_update.py failed !")
	exit(1)

# executing Framework_update.py to copy the content from patch to AOSP frameworks directory

print ( "updating framework directory.....\n")
	
cmd = 'python3 ' +   './python_scripts/Framework_update.py ' + TARGET_PLATFORM_NAME  +' '+TARGET_PLATFORM_VARIANT_NAME+' '+ SOURCE_PLATFORM_NAME + ' '+SOURCE_PLATFORM_VARIANT_NAME+' '+ VENDOR_NAME

if os.system(cmd) == 0:


	print( "Framework_update.py executed successfully...\n")
else: 
	print ( "Framework_update.py failed !")
	exit(1)


# executing Hal_update.py to copy the content from patch to AOSP hardware directory

print( "updating hal.....\n")
	
cmd = 'python3 ' +   './python_scripts/Hal_update.py ' + TARGET_PLATFORM_NAME  + ' '+TARGET_PLATFORM_VARIANT_NAME +' '+ SOURCE_PLATFORM_NAME + ' '+SOURCE_PLATFORM_VARIANT_NAME +' ' + VENDOR_NAME

if os.system(cmd) == 0:

	print( "Hal_update.py executed successfully...\n")
else:
	print( "Hal_update.py failed !\n")
	exit(1)
# executing External_update.py to copy the content from patch to AOSP external directory

print( "Updating external directory.....\n")

cmd = 'python3 ' +  './python_scripts/External_update.py ' + TARGET_PLATFORM_NAME  +' '+TARGET_PLATFORM_VARIANT_NAME + ' '+SOURCE_PLATFORM_NAME + ' '+SOURCE_PLATFORM_VARIANT_NAME +' '+VENDOR_NAME

if os.system(cmd) == 0:
	
	print ( "External_update.py executed successfully...\n")
else:
	print( "External_update.py failed !\n")
	exit(1)


print (".......................Porting Done .............................")
