# framework_update.py
# copy the contents from patch to AOSP frameworks directory
import sys
sys.path.append('./python_scripts')
from replace import *
from distutils.dir_util import copy_tree
from read_configuration import *
cwd = os.getcwd()

# reading the configuration variables
data = read_configuration ()

print("framework_update.py executing from : "+ cwd +'/nxp'+"\n")

# need to update av in AOSP frameworks directory for multimedia  

source = data['src_dir_frameworks']+'/'+'av'
target = data['dst_dir_frameworks']+'/'+'av'

print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copy_tree(source,target)
print ("file copied successfuly....\n")


# need to update av in AOSP frameworks directory for multimedia  

source = data['src_dir_frameworks']+'/'+'base/media/jni/audioeffect/android_media_Visualizer.cpp'
target = data['dst_dir_frameworks']+'/'+'base/media/jni/audioeffect/android_media_Visualizer.cpp'

print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copyfile(source,target)
print ("file copied successfuly....\n")

                                              
# need to update av in AOSP frameworks directory for multimedia  

source = data['src_dir_frameworks']+'/'+'native/headers/media_plugin/media/openmax/OMX_Implement.h'
target = data['dst_dir_frameworks']+'/'+'native/headers/media_plugin/media/openmax/OMX_Implement.h'

print ("source path:="+str(source))
print ("target path:="+str(target)+"\n")
copyfile(source,target)
print ("file copied successfuly....\n")
