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
CMAKE_COMMAND = /home/charles/Desktop/clion-2018.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/charles/Desktop/clion-2018.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/charles/Desktop/Westguard-SSM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/charles/Desktop/Westguard-SSM

# Include any dependencies generated for this target.
include third_parties/googletest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include third_parties/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include third_parties/googletest/CMakeFiles/gtest_main.dir/flags.make

third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: third_parties/googletest/CMakeFiles/gtest_main.dir/flags.make
third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: third_parties/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /home/charles/Desktop/Westguard-SSM/third_parties/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /home/charles/Desktop/Westguard-SSM/third_parties/googletest/src/gtest_main.cc

third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /home/charles/Desktop/Westguard-SSM/third_parties/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/Desktop/Westguard-SSM/third_parties/googletest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /home/charles/Desktop/Westguard-SSM/third_parties/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/Desktop/Westguard-SSM/third_parties/googletest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:

.PHONY : third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f third_parties/googletest/CMakeFiles/gtest_main.dir/build.make third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

third_parties/googletest/libgtest_main.a: third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
third_parties/googletest/libgtest_main.a: third_parties/googletest/CMakeFiles/gtest_main.dir/build.make
third_parties/googletest/libgtest_main.a: third_parties/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /home/charles/Desktop/Westguard-SSM/third_parties/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /home/charles/Desktop/Westguard-SSM/third_parties/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_parties/googletest/CMakeFiles/gtest_main.dir/build: third_parties/googletest/libgtest_main.a

.PHONY : third_parties/googletest/CMakeFiles/gtest_main.dir/build

third_parties/googletest/CMakeFiles/gtest_main.dir/requires: third_parties/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

.PHONY : third_parties/googletest/CMakeFiles/gtest_main.dir/requires

third_parties/googletest/CMakeFiles/gtest_main.dir/clean:
	cd /home/charles/Desktop/Westguard-SSM/third_parties/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : third_parties/googletest/CMakeFiles/gtest_main.dir/clean

third_parties/googletest/CMakeFiles/gtest_main.dir/depend:
	cd /home/charles/Desktop/Westguard-SSM && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/charles/Desktop/Westguard-SSM /home/charles/Desktop/Westguard-SSM/third_parties/googletest /home/charles/Desktop/Westguard-SSM /home/charles/Desktop/Westguard-SSM/third_parties/googletest /home/charles/Desktop/Westguard-SSM/third_parties/googletest/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_parties/googletest/CMakeFiles/gtest_main.dir/depend

