import os
from BuildVariant import *
 
print("choose the vendor....") 
print("press 0 for nxp..") 	 
print("press 1 for qcom..") 	 
s = input()

if s == "0":
		
	vendor_name ="nxp"
	
	print("choose the source platform name")
	print("press 0 for imx8m") 	 
	print("press 1 for imx7d")
	print("press 2 for other")
	s = input()
	argument= s
	print("enter the target platform name:=   ")    
	target_platform_name = str(input())

	if s == "0":
		source_platform_name = "imx8m"
		print("choose the source variant name")
		print("press 0 for evk_8mq")
		print("press 1 for other")
		s = input()
		argument= s
		if s== "0":
			source_variant_name="evk_8mq"
		else:
			print("variant name is not supported!!!!!!!!!!!")
			exit(1)
		print("enter the target variant name:=   ")
		target_variant_name = str(input())

	elif s =="1":
		
		source_platform_name = "imx7d"
		print("choose source variant name")
		print("press 0 for sabresd_7d")
		s = input()
		argument= s
		
		if s== "0":   
			source_variant_name="sabresd_7d"
		else:
			print("variant name is not supported!!!!!!!!!!!")
			exit(1)
		print("enter the target variant name:=   ")
		target_variant_name = str(input())

			


	else:
		print("source platform  is not supported!!!!")
		exit(1)

elif s =="1":
		
	vendor_name="qcom"
	print("choose the source platform name")
	print("press 0 for qcom") 	 
	print("press 1 for other")
	s = input()
	argument= s
	print("enter the target platform name:=   ")
	target_platform_name = str(input())

	if s =="0":
		
		source_platform_name="qcom"
		print("choose source variant  name")
		print("press 0 for msm8996")
		s = input()
		argument= s
	
		if s== "0":     
			source_variant_name="msm8996"
		else: 
			print("source variant name is not supported!!!!!!!!!!!")
			exit(1)
		print("enter the target variant name:=   ")
		target_variant_name = str(input())


	else:
		print("source platform  is not supported!!!!")
		exit(1)
else:
	print("vendor is not supported!!!!")
	exit(1)


print("enter the patch source path:=   ")
source_android_path_dir = str(input())

print("enter the target path for AOSP_P :=   ")
target_android_path_dir = str(input())

cmd = 'python3 ' + 'BuildVariant.py '  + vendor_name + ' '+target_platform_name+' '+target_variant_name +' '+source_platform_name+ ' '+ source_variant_name+' '+source_android_path_dir+' '+target_android_path_dir
print(cmd)

os.system(cmd) 

cmd  = 'python3 ' + 'demo.py '
os.system(cmd)

