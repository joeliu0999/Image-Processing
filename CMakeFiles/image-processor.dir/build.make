# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\COP 3504\C++\project 3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\COP 3504\C++\project 3"

# Include any dependencies generated for this target.
include CMakeFiles/image-processor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image-processor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image-processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image-processor.dir/flags.make

CMakeFiles/image-processor.dir/image-processor.cpp.obj: CMakeFiles/image-processor.dir/flags.make
CMakeFiles/image-processor.dir/image-processor.cpp.obj: image-processor.cpp
CMakeFiles/image-processor.dir/image-processor.cpp.obj: CMakeFiles/image-processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\COP 3504\C++\project 3\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image-processor.dir/image-processor.cpp.obj"
	C:\ProgramData\chocolatey\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image-processor.dir/image-processor.cpp.obj -MF CMakeFiles\image-processor.dir\image-processor.cpp.obj.d -o CMakeFiles\image-processor.dir\image-processor.cpp.obj -c "D:\COP 3504\C++\project 3\image-processor.cpp"

CMakeFiles/image-processor.dir/image-processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image-processor.dir/image-processor.cpp.i"
	C:\ProgramData\chocolatey\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\COP 3504\C++\project 3\image-processor.cpp" > CMakeFiles\image-processor.dir\image-processor.cpp.i

CMakeFiles/image-processor.dir/image-processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image-processor.dir/image-processor.cpp.s"
	C:\ProgramData\chocolatey\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\COP 3504\C++\project 3\image-processor.cpp" -o CMakeFiles\image-processor.dir\image-processor.cpp.s

CMakeFiles/image-processor.dir/main.cpp.obj: CMakeFiles/image-processor.dir/flags.make
CMakeFiles/image-processor.dir/main.cpp.obj: main.cpp
CMakeFiles/image-processor.dir/main.cpp.obj: CMakeFiles/image-processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\COP 3504\C++\project 3\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image-processor.dir/main.cpp.obj"
	C:\ProgramData\chocolatey\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image-processor.dir/main.cpp.obj -MF CMakeFiles\image-processor.dir\main.cpp.obj.d -o CMakeFiles\image-processor.dir\main.cpp.obj -c "D:\COP 3504\C++\project 3\main.cpp"

CMakeFiles/image-processor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image-processor.dir/main.cpp.i"
	C:\ProgramData\chocolatey\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\COP 3504\C++\project 3\main.cpp" > CMakeFiles\image-processor.dir\main.cpp.i

CMakeFiles/image-processor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image-processor.dir/main.cpp.s"
	C:\ProgramData\chocolatey\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\COP 3504\C++\project 3\main.cpp" -o CMakeFiles\image-processor.dir\main.cpp.s

# Object files for target image-processor
image__processor_OBJECTS = \
"CMakeFiles/image-processor.dir/image-processor.cpp.obj" \
"CMakeFiles/image-processor.dir/main.cpp.obj"

# External object files for target image-processor
image__processor_EXTERNAL_OBJECTS =

image-processor.exe: CMakeFiles/image-processor.dir/image-processor.cpp.obj
image-processor.exe: CMakeFiles/image-processor.dir/main.cpp.obj
image-processor.exe: CMakeFiles/image-processor.dir/build.make
image-processor.exe: CMakeFiles/image-processor.dir/linkLibs.rsp
image-processor.exe: CMakeFiles/image-processor.dir/objects1
image-processor.exe: CMakeFiles/image-processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\COP 3504\C++\project 3\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable image-processor.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\image-processor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image-processor.dir/build: image-processor.exe
.PHONY : CMakeFiles/image-processor.dir/build

CMakeFiles/image-processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\image-processor.dir\cmake_clean.cmake
.PHONY : CMakeFiles/image-processor.dir/clean

CMakeFiles/image-processor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\COP 3504\C++\project 3" "D:\COP 3504\C++\project 3" "D:\COP 3504\C++\project 3" "D:\COP 3504\C++\project 3" "D:\COP 3504\C++\project 3\CMakeFiles\image-processor.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/image-processor.dir/depend

