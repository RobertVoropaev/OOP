# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/rv/Programs/CLion-2019.3.3/clion-2019.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/rv/Programs/CLion-2019.3.3/clion-2019.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rv/projects/OOP/dz11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rv/projects/OOP/dz11/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dz11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dz11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dz11.dir/flags.make

CMakeFiles/dz11.dir/main.cpp.o: CMakeFiles/dz11.dir/flags.make
CMakeFiles/dz11.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rv/projects/OOP/dz11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dz11.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dz11.dir/main.cpp.o -c /home/rv/projects/OOP/dz11/main.cpp

CMakeFiles/dz11.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dz11.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rv/projects/OOP/dz11/main.cpp > CMakeFiles/dz11.dir/main.cpp.i

CMakeFiles/dz11.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dz11.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rv/projects/OOP/dz11/main.cpp -o CMakeFiles/dz11.dir/main.cpp.s

# Object files for target dz11
dz11_OBJECTS = \
"CMakeFiles/dz11.dir/main.cpp.o"

# External object files for target dz11
dz11_EXTERNAL_OBJECTS =

dz11: CMakeFiles/dz11.dir/main.cpp.o
dz11: CMakeFiles/dz11.dir/build.make
dz11: CMakeFiles/dz11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rv/projects/OOP/dz11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dz11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dz11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dz11.dir/build: dz11

.PHONY : CMakeFiles/dz11.dir/build

CMakeFiles/dz11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dz11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dz11.dir/clean

CMakeFiles/dz11.dir/depend:
	cd /home/rv/projects/OOP/dz11/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rv/projects/OOP/dz11 /home/rv/projects/OOP/dz11 /home/rv/projects/OOP/dz11/cmake-build-debug /home/rv/projects/OOP/dz11/cmake-build-debug /home/rv/projects/OOP/dz11/cmake-build-debug/CMakeFiles/dz11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dz11.dir/depend

