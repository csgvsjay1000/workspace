# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/workspace/test/RedisTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/workspace/test/RedisTest

# Include any dependencies generated for this target.
include CMakeFiles/db_proxy_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/db_proxy_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/db_proxy_server.dir/flags.make

CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o: CMakeFiles/db_proxy_server.dir/flags.make
CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o: RedisTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/test/RedisTest/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o -c /root/workspace/test/RedisTest/RedisTest.cpp

CMakeFiles/db_proxy_server.dir/RedisTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/db_proxy_server.dir/RedisTest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/test/RedisTest/RedisTest.cpp > CMakeFiles/db_proxy_server.dir/RedisTest.cpp.i

CMakeFiles/db_proxy_server.dir/RedisTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/db_proxy_server.dir/RedisTest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/test/RedisTest/RedisTest.cpp -o CMakeFiles/db_proxy_server.dir/RedisTest.cpp.s

CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o.requires:
.PHONY : CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o.requires

CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o.provides: CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/db_proxy_server.dir/build.make CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o.provides.build
.PHONY : CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o.provides

CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o.provides.build: CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o

# Object files for target db_proxy_server
db_proxy_server_OBJECTS = \
"CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o"

# External object files for target db_proxy_server
db_proxy_server_EXTERNAL_OBJECTS =

db_proxy_server: CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o
db_proxy_server: CMakeFiles/db_proxy_server.dir/build.make
db_proxy_server: CMakeFiles/db_proxy_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable db_proxy_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/db_proxy_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/db_proxy_server.dir/build: db_proxy_server
.PHONY : CMakeFiles/db_proxy_server.dir/build

CMakeFiles/db_proxy_server.dir/requires: CMakeFiles/db_proxy_server.dir/RedisTest.cpp.o.requires
.PHONY : CMakeFiles/db_proxy_server.dir/requires

CMakeFiles/db_proxy_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/db_proxy_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/db_proxy_server.dir/clean

CMakeFiles/db_proxy_server.dir/depend:
	cd /root/workspace/test/RedisTest && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/workspace/test/RedisTest /root/workspace/test/RedisTest /root/workspace/test/RedisTest /root/workspace/test/RedisTest /root/workspace/test/RedisTest/CMakeFiles/db_proxy_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/db_proxy_server.dir/depend

