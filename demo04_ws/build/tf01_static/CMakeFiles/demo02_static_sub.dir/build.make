# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/shuai/demo04_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shuai/demo04_ws/build

# Include any dependencies generated for this target.
include tf01_static/CMakeFiles/demo02_static_sub.dir/depend.make

# Include the progress variables for this target.
include tf01_static/CMakeFiles/demo02_static_sub.dir/progress.make

# Include the compile flags for this target's objects.
include tf01_static/CMakeFiles/demo02_static_sub.dir/flags.make

tf01_static/CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.o: tf01_static/CMakeFiles/demo02_static_sub.dir/flags.make
tf01_static/CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.o: /home/shuai/demo04_ws/src/tf01_static/src/demo02_static_sub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shuai/demo04_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tf01_static/CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.o"
	cd /home/shuai/demo04_ws/build/tf01_static && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.o -c /home/shuai/demo04_ws/src/tf01_static/src/demo02_static_sub.cpp

tf01_static/CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.i"
	cd /home/shuai/demo04_ws/build/tf01_static && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shuai/demo04_ws/src/tf01_static/src/demo02_static_sub.cpp > CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.i

tf01_static/CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.s"
	cd /home/shuai/demo04_ws/build/tf01_static && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shuai/demo04_ws/src/tf01_static/src/demo02_static_sub.cpp -o CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.s

# Object files for target demo02_static_sub
demo02_static_sub_OBJECTS = \
"CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.o"

# External object files for target demo02_static_sub
demo02_static_sub_EXTERNAL_OBJECTS =

/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: tf01_static/CMakeFiles/demo02_static_sub.dir/src/demo02_static_sub.cpp.o
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: tf01_static/CMakeFiles/demo02_static_sub.dir/build.make
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/liborocos-kdl.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/liborocos-kdl.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/libtf2_ros.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/libactionlib.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/libmessage_filters.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/libroscpp.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/librosconsole.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/libtf2.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/librostime.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /opt/ros/noetic/lib/libcpp_common.so
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub: tf01_static/CMakeFiles/demo02_static_sub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shuai/demo04_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub"
	cd /home/shuai/demo04_ws/build/tf01_static && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo02_static_sub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tf01_static/CMakeFiles/demo02_static_sub.dir/build: /home/shuai/demo04_ws/devel/lib/tf01_static/demo02_static_sub

.PHONY : tf01_static/CMakeFiles/demo02_static_sub.dir/build

tf01_static/CMakeFiles/demo02_static_sub.dir/clean:
	cd /home/shuai/demo04_ws/build/tf01_static && $(CMAKE_COMMAND) -P CMakeFiles/demo02_static_sub.dir/cmake_clean.cmake
.PHONY : tf01_static/CMakeFiles/demo02_static_sub.dir/clean

tf01_static/CMakeFiles/demo02_static_sub.dir/depend:
	cd /home/shuai/demo04_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shuai/demo04_ws/src /home/shuai/demo04_ws/src/tf01_static /home/shuai/demo04_ws/build /home/shuai/demo04_ws/build/tf01_static /home/shuai/demo04_ws/build/tf01_static/CMakeFiles/demo02_static_sub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tf01_static/CMakeFiles/demo02_static_sub.dir/depend

