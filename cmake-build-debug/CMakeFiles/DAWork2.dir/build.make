# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /snap/clion/190/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/190/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guilherme/CLionProjects/DAWork2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guilherme/CLionProjects/DAWork2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DAWork2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DAWork2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DAWork2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DAWork2.dir/flags.make

CMakeFiles/DAWork2.dir/Source/main.cpp.o: CMakeFiles/DAWork2.dir/flags.make
CMakeFiles/DAWork2.dir/Source/main.cpp.o: ../Source/main.cpp
CMakeFiles/DAWork2.dir/Source/main.cpp.o: CMakeFiles/DAWork2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/CLionProjects/DAWork2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DAWork2.dir/Source/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAWork2.dir/Source/main.cpp.o -MF CMakeFiles/DAWork2.dir/Source/main.cpp.o.d -o CMakeFiles/DAWork2.dir/Source/main.cpp.o -c /home/guilherme/CLionProjects/DAWork2/Source/main.cpp

CMakeFiles/DAWork2.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAWork2.dir/Source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guilherme/CLionProjects/DAWork2/Source/main.cpp > CMakeFiles/DAWork2.dir/Source/main.cpp.i

CMakeFiles/DAWork2.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAWork2.dir/Source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guilherme/CLionProjects/DAWork2/Source/main.cpp -o CMakeFiles/DAWork2.dir/Source/main.cpp.s

CMakeFiles/DAWork2.dir/Source/Reader.cpp.o: CMakeFiles/DAWork2.dir/flags.make
CMakeFiles/DAWork2.dir/Source/Reader.cpp.o: ../Source/Reader.cpp
CMakeFiles/DAWork2.dir/Source/Reader.cpp.o: CMakeFiles/DAWork2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/CLionProjects/DAWork2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DAWork2.dir/Source/Reader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAWork2.dir/Source/Reader.cpp.o -MF CMakeFiles/DAWork2.dir/Source/Reader.cpp.o.d -o CMakeFiles/DAWork2.dir/Source/Reader.cpp.o -c /home/guilherme/CLionProjects/DAWork2/Source/Reader.cpp

CMakeFiles/DAWork2.dir/Source/Reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAWork2.dir/Source/Reader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guilherme/CLionProjects/DAWork2/Source/Reader.cpp > CMakeFiles/DAWork2.dir/Source/Reader.cpp.i

CMakeFiles/DAWork2.dir/Source/Reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAWork2.dir/Source/Reader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guilherme/CLionProjects/DAWork2/Source/Reader.cpp -o CMakeFiles/DAWork2.dir/Source/Reader.cpp.s

CMakeFiles/DAWork2.dir/Source/Travels.cpp.o: CMakeFiles/DAWork2.dir/flags.make
CMakeFiles/DAWork2.dir/Source/Travels.cpp.o: ../Source/Travels.cpp
CMakeFiles/DAWork2.dir/Source/Travels.cpp.o: CMakeFiles/DAWork2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/CLionProjects/DAWork2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DAWork2.dir/Source/Travels.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAWork2.dir/Source/Travels.cpp.o -MF CMakeFiles/DAWork2.dir/Source/Travels.cpp.o.d -o CMakeFiles/DAWork2.dir/Source/Travels.cpp.o -c /home/guilherme/CLionProjects/DAWork2/Source/Travels.cpp

CMakeFiles/DAWork2.dir/Source/Travels.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAWork2.dir/Source/Travels.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guilherme/CLionProjects/DAWork2/Source/Travels.cpp > CMakeFiles/DAWork2.dir/Source/Travels.cpp.i

CMakeFiles/DAWork2.dir/Source/Travels.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAWork2.dir/Source/Travels.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guilherme/CLionProjects/DAWork2/Source/Travels.cpp -o CMakeFiles/DAWork2.dir/Source/Travels.cpp.s

CMakeFiles/DAWork2.dir/Source/Manager.cpp.o: CMakeFiles/DAWork2.dir/flags.make
CMakeFiles/DAWork2.dir/Source/Manager.cpp.o: ../Source/Manager.cpp
CMakeFiles/DAWork2.dir/Source/Manager.cpp.o: CMakeFiles/DAWork2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/CLionProjects/DAWork2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DAWork2.dir/Source/Manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAWork2.dir/Source/Manager.cpp.o -MF CMakeFiles/DAWork2.dir/Source/Manager.cpp.o.d -o CMakeFiles/DAWork2.dir/Source/Manager.cpp.o -c /home/guilherme/CLionProjects/DAWork2/Source/Manager.cpp

CMakeFiles/DAWork2.dir/Source/Manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAWork2.dir/Source/Manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guilherme/CLionProjects/DAWork2/Source/Manager.cpp > CMakeFiles/DAWork2.dir/Source/Manager.cpp.i

CMakeFiles/DAWork2.dir/Source/Manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAWork2.dir/Source/Manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guilherme/CLionProjects/DAWork2/Source/Manager.cpp -o CMakeFiles/DAWork2.dir/Source/Manager.cpp.s

# Object files for target DAWork2
DAWork2_OBJECTS = \
"CMakeFiles/DAWork2.dir/Source/main.cpp.o" \
"CMakeFiles/DAWork2.dir/Source/Reader.cpp.o" \
"CMakeFiles/DAWork2.dir/Source/Travels.cpp.o" \
"CMakeFiles/DAWork2.dir/Source/Manager.cpp.o"

# External object files for target DAWork2
DAWork2_EXTERNAL_OBJECTS =

DAWork2: CMakeFiles/DAWork2.dir/Source/main.cpp.o
DAWork2: CMakeFiles/DAWork2.dir/Source/Reader.cpp.o
DAWork2: CMakeFiles/DAWork2.dir/Source/Travels.cpp.o
DAWork2: CMakeFiles/DAWork2.dir/Source/Manager.cpp.o
DAWork2: CMakeFiles/DAWork2.dir/build.make
DAWork2: CMakeFiles/DAWork2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guilherme/CLionProjects/DAWork2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DAWork2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DAWork2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DAWork2.dir/build: DAWork2
.PHONY : CMakeFiles/DAWork2.dir/build

CMakeFiles/DAWork2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DAWork2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DAWork2.dir/clean

CMakeFiles/DAWork2.dir/depend:
	cd /home/guilherme/CLionProjects/DAWork2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guilherme/CLionProjects/DAWork2 /home/guilherme/CLionProjects/DAWork2 /home/guilherme/CLionProjects/DAWork2/cmake-build-debug /home/guilherme/CLionProjects/DAWork2/cmake-build-debug /home/guilherme/CLionProjects/DAWork2/cmake-build-debug/CMakeFiles/DAWork2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DAWork2.dir/depend
