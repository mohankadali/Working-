#!/usr/bin/env python3
#!/usr/bin/env python2

import os
import subprocess
import sys
import getopt

def bash_command(cmd):
    subprocess.call('/bin/bash -cl "$GREPDB"', shell=True, env={'GREPDB': cmd})

bash_command('cd system/tools/ && git clone https://android.googlesource.com/platform/system/tools/bpt')
bash_command('cd external/ && git clone https://github.com/murata-wireless/cyw-fmac-fw && git clone https://github.com/murata-wireless/cyw-fmac-nvram')
#bash_command('source build/envsetup.sh; lunch ' + str(sys.argv[2]) + '-' + 'userdebug' + '; make -j8')

