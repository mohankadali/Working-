#!/bin/sh
bindir=$(pwd)
cd /Backup/MOHAN/VULKAN/ogl-master/tutorial18_billboards_and_particles/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /Backup/MOHAN/VULKAN/ogl-master/build/tutorial18_billboards 
	else
		"/Backup/MOHAN/VULKAN/ogl-master/build/tutorial18_billboards"  
	fi
else
	"/Backup/MOHAN/VULKAN/ogl-master/build/tutorial18_billboards"  
fi
