# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion-2017.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lbarrios/Documents/uba-algo2-2017-2c/labo1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/correrMain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/correrMain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/correrMain.dir/flags.make

CMakeFiles/correrMain.dir/src/matriz.cpp.o: CMakeFiles/correrMain.dir/flags.make
CMakeFiles/correrMain.dir/src/matriz.cpp.o: ../src/matriz.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/correrMain.dir/src/matriz.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrMain.dir/src/matriz.cpp.o -c /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/src/matriz.cpp

CMakeFiles/correrMain.dir/src/matriz.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrMain.dir/src/matriz.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/src/matriz.cpp > CMakeFiles/correrMain.dir/src/matriz.cpp.i

CMakeFiles/correrMain.dir/src/matriz.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrMain.dir/src/matriz.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/src/matriz.cpp -o CMakeFiles/correrMain.dir/src/matriz.cpp.s

CMakeFiles/correrMain.dir/src/matriz.cpp.o.requires:

.PHONY : CMakeFiles/correrMain.dir/src/matriz.cpp.o.requires

CMakeFiles/correrMain.dir/src/matriz.cpp.o.provides: CMakeFiles/correrMain.dir/src/matriz.cpp.o.requires
	$(MAKE) -f CMakeFiles/correrMain.dir/build.make CMakeFiles/correrMain.dir/src/matriz.cpp.o.provides.build
.PHONY : CMakeFiles/correrMain.dir/src/matriz.cpp.o.provides

CMakeFiles/correrMain.dir/src/matriz.cpp.o.provides.build: CMakeFiles/correrMain.dir/src/matriz.cpp.o


CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o: CMakeFiles/correrMain.dir/flags.make
CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o: ../src/matriz_ops.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o -c /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/src/matriz_ops.cpp

CMakeFiles/correrMain.dir/src/matriz_ops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrMain.dir/src/matriz_ops.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/src/matriz_ops.cpp > CMakeFiles/correrMain.dir/src/matriz_ops.cpp.i

CMakeFiles/correrMain.dir/src/matriz_ops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrMain.dir/src/matriz_ops.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/src/matriz_ops.cpp -o CMakeFiles/correrMain.dir/src/matriz_ops.cpp.s

CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o.requires:

.PHONY : CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o.requires

CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o.provides: CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o.requires
	$(MAKE) -f CMakeFiles/correrMain.dir/build.make CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o.provides.build
.PHONY : CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o.provides

CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o.provides.build: CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o


CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o: CMakeFiles/correrMain.dir/flags.make
CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o: ../tests/matriz-test-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o -c /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/tests/matriz-test-main.cpp

CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/tests/matriz-test-main.cpp > CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.i

CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/tests/matriz-test-main.cpp -o CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.s

CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o.requires:

.PHONY : CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o.requires

CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o.provides: CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o.requires
	$(MAKE) -f CMakeFiles/correrMain.dir/build.make CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o.provides.build
.PHONY : CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o.provides

CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o.provides.build: CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o


# Object files for target correrMain
correrMain_OBJECTS = \
"CMakeFiles/correrMain.dir/src/matriz.cpp.o" \
"CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o" \
"CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o"

# External object files for target correrMain
correrMain_EXTERNAL_OBJECTS =

correrMain: CMakeFiles/correrMain.dir/src/matriz.cpp.o
correrMain: CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o
correrMain: CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o
correrMain: CMakeFiles/correrMain.dir/build.make
correrMain: CMakeFiles/correrMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable correrMain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/correrMain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/correrMain.dir/build: correrMain

.PHONY : CMakeFiles/correrMain.dir/build

CMakeFiles/correrMain.dir/requires: CMakeFiles/correrMain.dir/src/matriz.cpp.o.requires
CMakeFiles/correrMain.dir/requires: CMakeFiles/correrMain.dir/src/matriz_ops.cpp.o.requires
CMakeFiles/correrMain.dir/requires: CMakeFiles/correrMain.dir/tests/matriz-test-main.cpp.o.requires

.PHONY : CMakeFiles/correrMain.dir/requires

CMakeFiles/correrMain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/correrMain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/correrMain.dir/clean

CMakeFiles/correrMain.dir/depend:
	cd /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lbarrios/Documents/uba-algo2-2017-2c/labo1 /home/lbarrios/Documents/uba-algo2-2017-2c/labo1 /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug /home/lbarrios/Documents/uba-algo2-2017-2c/labo1/cmake-build-debug/CMakeFiles/correrMain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/correrMain.dir/depend
