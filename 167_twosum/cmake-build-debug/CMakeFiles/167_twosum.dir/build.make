# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michealki/Desktop/leetcode/167_twosum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michealki/Desktop/leetcode/167_twosum/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/167_twosum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/167_twosum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/167_twosum.dir/flags.make

CMakeFiles/167_twosum.dir/main.cpp.o: CMakeFiles/167_twosum.dir/flags.make
CMakeFiles/167_twosum.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michealki/Desktop/leetcode/167_twosum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/167_twosum.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/167_twosum.dir/main.cpp.o -c /Users/michealki/Desktop/leetcode/167_twosum/main.cpp

CMakeFiles/167_twosum.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/167_twosum.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/michealki/Desktop/leetcode/167_twosum/main.cpp > CMakeFiles/167_twosum.dir/main.cpp.i

CMakeFiles/167_twosum.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/167_twosum.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/michealki/Desktop/leetcode/167_twosum/main.cpp -o CMakeFiles/167_twosum.dir/main.cpp.s

# Object files for target 167_twosum
167_twosum_OBJECTS = \
"CMakeFiles/167_twosum.dir/main.cpp.o"

# External object files for target 167_twosum
167_twosum_EXTERNAL_OBJECTS =

167_twosum: CMakeFiles/167_twosum.dir/main.cpp.o
167_twosum: CMakeFiles/167_twosum.dir/build.make
167_twosum: CMakeFiles/167_twosum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michealki/Desktop/leetcode/167_twosum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 167_twosum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/167_twosum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/167_twosum.dir/build: 167_twosum

.PHONY : CMakeFiles/167_twosum.dir/build

CMakeFiles/167_twosum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/167_twosum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/167_twosum.dir/clean

CMakeFiles/167_twosum.dir/depend:
	cd /Users/michealki/Desktop/leetcode/167_twosum/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michealki/Desktop/leetcode/167_twosum /Users/michealki/Desktop/leetcode/167_twosum /Users/michealki/Desktop/leetcode/167_twosum/cmake-build-debug /Users/michealki/Desktop/leetcode/167_twosum/cmake-build-debug /Users/michealki/Desktop/leetcode/167_twosum/cmake-build-debug/CMakeFiles/167_twosum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/167_twosum.dir/depend

