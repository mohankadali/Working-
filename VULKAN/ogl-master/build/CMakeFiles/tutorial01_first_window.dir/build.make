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
include CMakeFiles/tutorial01_first_window.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tutorial01_first_window.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tutorial01_first_window.dir/flags.make

CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o: CMakeFiles/tutorial01_first_window.dir/flags.make
CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o: ../tutorial01_first_window/tutorial01.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Backup/MOHAN/VULKAN/ogl-master/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o -c /Backup/MOHAN/VULKAN/ogl-master/tutorial01_first_window/tutorial01.cpp

CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Backup/MOHAN/VULKAN/ogl-master/tutorial01_first_window/tutorial01.cpp > CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.i

CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Backup/MOHAN/VULKAN/ogl-master/tutorial01_first_window/tutorial01.cpp -o CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.s

CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o.requires:
.PHONY : CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o.requires

CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o.provides: CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial01_first_window.dir/build.make CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o.provides

CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o.provides.build: CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o

# Object files for target tutorial01_first_window
tutorial01_first_window_OBJECTS = \
"CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o"

# External object files for target tutorial01_first_window
tutorial01_first_window_EXTERNAL_OBJECTS =

tutorial01_first_window: CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o
tutorial01_first_window: CMakeFiles/tutorial01_first_window.dir/build.make
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libGLU.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libGL.so
tutorial01_first_window: external/glfw-3.1.2/src/libglfw3.a
tutorial01_first_window: external/libGLEW_1130.a
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libGLU.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/librt.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libm.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libX11.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXrandr.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXinerama.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXi.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXcursor.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/librt.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libm.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libX11.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXrandr.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXinerama.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXi.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libXcursor.so
tutorial01_first_window: /usr/lib/x86_64-linux-gnu/libGL.so
tutorial01_first_window: CMakeFiles/tutorial01_first_window.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable tutorial01_first_window"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial01_first_window.dir/link.txt --verbose=$(VERBOSE)
	/usr/local/bin/cmake -E copy /Backup/MOHAN/VULKAN/ogl-master/build/./tutorial01_first_window /Backup/MOHAN/VULKAN/ogl-master/tutorial01_first_window/

# Rule to build all files generated by this target.
CMakeFiles/tutorial01_first_window.dir/build: tutorial01_first_window
.PHONY : CMakeFiles/tutorial01_first_window.dir/build

CMakeFiles/tutorial01_first_window.dir/requires: CMakeFiles/tutorial01_first_window.dir/tutorial01_first_window/tutorial01.cpp.o.requires
.PHONY : CMakeFiles/tutorial01_first_window.dir/requires

CMakeFiles/tutorial01_first_window.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tutorial01_first_window.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tutorial01_first_window.dir/clean

CMakeFiles/tutorial01_first_window.dir/depend:
	cd /Backup/MOHAN/VULKAN/ogl-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Backup/MOHAN/VULKAN/ogl-master /Backup/MOHAN/VULKAN/ogl-master /Backup/MOHAN/VULKAN/ogl-master/build /Backup/MOHAN/VULKAN/ogl-master/build /Backup/MOHAN/VULKAN/ogl-master/build/CMakeFiles/tutorial01_first_window.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tutorial01_first_window.dir/depend

