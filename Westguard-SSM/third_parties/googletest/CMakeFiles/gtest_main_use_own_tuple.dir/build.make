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
include third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/depend.make

# Include the progress variables for this target.
include third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/progress.make

# Include the compile flags for this target's objects.
include third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/flags.make

third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.obj: third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/flags.make
third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.obj: third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/includes_CXX.rsp
third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.obj: third_parties/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Charles.Socie\Desktop\Westguard-SSM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.obj"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest_main_use_own_tuple.dir\src\gtest-all.cc.obj -c C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\src\gtest-all.cc

third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.i"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\src\gtest-all.cc > CMakeFiles\gtest_main_use_own_tuple.dir\src\gtest-all.cc.i

third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.s"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\src\gtest-all.cc -o CMakeFiles\gtest_main_use_own_tuple.dir\src\gtest-all.cc.s

third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.obj: third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/flags.make
third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.obj: third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/includes_CXX.rsp
third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.obj: third_parties/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Charles.Socie\Desktop\Westguard-SSM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.obj"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest_main_use_own_tuple.dir\src\gtest_main.cc.obj -c C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\src\gtest_main.cc

third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.i"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\src\gtest_main.cc > CMakeFiles\gtest_main_use_own_tuple.dir\src\gtest_main.cc.i

third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.s"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\src\gtest_main.cc -o CMakeFiles\gtest_main_use_own_tuple.dir\src\gtest_main.cc.s

# Object files for target gtest_main_use_own_tuple
gtest_main_use_own_tuple_OBJECTS = \
"CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.obj" \
"CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.obj"

# External object files for target gtest_main_use_own_tuple
gtest_main_use_own_tuple_EXTERNAL_OBJECTS =

third_parties/googletest/libgtest_main_use_own_tuple.a: third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest-all.cc.obj
third_parties/googletest/libgtest_main_use_own_tuple.a: third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/src/gtest_main.cc.obj
third_parties/googletest/libgtest_main_use_own_tuple.a: third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/build.make
third_parties/googletest/libgtest_main_use_own_tuple.a: third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Charles.Socie\Desktop\Westguard-SSM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgtest_main_use_own_tuple.a"
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && $(CMAKE_COMMAND) -P CMakeFiles\gtest_main_use_own_tuple.dir\cmake_clean_target.cmake
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest_main_use_own_tuple.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/build: third_parties/googletest/libgtest_main_use_own_tuple.a

.PHONY : third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/build

third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/clean:
	cd /d C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest && $(CMAKE_COMMAND) -P CMakeFiles\gtest_main_use_own_tuple.dir\cmake_clean.cmake
.PHONY : third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/clean

third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Charles.Socie\Desktop\Westguard-SSM C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest C:\Users\Charles.Socie\Desktop\Westguard-SSM C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest C:\Users\Charles.Socie\Desktop\Westguard-SSM\third_parties\googletest\CMakeFiles\gtest_main_use_own_tuple.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : third_parties/googletest/CMakeFiles/gtest_main_use_own_tuple.dir/depend

