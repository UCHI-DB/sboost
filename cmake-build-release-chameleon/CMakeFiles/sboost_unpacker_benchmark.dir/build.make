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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.i9YVyPYwPO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.i9YVyPYwPO/cmake-build-release-chameleon

# Include any dependencies generated for this target.
include CMakeFiles/sboost_unpacker_benchmark.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sboost_unpacker_benchmark.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sboost_unpacker_benchmark.dir/flags.make

CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.o: CMakeFiles/sboost_unpacker_benchmark.dir/flags.make
CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.o: ../unpacker_benchmark.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.i9YVyPYwPO/cmake-build-release-chameleon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.o -c /tmp/tmp.i9YVyPYwPO/unpacker_benchmark.cc

CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.i9YVyPYwPO/unpacker_benchmark.cc > CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.i

CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.i9YVyPYwPO/unpacker_benchmark.cc -o CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.s

# Object files for target sboost_unpacker_benchmark
sboost_unpacker_benchmark_OBJECTS = \
"CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.o"

# External object files for target sboost_unpacker_benchmark
sboost_unpacker_benchmark_EXTERNAL_OBJECTS =

sboost_unpacker_benchmark: CMakeFiles/sboost_unpacker_benchmark.dir/unpacker_benchmark.cc.o
sboost_unpacker_benchmark: CMakeFiles/sboost_unpacker_benchmark.dir/build.make
sboost_unpacker_benchmark: gbenchmark_ep/src/gbenchmark_ep-install/lib/libbenchmark.a
sboost_unpacker_benchmark: gbenchmark_ep/src/gbenchmark_ep-install/lib/libbenchmark_main.a
sboost_unpacker_benchmark: libsboost.a
sboost_unpacker_benchmark: CMakeFiles/sboost_unpacker_benchmark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.i9YVyPYwPO/cmake-build-release-chameleon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sboost_unpacker_benchmark"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sboost_unpacker_benchmark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sboost_unpacker_benchmark.dir/build: sboost_unpacker_benchmark

.PHONY : CMakeFiles/sboost_unpacker_benchmark.dir/build

CMakeFiles/sboost_unpacker_benchmark.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sboost_unpacker_benchmark.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sboost_unpacker_benchmark.dir/clean

CMakeFiles/sboost_unpacker_benchmark.dir/depend:
	cd /tmp/tmp.i9YVyPYwPO/cmake-build-release-chameleon && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.i9YVyPYwPO /tmp/tmp.i9YVyPYwPO /tmp/tmp.i9YVyPYwPO/cmake-build-release-chameleon /tmp/tmp.i9YVyPYwPO/cmake-build-release-chameleon /tmp/tmp.i9YVyPYwPO/cmake-build-release-chameleon/CMakeFiles/sboost_unpacker_benchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sboost_unpacker_benchmark.dir/depend
