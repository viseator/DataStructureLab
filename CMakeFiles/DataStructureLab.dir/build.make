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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/viseator/study/DataStructureLab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/viseator/study/DataStructureLab

# Include any dependencies generated for this target.
include CMakeFiles/DataStructureLab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructureLab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructureLab.dir/flags.make

CMakeFiles/DataStructureLab.dir/main.cpp.o: CMakeFiles/DataStructureLab.dir/flags.make
CMakeFiles/DataStructureLab.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viseator/study/DataStructureLab/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataStructureLab.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataStructureLab.dir/main.cpp.o -c /home/viseator/study/DataStructureLab/main.cpp

CMakeFiles/DataStructureLab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructureLab.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viseator/study/DataStructureLab/main.cpp > CMakeFiles/DataStructureLab.dir/main.cpp.i

CMakeFiles/DataStructureLab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructureLab.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viseator/study/DataStructureLab/main.cpp -o CMakeFiles/DataStructureLab.dir/main.cpp.s

CMakeFiles/DataStructureLab.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DataStructureLab.dir/main.cpp.o.requires

CMakeFiles/DataStructureLab.dir/main.cpp.o.provides: CMakeFiles/DataStructureLab.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DataStructureLab.dir/build.make CMakeFiles/DataStructureLab.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DataStructureLab.dir/main.cpp.o.provides

CMakeFiles/DataStructureLab.dir/main.cpp.o.provides.build: CMakeFiles/DataStructureLab.dir/main.cpp.o


CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o: CMakeFiles/DataStructureLab.dir/flags.make
CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o: datastructure/linkedlist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viseator/study/DataStructureLab/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o -c /home/viseator/study/DataStructureLab/datastructure/linkedlist.cpp

CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viseator/study/DataStructureLab/datastructure/linkedlist.cpp > CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.i

CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viseator/study/DataStructureLab/datastructure/linkedlist.cpp -o CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.s

CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o.requires:

.PHONY : CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o.requires

CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o.provides: CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o.requires
	$(MAKE) -f CMakeFiles/DataStructureLab.dir/build.make CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o.provides.build
.PHONY : CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o.provides

CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o.provides.build: CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o


# Object files for target DataStructureLab
DataStructureLab_OBJECTS = \
"CMakeFiles/DataStructureLab.dir/main.cpp.o" \
"CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o"

# External object files for target DataStructureLab
DataStructureLab_EXTERNAL_OBJECTS =

DataStructureLab: CMakeFiles/DataStructureLab.dir/main.cpp.o
DataStructureLab: CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o
DataStructureLab: CMakeFiles/DataStructureLab.dir/build.make
DataStructureLab: CMakeFiles/DataStructureLab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/viseator/study/DataStructureLab/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DataStructureLab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructureLab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructureLab.dir/build: DataStructureLab

.PHONY : CMakeFiles/DataStructureLab.dir/build

CMakeFiles/DataStructureLab.dir/requires: CMakeFiles/DataStructureLab.dir/main.cpp.o.requires
CMakeFiles/DataStructureLab.dir/requires: CMakeFiles/DataStructureLab.dir/datastructure/linkedlist.cpp.o.requires

.PHONY : CMakeFiles/DataStructureLab.dir/requires

CMakeFiles/DataStructureLab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataStructureLab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataStructureLab.dir/clean

CMakeFiles/DataStructureLab.dir/depend:
	cd /home/viseator/study/DataStructureLab && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viseator/study/DataStructureLab /home/viseator/study/DataStructureLab /home/viseator/study/DataStructureLab /home/viseator/study/DataStructureLab /home/viseator/study/DataStructureLab/CMakeFiles/DataStructureLab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataStructureLab.dir/depend
