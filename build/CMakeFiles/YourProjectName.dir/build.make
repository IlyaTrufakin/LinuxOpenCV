# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jetson/LinuxOpenCV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jetson/LinuxOpenCV/build

# Include any dependencies generated for this target.
include CMakeFiles/YourProjectName.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/YourProjectName.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YourProjectName.dir/flags.make

CMakeFiles/YourProjectName.dir/main.cpp.o: CMakeFiles/YourProjectName.dir/flags.make
CMakeFiles/YourProjectName.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jetson/LinuxOpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/YourProjectName.dir/main.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/YourProjectName.dir/main.cpp.o -c /home/jetson/LinuxOpenCV/main.cpp

CMakeFiles/YourProjectName.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/YourProjectName.dir/main.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jetson/LinuxOpenCV/main.cpp > CMakeFiles/YourProjectName.dir/main.cpp.i

CMakeFiles/YourProjectName.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/YourProjectName.dir/main.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jetson/LinuxOpenCV/main.cpp -o CMakeFiles/YourProjectName.dir/main.cpp.s

CMakeFiles/YourProjectName.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/YourProjectName.dir/main.cpp.o.requires

CMakeFiles/YourProjectName.dir/main.cpp.o.provides: CMakeFiles/YourProjectName.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/YourProjectName.dir/build.make CMakeFiles/YourProjectName.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/YourProjectName.dir/main.cpp.o.provides

CMakeFiles/YourProjectName.dir/main.cpp.o.provides.build: CMakeFiles/YourProjectName.dir/main.cpp.o


# Object files for target YourProjectName
YourProjectName_OBJECTS = \
"CMakeFiles/YourProjectName.dir/main.cpp.o"

# External object files for target YourProjectName
YourProjectName_EXTERNAL_OBJECTS =

YourProjectName: CMakeFiles/YourProjectName.dir/main.cpp.o
YourProjectName: CMakeFiles/YourProjectName.dir/build.make
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_dnn.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_gapi.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_highgui.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_ml.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_objdetect.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_photo.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_stitching.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_video.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_videoio.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_imgcodecs.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_calib3d.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_features2d.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_flann.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_imgproc.so.4.1.1
YourProjectName: /usr/lib/aarch64-linux-gnu/libopencv_core.so.4.1.1
YourProjectName: CMakeFiles/YourProjectName.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jetson/LinuxOpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable YourProjectName"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/YourProjectName.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YourProjectName.dir/build: YourProjectName

.PHONY : CMakeFiles/YourProjectName.dir/build

CMakeFiles/YourProjectName.dir/requires: CMakeFiles/YourProjectName.dir/main.cpp.o.requires

.PHONY : CMakeFiles/YourProjectName.dir/requires

CMakeFiles/YourProjectName.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/YourProjectName.dir/cmake_clean.cmake
.PHONY : CMakeFiles/YourProjectName.dir/clean

CMakeFiles/YourProjectName.dir/depend:
	cd /home/jetson/LinuxOpenCV/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jetson/LinuxOpenCV /home/jetson/LinuxOpenCV /home/jetson/LinuxOpenCV/build /home/jetson/LinuxOpenCV/build /home/jetson/LinuxOpenCV/build/CMakeFiles/YourProjectName.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/YourProjectName.dir/depend

