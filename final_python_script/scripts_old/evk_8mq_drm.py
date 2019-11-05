from replace import *
from config_file import *

data = config ()


target = data['target_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'evk_8mq_drm.mk'
temp_target = data['target_device']+'/'+str(sys.argv[1])+'/'+str(sys.argv[2])+'/'+'temp.txt'


replace (target, temp_target, '/fsl/'+str(sys.argv[3])+'/'+str(sys.argv[4]), '/'+ str(sys.argv[1])+'/'+str(sys.argv[2]))
