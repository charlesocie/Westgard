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
include src/Controller/CMakeFiles/Controller.dir/depend.make

# Include the progress variables for this target.
include src/Controller/CMakeFiles/Controller.dir/progress.make

# Include the compile flags for this target's objects.
include src/Controller/CMakeFiles/Controller.dir/flags.make

src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o: src/Controller/CMakeFiles/Controller.dir/flags.make
src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o: src/Controller/EvaluateController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/EvaluateController.cpp.o -c /home/charles/Desktop/Westguard-SSM/src/Controller/EvaluateController.cpp

src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/EvaluateController.cpp.i"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/Desktop/Westguard-SSM/src/Controller/EvaluateController.cpp > CMakeFiles/Controller.dir/EvaluateController.cpp.i

src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/EvaluateController.cpp.s"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/Desktop/Westguard-SSM/src/Controller/EvaluateController.cpp -o CMakeFiles/Controller.dir/EvaluateController.cpp.s

src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o.requires:

.PHONY : src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o.requires

src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o.provides: src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o.requires
	$(MAKE) -f src/Controller/CMakeFiles/Controller.dir/build.make src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o.provides.build
.PHONY : src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o.provides

src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o.provides.build: src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o


src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o: src/Controller/CMakeFiles/Controller.dir/flags.make
src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o: src/Controller/Measure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/Measure.cpp.o -c /home/charles/Desktop/Westguard-SSM/src/Controller/Measure.cpp

src/Controller/CMakeFiles/Controller.dir/Measure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/Measure.cpp.i"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/Desktop/Westguard-SSM/src/Controller/Measure.cpp > CMakeFiles/Controller.dir/Measure.cpp.i

src/Controller/CMakeFiles/Controller.dir/Measure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/Measure.cpp.s"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/Desktop/Westguard-SSM/src/Controller/Measure.cpp -o CMakeFiles/Controller.dir/Measure.cpp.s

src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o.requires:

.PHONY : src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o.requires

src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o.provides: src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o.requires
	$(MAKE) -f src/Controller/CMakeFiles/Controller.dir/build.make src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o.provides.build
.PHONY : src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o.provides

src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o.provides.build: src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o


src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o: src/Controller/CMakeFiles/Controller.dir/flags.make
src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o: src/Controller/RuleSetting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/RuleSetting.cpp.o -c /home/charles/Desktop/Westguard-SSM/src/Controller/RuleSetting.cpp

src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/RuleSetting.cpp.i"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/Desktop/Westguard-SSM/src/Controller/RuleSetting.cpp > CMakeFiles/Controller.dir/RuleSetting.cpp.i

src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/RuleSetting.cpp.s"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/Desktop/Westguard-SSM/src/Controller/RuleSetting.cpp -o CMakeFiles/Controller.dir/RuleSetting.cpp.s

src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o.requires:

.PHONY : src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o.requires

src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o.provides: src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o.requires
	$(MAKE) -f src/Controller/CMakeFiles/Controller.dir/build.make src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o.provides.build
.PHONY : src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o.provides

src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o.provides.build: src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o


src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o: src/Controller/CMakeFiles/Controller.dir/flags.make
src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o: src/Controller/WestgardConfiguration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o -c /home/charles/Desktop/Westguard-SSM/src/Controller/WestgardConfiguration.cpp

src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/WestgardConfiguration.cpp.i"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/Desktop/Westguard-SSM/src/Controller/WestgardConfiguration.cpp > CMakeFiles/Controller.dir/WestgardConfiguration.cpp.i

src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/WestgardConfiguration.cpp.s"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/Desktop/Westguard-SSM/src/Controller/WestgardConfiguration.cpp -o CMakeFiles/Controller.dir/WestgardConfiguration.cpp.s

src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o.requires:

.PHONY : src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o.requires

src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o.provides: src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o.requires
	$(MAKE) -f src/Controller/CMakeFiles/Controller.dir/build.make src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o.provides.build
.PHONY : src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o.provides

src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o.provides.build: src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o


src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o: src/Controller/CMakeFiles/Controller.dir/flags.make
src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o: src/Controller/WestgardResult.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/WestgardResult.cpp.o -c /home/charles/Desktop/Westguard-SSM/src/Controller/WestgardResult.cpp

src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/WestgardResult.cpp.i"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/Desktop/Westguard-SSM/src/Controller/WestgardResult.cpp > CMakeFiles/Controller.dir/WestgardResult.cpp.i

