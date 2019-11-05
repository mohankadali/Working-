# framework_update.py
# copy the contents from patch to AOSP source code  
import sys
sys.path.append('./python_scripts')
from replace import *
from read_configuration import *
from distutils.dir_util import copy_tree
cwd = os.getcwd()

# reading the configuration variables
data = read_configuration ()

print("framework_update.py executing from : "+ cwd +'/qcom')

