# BuildVariant.py 
# This file contains the command line options for build variable configurations. 
# output of this file will update  BuildVariant.config file and after that  it will execute VariantCreation.py.
 
import os
import sys
import fileinput

# config_generate function used for replace with new data in BuildVariant.config file 
# target    : BuildVariant.config
# text      : if any line contains this text, I want to modify the whole line
# new_text  : data need update
   			
def config_generate(target, text, new_text):
	text = text   # if any line contains this text, I want to modify the whole line.
	new_text = new_text
	x = fileinput.input(files=target, inplace=1)
	for line in x:
		if text in line:
			line = new_text
		print(line)

	x.close()

# erase_blank_line function will remove the blank line if present 

def erase_blank_line():
	for line in fileinput.FileInput("./python_scripts/BuildVariant.config",inplace=1):
		if line.rstrip():
        		print (line)

	
# menu selecton  

print("Vendor name configuration....\n")
print(" 0 - nxp")
print(" 1 - qcom")
print(" 2 - exit")
s = input()
argument= s
if s == "0":
	config_generate("./python_scripts/BuildVariant.config", "VENDOR_NAME", "VENDOR_NAME = nxp")
			
	print("\nsource platform configuration......................\n")
	print(" 0 - imx8m") 	 
	print(" 1 - imx7d")
	print(" 2 - exit")
	s = input()
	argument= s
	print("\nenter the target platform name:=   ")    
	target_platform_name = str(input())
	config_generate("./python_scripts/BuildVariant.config", "TARGET_PLATFORM_NAME", "TARGET_PLATFORM_NAME = "+target_platform_name)

	if s == "0":
		config_generate("./python_scripts/BuildVariant.config", "SOURCE_PLATFORM_NAME", "SOURCE_PLATFORM_NAME = imx8m")

		print("\nsource variant name configuration..................\n")
		print(" 0 - evk_8mq")
		print(" 1 - exit")
		s = input()
		argument= s
		if s== "0":
			config_generate("./python_scripts/BuildVariant.config", "SOURCE_PLATFORM_VARIANT_NAME", "SOURCE_PLATFORM_VARIANT_NAME = evk_8mq")


		else:
			print("variant name is not supported!!!!!!!!!!!\n")
			exit(1)
		print("\nEnter the target variant name:=   ")
		target_variant_name = str(input())
		config_generate("./python_scripts/BuildVariant.config", "TARGET_PLATFORM_VARIANT_NAME", "TARGET_PLATFORM_VARIANT_NAME = "+target_variant_name)


	elif s =="1":
		config_generate("./python_scripts/BuildVariant.config", "SOURCE_PLATFORM_NAME", "SOURCE_PLATFORM_NAME = imx7d")
		
		print("\nsource variant name configuration .................\n")
		print(" 0 - sabresd_7d")
		print(" 1 - exit")
		s = input()
		argument= s
			
		if s== "0":
			config_generate("./python_scripts/BuildVariant.config", "SOURCE_PLATFORM_VARIANT_NAME", "SOURCE_PLATFORM_VARIANT_NAME = sabresd_7d")
     
		else:
			print("variant name is not supported!!!!!!!!!!!\n")
			exit(1)
		print("\nEnter the target variant name:=   ")
		target_variant_name = str(input())
		config_generate("./python_scripts/BuildVariant.config", "TARGET_PLATFORM_VARIANT_NAME", "TARGET_PLATFORM_VARIANT_NAME = "+target_variant_name)

	else:
		print("source platform  is not supported!!!!\n")
		exit(1)
elif s =="1":
	config_generate("./python_scripts/BuildVariant.config", "VENDOR_NAME", "VENDOR_NAME = qcom")

	
	print("\nsource platform name configuration.............\n")
	print(" 0 - qcom") 	 
	print(" 1 - other")
	s = input()
	argument= s
	print("\nEnter the target platform name:=   ")
	target_platform_name = str(input())
	config_generate("./python_scripts/BuildVariant.config", "TARGET_PLATFORM_NAME", "TARGET_PLATFORM_NAME = "+target_platform_name)


	if s =="0":
		config_generate("./python_scripts/BuildVariant.config", "SOURCE_PLATFORM_NAME", "SOURCE_PLATFORM_NAME = qcom")

		print("source variant name configuration...............\n")
		print(" 0 - msm8996")
		print(" 1 - exit")
		s = input()
		argument= s
			
		if s== "0":
			config_generate("./python_scripts/BuildVariant.config", "SOURCE_PLATFORM_VARIANT_NAME", "SOURCE_PLATFORM_VARIANT_NAME = msm8996")
     
		else: 
			print("source variant name is not supported!!!!!!!!!!!\n")
			exit(1)
		print("\nEnter the target variant name:=   ")
		target_variant_name = str(input())
		config_generate("./python_scripts/BuildVariant.config", "TARGET_PLATFORM_VARIANT_NAME", "TARGET_PLATFORM_VARIANT_NAME = "+target_variant_name)

	else:
		print("source platform  is not supported!!!!\n")
		exit(1)
else:
	print("vendor is not supported!!!!\n")
	exit(1)


print("\nEnter the patch source path:=   ")
source_android_path_dir = str(input())
config_generate("./python_scripts/BuildVariant.config", "SOURCE_ANDROID_PATH_DIR", "SOURCE_ANDROID_PATH_DIR ="+source_android_path_dir )
print("\nEnter the target path for AOSP_P :=   ")
target_android_path_dir = str(input())
config_generate("./python_scripts/BuildVariant.config", "TARGET_ANDROID_PATH_DIR", "TARGET_ANDROID_PATH_DIR ="+target_android_path_dir )
erase_blank_line()

# executeing Variant_creation.py for porting

os.system("python3 Variant_creation.py")