src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/WestgardResult.cpp.s"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/Desktop/Westguard-SSM/src/Controller/WestgardResult.cpp -o CMakeFiles/Controller.dir/WestgardResult.cpp.s

src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o.requires:

.PHONY : src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o.requires

src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o.provides: src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o.requires
	$(MAKE) -f src/Controller/CMakeFiles/Controller.dir/build.make src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o.provides.build
.PHONY : src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o.provides

src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o.provides.build: src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o


src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o: src/Controller/CMakeFiles/Controller.dir/flags.make
src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o: src/WestgardInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o -c /home/charles/Desktop/Westguard-SSM/src/WestgardInterface.cpp

src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/__/WestgardInterface.cpp.i"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/Desktop/Westguard-SSM/src/WestgardInterface.cpp > CMakeFiles/Controller.dir/__/WestgardInterface.cpp.i

src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/__/WestgardInterface.cpp.s"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/Desktop/Westguard-SSM/src/WestgardInterface.cpp -o CMakeFiles/Controller.dir/__/WestgardInterface.cpp.s

src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o.requires:

.PHONY : src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o.requires

src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o.provides: src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o.requires
	$(MAKE) -f src/Controller/CMakeFiles/Controller.dir/build.make src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o.provides.build
.PHONY : src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o.provides

src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o.provides.build: src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o


# Object files for target Controller
Controller_OBJECTS = \
"CMakeFiles/Controller.dir/EvaluateController.cpp.o" \
"CMakeFiles/Controller.dir/Measure.cpp.o" \
"CMakeFiles/Controller.dir/RuleSetting.cpp.o" \
"CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o" \
"CMakeFiles/Controller.dir/WestgardResult.cpp.o" \
"CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o"

# External object files for target Controller
Controller_EXTERNAL_OBJECTS =

src/Controller/libController.a: src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o
src/Controller/libController.a: src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o
src/Controller/libController.a: src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o
src/Controller/libController.a: src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o
src/Controller/libController.a: src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o
src/Controller/libController.a: src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o
src/Controller/libController.a: src/Controller/CMakeFiles/Controller.dir/build.make
src/Controller/libController.a: src/Controller/CMakeFiles/Controller.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/charles/Desktop/Westguard-SSM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libController.a"
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && $(CMAKE_COMMAND) -P CMakeFiles/Controller.dir/cmake_clean_target.cmake
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Controller.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Controller/CMakeFiles/Controller.dir/build: src/Controller/libController.a

.PHONY : src/Controller/CMakeFiles/Controller.dir/build

src/Controller/CMakeFiles/Controller.dir/requires: src/Controller/CMakeFiles/Controller.dir/EvaluateController.cpp.o.requires
src/Controller/CMakeFiles/Controller.dir/requires: src/Controller/CMakeFiles/Controller.dir/Measure.cpp.o.requires
src/Controller/CMakeFiles/Controller.dir/requires: src/Controller/CMakeFiles/Controller.dir/RuleSetting.cpp.o.requires
src/Controller/CMakeFiles/Controller.dir/requires: src/Controller/CMakeFiles/Controller.dir/WestgardConfiguration.cpp.o.requires
src/Controller/CMakeFiles/Controller.dir/requires: src/Controller/CMakeFiles/Controller.dir/WestgardResult.cpp.o.requires
src/Controller/CMakeFiles/Controller.dir/requires: src/Controller/CMakeFiles/Controller.dir/__/WestgardInterface.cpp.o.requires

.PHONY : src/Controller/CMakeFiles/Controller.dir/requires

src/Controller/CMakeFiles/Controller.dir/clean:
	cd /home/charles/Desktop/Westguard-SSM/src/Controller && $(CMAKE_COMMAND) -P CMakeFiles/Controller.dir/cmake_clean.cmake
.PHONY : src/Controller/CMakeFiles/Controller.dir/clean

src/Controller/CMakeFiles/Controller.dir/depend:
	cd /home/charles/Desktop/Westguard-SSM && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/charles/Desktop/Westguard-SSM /home/charles/Desktop/Westguard-SSM/src/Controller /home/charles/Desktop/Westguard-SSM /home/charles/Desktop/Westguard-SSM/src/Controller /home/charles/Desktop/Westguard-SSM/src/Controller/CMakeFiles/Controller.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Controller/CMakeFiles/Controller.dir/depend

