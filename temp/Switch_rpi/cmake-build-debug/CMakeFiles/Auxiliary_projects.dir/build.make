# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/hubert/Public/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/hubert/Public/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Auxiliary_projects.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Auxiliary_projects.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Auxiliary_projects.dir/flags.make

CMakeFiles/Auxiliary_projects.dir/main.cpp.o: CMakeFiles/Auxiliary_projects.dir/flags.make
CMakeFiles/Auxiliary_projects.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Auxiliary_projects.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Auxiliary_projects.dir/main.cpp.o -c /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/main.cpp

CMakeFiles/Auxiliary_projects.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Auxiliary_projects.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/main.cpp > CMakeFiles/Auxiliary_projects.dir/main.cpp.i

CMakeFiles/Auxiliary_projects.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Auxiliary_projects.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/main.cpp -o CMakeFiles/Auxiliary_projects.dir/main.cpp.s

CMakeFiles/Auxiliary_projects.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Auxiliary_projects.dir/main.cpp.o.requires

CMakeFiles/Auxiliary_projects.dir/main.cpp.o.provides: CMakeFiles/Auxiliary_projects.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Auxiliary_projects.dir/build.make CMakeFiles/Auxiliary_projects.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Auxiliary_projects.dir/main.cpp.o.provides

CMakeFiles/Auxiliary_projects.dir/main.cpp.o.provides.build: CMakeFiles/Auxiliary_projects.dir/main.cpp.o


# Object files for target Auxiliary_projects
Auxiliary_projects_OBJECTS = \
"CMakeFiles/Auxiliary_projects.dir/main.cpp.o"

# External object files for target Auxiliary_projects
Auxiliary_projects_EXTERNAL_OBJECTS =

Auxiliary_projects: CMakeFiles/Auxiliary_projects.dir/main.cpp.o
Auxiliary_projects: CMakeFiles/Auxiliary_projects.dir/build.make
Auxiliary_projects: CMakeFiles/Auxiliary_projects.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Auxiliary_projects"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Auxiliary_projects.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Auxiliary_projects.dir/build: Auxiliary_projects

.PHONY : CMakeFiles/Auxiliary_projects.dir/build

CMakeFiles/Auxiliary_projects.dir/requires: CMakeFiles/Auxiliary_projects.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Auxiliary_projects.dir/requires

CMakeFiles/Auxiliary_projects.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Auxiliary_projects.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Auxiliary_projects.dir/clean

CMakeFiles/Auxiliary_projects.dir/depend:
	cd /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/cmake-build-debug /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/cmake-build-debug /home/hubert/Documents/Projekty/Auxiliary_projects/Switch_rpi/cmake-build-debug/CMakeFiles/Auxiliary_projects.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Auxiliary_projects.dir/depend

