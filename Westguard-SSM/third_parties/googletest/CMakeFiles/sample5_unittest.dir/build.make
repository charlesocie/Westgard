# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.11

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Charles.Socie\Desktop\Westguard-SSM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Charles.Socie\Desktop\Westguard-SSM

# Include any dependencies generated for this target.
include third_parties/googletest/CMakeFiles/sample5_unittest.dir/depend.make

# Include the progress variables for this target.
include third_parties/googletest/CMakeFiles/sample5_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include third_parties/googletest/CMakeFiles/sample5_unittest.dir/flags.make

third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.obj: third_parties/googletest/CMakeFiles/sample5_unittest.dir/flags.make
third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.obj: third_parties/googletest/CMakeFiles/sample5_unittest.dir/includes_CXX.rsp
third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.obj: third_parties/googletest/samples/sample5_unittest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Charles.Socie\Desktop\Westguard-SSM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.obj"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sample5_unittest.dir\samples\sample5_unittest.cc.obj -c C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\samples\sample5_unittest.cc

third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.i"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\samples\sample5_unittest.cc > CMakeFiles\sample5_unittest.dir\samples\sample5_unittest.cc.i

third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.s"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\samples\sample5_unittest.cc -o CMakeFiles\sample5_unittest.dir\samples\sample5_unittest.cc.s

third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.obj: third_parties/googletest/CMakeFiles/sample5_unittest.dir/flags.make
third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.obj: third_parties/googletest/CMakeFiles/sample5_unittest.dir/includes_CXX.rsp
third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.obj: third_parties/googletest/samples/sample1.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Charles.Socie\Desktop\Westguard-SSM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.obj"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sample5_unittest.dir\samples\sample1.cc.obj -c C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\samples\sample1.cc

third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample5_unittest.dir/samples/sample1.cc.i"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\samples\sample1.cc > CMakeFiles\sample5_unittest.dir\samples\sample1.cc.i

third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample5_unittest.dir/samples/sample1.cc.s"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\samples\sample1.cc -o CMakeFiles\sample5_unittest.dir\samples\sample1.cc.s

# Object files for target sample5_unittest
sample5_unittest_OBJECTS = \
"CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.obj" \
"CMakeFiles/sample5_unittest.dir/samples/sample1.cc.obj"

# External object files for target sample5_unittest
sample5_unittest_EXTERNAL_OBJECTS =

third_parties/googletest/sample5_unittest.exe: third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample5_unittest.cc.obj
third_parties/googletest/sample5_unittest.exe: third_parties/googletest/CMakeFiles/sample5_unittest.dir/samples/sample1.cc.obj
third_parties/googletest/sample5_unittest.exe: third_parties/googletest/CMakeFiles/sample5_unittest.dir/build.make
third_parties/googletest/sample5_unittest.exe: third_parties/googletest/libgtest_main.a
third_parties/googletest/sample5_unittest.exe: third_parties/googletest/libgtest.a
third_parties/googletest/sample5_unittest.exe: third_parties/googletest/CMakeFiles/sample5_unittest.dir/linklibs.rsp
third_parties/googletest/sample5_unittest.exe: third_parties/googletest/CMakeFiles/sample5_unittest.dir/objects1.rsp
third_parties/googletest/sample5_unittest.exe: third_parties/googletest/CMakeFiles/sample5_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Charles.Socie\Desktop\Westguard-SSM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sample5_unittest.exe"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sample5_unittest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_parties/googletest/CMakeFiles/sample5_unittest.dir/build: third_parties/googletest/sample5_unittest.exe

.PHONY : third_parties/googletest/CMakeFiles/sample5_unittest.dir/build

third_parties/googletest/CMakeFiles/sample5_unittest.dir/clean:
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && $(CMAKE_COMMAND) -P CMakeFiles\sample5_unittest.dir\cmake_clean.cmake
.PHONY : third_parties/googletest/CMakeFiles/sample5_unittest.dir/clean

third_parties/googletest/CMakeFiles/sample5_unittest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Charles.Socie\Desktop\Westguard-SSM C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest C:\Users\Charles.Socie\Desktop\Westguard-SSM C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\CMakeFiles\sample5_unittest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : third_parties/googletest/CMakeFiles/sample5_unittest.dir/depend

