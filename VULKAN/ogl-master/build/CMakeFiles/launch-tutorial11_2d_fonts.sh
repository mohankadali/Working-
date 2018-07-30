#!/bin/sh
bindir=$(pwd)
cd /Backup/MOHAN/VULKAN/ogl-master/tutorial11_2d_fonts/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /Backup/MOHAN/VULKAN/ogl-master/build/tutorial11_2d_fonts 
	else
		"/Backup/MOHAN/VULKAN/ogl-master/build/tutorial11_2d_fonts"  
	fi
else
	"/Backup/MOHAN/VULKAN/ogl-master/build/tutorial11_2d_fonts"  
fi
