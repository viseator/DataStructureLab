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
CMAKE_COMMAND = /home/viseator/clion-2017.2.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/viseator/clion-2017.2.1/bin/cmake/bin/cmake -E remove -f

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
	/usr/bin/x86_64-w64-mingw32-c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataStructureLab.dir/main.cpp.o -c /home/viseator/study/DataStructureLab/main.cpp

CMakeFiles/DataStructureLab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructureLab.dir/main.cpp.i"
	/usr/bin/x86_64-w64-mingw32-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viseator/study/DataStructureLab/main.cpp > CMakeFiles/DataStructureLab.dir/main.cpp.i

CMakeFiles/DataStructureLab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructureLab.dir/main.cpp.s"
	/usr/bin/x86_64-w64-mingw32-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viseator/study/DataStructureLab/main.cpp -o CMakeFiles/DataStructureLab.dir/main.cpp.s

CMakeFiles/DataStructureLab.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DataStructureLab.dir/main.cpp.o.requires

CMakeFiles/DataStructureLab.dir/main.cpp.o.provides: CMakeFiles/DataStructureLab.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DataStructureLab.dir/build.make CMakeFiles/DataStructureLab.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DataStructureLab.dir/main.cpp.o.provides

CMakeFiles/DataStructureLab.dir/main.cpp.o.provides.build: CMakeFiles/DataStructureLab.dir/main.cpp.o


CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o: CMakeFiles/DataStructureLab.dir/flags.make
CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o: datastructure/Graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viseator/study/DataStructureLab/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o"
	/usr/bin/x86_64-w64-mingw32-cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o   -c /home/viseator/study/DataStructureLab/datastructure/Graph.c

CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.i"
	/usr/bin/x86_64-w64-mingw32-cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/viseator/study/DataStructureLab/datastructure/Graph.c > CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.i

CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.s"
	/usr/bin/x86_64-w64-mingw32-cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/viseator/study/DataStructureLab/datastructure/Graph.c -o CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.s

CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o.requires:

.PHONY : CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o.requires

CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o.provides: CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o.requires
	$(MAKE) -f CMakeFiles/DataStructureLab.dir/build.make CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o.provides.build
.PHONY : CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o.provides

CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o.provides.build: CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o


CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o: CMakeFiles/DataStructureLab.dir/flags.make
CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o: GraphMenu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/viseator/study/DataStructureLab/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o"
	/usr/bin/x86_64-w64-mingw32-c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o -c /home/viseator/study/DataStructureLab/GraphMenu.cpp

CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.i"
	/usr/bin/x86_64-w64-mingw32-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viseator/study/DataStructureLab/GraphMenu.cpp > CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.i

CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.s"
	/usr/bin/x86_64-w64-mingw32-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viseator/study/DataStructureLab/GraphMenu.cpp -o CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.s

CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o.requires:

.PHONY : CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o.requires

CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o.provides: CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o.requires
	$(MAKE) -f CMakeFiles/DataStructureLab.dir/build.make CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o.provides.build
.PHONY : CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o.provides

CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o.provides.build: CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o


# Object files for target DataStructureLab
DataStructureLab_OBJECTS = \
"CMakeFiles/DataStructureLab.dir/main.cpp.o" \
"CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o" \
"CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o"

# External object files for target DataStructureLab
DataStructureLab_EXTERNAL_OBJECTS =

DataStructureLab: CMakeFiles/DataStructureLab.dir/main.cpp.o
DataStructureLab: CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o
DataStructureLab: CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o
DataStructureLab: CMakeFiles/DataStructureLab.dir/build.make
DataStructureLab: CMakeFiles/DataStructureLab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/viseator/study/DataStructureLab/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DataStructureLab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructureLab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructureLab.dir/build: DataStructureLab

.PHONY : CMakeFiles/DataStructureLab.dir/build

CMakeFiles/DataStructureLab.dir/requires: CMakeFiles/DataStructureLab.dir/main.cpp.o.requires
CMakeFiles/DataStructureLab.dir/requires: CMakeFiles/DataStructureLab.dir/datastructure/Graph.c.o.requires
CMakeFiles/DataStructureLab.dir/requires: CMakeFiles/DataStructureLab.dir/GraphMenu.cpp.o.requires

.PHONY : CMakeFiles/DataStructureLab.dir/requires

CMakeFiles/DataStructureLab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataStructureLab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataStructureLab.dir/clean

CMakeFiles/DataStructureLab.dir/depend:
	cd /home/viseator/study/DataStructureLab && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viseator/study/DataStructureLab /home/viseator/study/DataStructureLab /home/viseator/study/DataStructureLab /home/viseator/study/DataStructureLab /home/viseator/study/DataStructureLab/CMakeFiles/DataStructureLab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataStructureLab.dir/depend

