#variant_creation.py
# Variant_creation.py file includes all sub python files required for porting  

import os
import sys
sys.path.append('./python_scripts')
from BuildVariant import *
from distutils.dir_util import copy_tree
data = build_configuration ()

# get the arguments from BuildVariant.py file
VENDOR_NAME = data['VENDOR_NAME']

SOURCE_PLATFORM_NAME = data['SOURCE_PLATFORM_NAME']
SOURCE_PLATFORM_VARIANT_NAME = data['SOURCE_PLATFORM_VARIANT_NAME']

TARGET_PLATFORM_NAME = data['TARGET_PLATFORM_NAME']
TARGET_PLATFORM_VARIANT_NAME = data['TARGET_PLATFORM_VARIANT_NAME']



# Display arguments in console 

print("\n")
print("VENDOR_NAME= " + VENDOR_NAME)

print ("SOURCE_PLATFORM_VARIANT_NAME = "+ SOURCE_PLATFORM_VARIANT_NAME)
print ("SOURCE_PLATFORM_NAME = " + SOURCE_PLATFORM_NAME)

print ("TARGET_PLATFORM_NAME ="+TARGET_PLATFORM_NAME)
print ("TARGET_PLATFORM_VARIANT_NAME = "+TARGET_PLATFORM_VARIANT_NAME)
print ("\n")


# executing populate-new-device.sh to create a required make files  

print( "populating new device.....\n")

cmd = 'sh '+'device/common/populate-new-device.sh '+' '+TARGET_PLATFORM_NAME+' '+TARGET_PLATFORM_VARIANT_NAME
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
