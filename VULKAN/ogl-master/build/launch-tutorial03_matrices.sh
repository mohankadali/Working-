#!/bin/sh
bindir=$(pwd)
cd /Backup/MOHAN/VULKAN/ogl-master/tutorial03_matrices/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /Backup/MOHAN/VULKAN/ogl-master/build/tutorial03_matrices 
	else
		"/Backup/MOHAN/VULKAN/ogl-master/build/tutorial03_matrices"  
	fi
else
	"/Backup/MOHAN/VULKAN/ogl-master/build/tutorial03_matrices"  
fi
