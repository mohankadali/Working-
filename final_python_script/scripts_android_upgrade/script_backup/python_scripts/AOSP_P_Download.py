#Downloading AOSP_P source code from remote location

import os

#A directory creation for source code

os.mkdir("../android_build")
os.chdir("../android_build")


#command to download source code

repo_init = 'repo init -u https://android.googlesource.com/platform/manifest -b android-9.0.0_r45'
os.system(repo_init)

repo_sync = 'repo sync'
os.system(repo_sync)
