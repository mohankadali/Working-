# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Backup/MOHAN/VULKAN/ogl-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Backup/MOHAN/VULKAN/ogl-master/build

# Include any dependencies generated for this target.
include CMakeFiles/tutorial02_red_triangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tutorial02_red_triangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tutorial02_red_triangle.dir/flags.make

CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o: CMakeFiles/tutorial02_red_triangle.dir/flags.make
CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o: ../tutorial02_red_triangle/tutorial02.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Backup/MOHAN/VULKAN/ogl-master/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o -c /Backup/MOHAN/VULKAN/ogl-master/tutorial02_red_triangle/tutorial02.cpp

CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Backup/MOHAN/VULKAN/ogl-master/tutorial02_red_triangle/tutorial02.cpp > CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.i

CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Backup/MOHAN/VULKAN/ogl-master/tutorial02_red_triangle/tutorial02.cpp -o CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.s

CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o.requires:
.PHONY : CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o.requires

CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o.provides: CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial02_red_triangle.dir/build.make CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o.provides

CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o.provides.build: CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o

CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o: CMakeFiles/tutorial02_red_triangle.dir/flags.make
CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o: ../common/shader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Backup/MOHAN/VULKAN/ogl-master/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o -c /Backup/MOHAN/VULKAN/ogl-master/common/shader.cpp

CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Backup/MOHAN/VULKAN/ogl-master/common/shader.cpp > CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.i

CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Backup/MOHAN/VULKAN/ogl-master/common/shader.cpp -o CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.s

CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o.requires:
.PHONY : CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o.requires

CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o.provides: CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial02_red_triangle.dir/build.make CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o.provides

CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o.provides.build: CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o

# Object files for target tutorial02_red_triangle
tutorial02_red_triangle_OBJECTS = \
"CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o" \
"CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o"

# External object files for target tutorial02_red_triangle
tutorial02_red_triangle_EXTERNAL_OBJECTS =

tutorial02_red_triangle: CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o
tutorial02_red_triangle: CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o
tutorial02_red_triangle: CMakeFiles/tutorial02_red_triangle.dir/build.make
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libGLU.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libGL.so
tutorial02_red_triangle: external/glfw-3.1.2/src/libglfw3.a
tutorial02_red_triangle: external/libGLEW_1130.a
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libGLU.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/librt.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libm.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libX11.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXrandr.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXinerama.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXi.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXcursor.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/librt.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libm.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libX11.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXrandr.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXinerama.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXi.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libXcursor.so
tutorial02_red_triangle: /usr/lib/x86_64-linux-gnu/libGL.so
tutorial02_red_triangle: CMakeFiles/tutorial02_red_triangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable tutorial02_red_triangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial02_red_triangle.dir/link.txt --verbose=$(VERBOSE)
	/usr/local/bin/cmake -E copy /Backup/MOHAN/VULKAN/ogl-master/build/./tutorial02_red_triangle /Backup/MOHAN/VULKAN/ogl-master/tutorial02_red_triangle/

# Rule to build all files generated by this target.
CMakeFiles/tutorial02_red_triangle.dir/build: tutorial02_red_triangle
.PHONY : CMakeFiles/tutorial02_red_triangle.dir/build

CMakeFiles/tutorial02_red_triangle.dir/requires: CMakeFiles/tutorial02_red_triangle.dir/tutorial02_red_triangle/tutorial02.cpp.o.requires
CMakeFiles/tutorial02_red_triangle.dir/requires: CMakeFiles/tutorial02_red_triangle.dir/common/shader.cpp.o.requires
.PHONY : CMakeFiles/tutorial02_red_triangle.dir/requires

CMakeFiles/tutorial02_red_triangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tutorial02_red_triangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tutorial02_red_triangle.dir/clean

CMakeFiles/tutorial02_red_triangle.dir/depend:
	cd /Backup/MOHAN/VULKAN/ogl-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Backup/MOHAN/VULKAN/ogl-master /Backup/MOHAN/VULKAN/ogl-master /Backup/MOHAN/VULKAN/ogl-master/build /Backup/MOHAN/VULKAN/ogl-master/build /Backup/MOHAN/VULKAN/ogl-master/build/CMakeFiles/tutorial02_red_triangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tutorial02_red_triangle.dir/depend

