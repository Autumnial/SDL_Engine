# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/cel/lil bit o storag/dev/c++/colon three"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/cel/lil bit o storag/dev/c++/colon three/build"

# Include any dependencies generated for this target.
include Engine/Math/CMakeFiles/Test-Math.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Engine/Math/CMakeFiles/Test-Math.dir/compiler_depend.make

# Include the progress variables for this target.
include Engine/Math/CMakeFiles/Test-Math.dir/progress.make

# Include the compile flags for this target's objects.
include Engine/Math/CMakeFiles/Test-Math.dir/flags.make

Engine/Math/CMakeFiles/Test-Math.dir/src/test.cpp.o: Engine/Math/CMakeFiles/Test-Math.dir/flags.make
Engine/Math/CMakeFiles/Test-Math.dir/src/test.cpp.o: /media/cel/lil\ bit\ o\ storag/dev/c++/colon\ three/Engine/Math/src/test.cpp
Engine/Math/CMakeFiles/Test-Math.dir/src/test.cpp.o: Engine/Math/CMakeFiles/Test-Math.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/media/cel/lil bit o storag/dev/c++/colon three/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Engine/Math/CMakeFiles/Test-Math.dir/src/test.cpp.o"
	cd "/media/cel/lil bit o storag/dev/c++/colon three/build/Engine/Math" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Engine/Math/CMakeFiles/Test-Math.dir/src/test.cpp.o -MF CMakeFiles/Test-Math.dir/src/test.cpp.o.d -o CMakeFiles/Test-Math.dir/src/test.cpp.o -c "/media/cel/lil bit o storag/dev/c++/colon three/Engine/Math/src/test.cpp"

Engine/Math/CMakeFiles/Test-Math.dir/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test-Math.dir/src/test.cpp.i"
	cd "/media/cel/lil bit o storag/dev/c++/colon three/build/Engine/Math" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/cel/lil bit o storag/dev/c++/colon three/Engine/Math/src/test.cpp" > CMakeFiles/Test-Math.dir/src/test.cpp.i

Engine/Math/CMakeFiles/Test-Math.dir/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test-Math.dir/src/test.cpp.s"
	cd "/media/cel/lil bit o storag/dev/c++/colon three/build/Engine/Math" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/cel/lil bit o storag/dev/c++/colon three/Engine/Math/src/test.cpp" -o CMakeFiles/Test-Math.dir/src/test.cpp.s

# Object files for target Test-Math
Test__Math_OBJECTS = \
"CMakeFiles/Test-Math.dir/src/test.cpp.o"

# External object files for target Test-Math
Test__Math_EXTERNAL_OBJECTS =

Test-Math: Engine/Math/CMakeFiles/Test-Math.dir/src/test.cpp.o
Test-Math: Engine/Math/CMakeFiles/Test-Math.dir/build.make
Test-Math: Engine/Math/CMakeFiles/Test-Math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/media/cel/lil bit o storag/dev/c++/colon three/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../Test-Math"
	cd "/media/cel/lil bit o storag/dev/c++/colon three/build/Engine/Math" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test-Math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Engine/Math/CMakeFiles/Test-Math.dir/build: Test-Math
.PHONY : Engine/Math/CMakeFiles/Test-Math.dir/build

Engine/Math/CMakeFiles/Test-Math.dir/clean:
	cd "/media/cel/lil bit o storag/dev/c++/colon three/build/Engine/Math" && $(CMAKE_COMMAND) -P CMakeFiles/Test-Math.dir/cmake_clean.cmake
.PHONY : Engine/Math/CMakeFiles/Test-Math.dir/clean

Engine/Math/CMakeFiles/Test-Math.dir/depend:
	cd "/media/cel/lil bit o storag/dev/c++/colon three/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/cel/lil bit o storag/dev/c++/colon three" "/media/cel/lil bit o storag/dev/c++/colon three/Engine/Math" "/media/cel/lil bit o storag/dev/c++/colon three/build" "/media/cel/lil bit o storag/dev/c++/colon three/build/Engine/Math" "/media/cel/lil bit o storag/dev/c++/colon three/build/Engine/Math/CMakeFiles/Test-Math.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : Engine/Math/CMakeFiles/Test-Math.dir/depend

