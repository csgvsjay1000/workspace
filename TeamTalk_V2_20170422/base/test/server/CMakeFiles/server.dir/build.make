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
CMAKE_SOURCE_DIR = /root/workspace/TeamTalk_V2_20170422/base/test/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/workspace/TeamTalk_V2_20170422/base/test/server

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server.cpp.o: server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/TeamTalk_V2_20170422/base/test/server/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/server.cpp.o -c /root/workspace/TeamTalk_V2_20170422/base/test/server/server.cpp

CMakeFiles/server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/TeamTalk_V2_20170422/base/test/server/server.cpp > CMakeFiles/server.dir/server.cpp.i

CMakeFiles/server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/TeamTalk_V2_20170422/base/test/server/server.cpp -o CMakeFiles/server.dir/server.cpp.s

CMakeFiles/server.dir/server.cpp.o.requires:
.PHONY : CMakeFiles/server.dir/server.cpp.o.requires

CMakeFiles/server.dir/server.cpp.o.provides: CMakeFiles/server.dir/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/server.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/server.cpp.o.provides

CMakeFiles/server.dir/server.cpp.o.provides.build: CMakeFiles/server.dir/server.cpp.o

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o: /root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/TeamTalk_V2_20170422/base/test/server/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o -c /root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp > CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.i

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.s

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o.requires:
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o.requires

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o.provides: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o.provides

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o.provides.build: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o: /root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/TeamTalk_V2_20170422/base/test/server/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o -c /root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp > CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.i

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.s

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o.requires:
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o.requires

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o.provides: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o.provides

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o.provides.build: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o: /root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/TeamTalk_V2_20170422/base/test/server/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o -c /root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp > CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.i

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.s

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o.requires:
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o.requires

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o.provides: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o.provides

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o.provides.build: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o: /root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/TeamTalk_V2_20170422/base/test/server/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o -c /root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp > CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.i

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.s

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o.requires:
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o.requires

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o.provides: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o.provides

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o.provides.build: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o: /root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/TeamTalk_V2_20170422/base/test/server/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o -c /root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc > CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.i

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.s

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o.requires:
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o.requires

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o.provides: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o.provides.build
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o.provides

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o.provides.build: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o: /root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/TeamTalk_V2_20170422/base/test/server/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o -c /root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc > CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.i

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc -o CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.s

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o.requires:
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o.requires

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o.provides: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o.provides.build
.PHONY : CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o.provides

CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o.provides.build: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/server.cpp.o" \
"CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o" \
"CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o" \
"CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o" \
"CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o" \
"CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o" \
"CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/server.cpp.o
server: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o
server: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o
server: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o
server: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o
server: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o
server: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/server.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZSimpleBuffer.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZPduBase.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZEventDispatch.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/SZBaseSocket.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.Server.pb.cc.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/root/workspace/TeamTalk_V2_20170422/base/pb/IM.BaseDefine.pb.cc.o.requires
.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /root/workspace/TeamTalk_V2_20170422/base/test/server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/workspace/TeamTalk_V2_20170422/base/test/server /root/workspace/TeamTalk_V2_20170422/base/test/server /root/workspace/TeamTalk_V2_20170422/base/test/server /root/workspace/TeamTalk_V2_20170422/base/test/server /root/workspace/TeamTalk_V2_20170422/base/test/server/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

