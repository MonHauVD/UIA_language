# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Lap trinh\UIA\UiaCompiler"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Lap trinh\UIA\build"

# Include any dependencies generated for this target.
include CMakeFiles/uia_compiler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/uia_compiler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/uia_compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uia_compiler.dir/flags.make

CMakeFiles/uia_compiler.dir/codegen:
.PHONY : CMakeFiles/uia_compiler.dir/codegen

CMakeFiles/uia_compiler.dir/uia_main.cpp.obj: CMakeFiles/uia_compiler.dir/flags.make
CMakeFiles/uia_compiler.dir/uia_main.cpp.obj: CMakeFiles/uia_compiler.dir/includes_CXX.rsp
CMakeFiles/uia_compiler.dir/uia_main.cpp.obj: D:/Lap\ trinh/UIA/UiaCompiler/uia_main.cpp
CMakeFiles/uia_compiler.dir/uia_main.cpp.obj: CMakeFiles/uia_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Lap trinh\UIA\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uia_compiler.dir/uia_main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/uia_compiler.dir/uia_main.cpp.obj -MF CMakeFiles\uia_compiler.dir\uia_main.cpp.obj.d -o CMakeFiles\uia_compiler.dir\uia_main.cpp.obj -c "D:\Lap trinh\UIA\UiaCompiler\uia_main.cpp"

CMakeFiles/uia_compiler.dir/uia_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uia_compiler.dir/uia_main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Lap trinh\UIA\UiaCompiler\uia_main.cpp" > CMakeFiles\uia_compiler.dir\uia_main.cpp.i

CMakeFiles/uia_compiler.dir/uia_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uia_compiler.dir/uia_main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Lap trinh\UIA\UiaCompiler\uia_main.cpp" -o CMakeFiles\uia_compiler.dir\uia_main.cpp.s

CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.obj: CMakeFiles/uia_compiler.dir/flags.make
CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.obj: CMakeFiles/uia_compiler.dir/includes_CXX.rsp
CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.obj: D:/Lap\ trinh/UIA/UiaCompiler/uia_preprocessor.cpp
CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.obj: CMakeFiles/uia_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Lap trinh\UIA\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.obj -MF CMakeFiles\uia_compiler.dir\uia_preprocessor.cpp.obj.d -o CMakeFiles\uia_compiler.dir\uia_preprocessor.cpp.obj -c "D:\Lap trinh\UIA\UiaCompiler\uia_preprocessor.cpp"

CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Lap trinh\UIA\UiaCompiler\uia_preprocessor.cpp" > CMakeFiles\uia_compiler.dir\uia_preprocessor.cpp.i

CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Lap trinh\UIA\UiaCompiler\uia_preprocessor.cpp" -o CMakeFiles\uia_compiler.dir\uia_preprocessor.cpp.s

CMakeFiles/uia_compiler.dir/uia_compiler.cpp.obj: CMakeFiles/uia_compiler.dir/flags.make
CMakeFiles/uia_compiler.dir/uia_compiler.cpp.obj: CMakeFiles/uia_compiler.dir/includes_CXX.rsp
CMakeFiles/uia_compiler.dir/uia_compiler.cpp.obj: D:/Lap\ trinh/UIA/UiaCompiler/uia_compiler.cpp
CMakeFiles/uia_compiler.dir/uia_compiler.cpp.obj: CMakeFiles/uia_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Lap trinh\UIA\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/uia_compiler.dir/uia_compiler.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/uia_compiler.dir/uia_compiler.cpp.obj -MF CMakeFiles\uia_compiler.dir\uia_compiler.cpp.obj.d -o CMakeFiles\uia_compiler.dir\uia_compiler.cpp.obj -c "D:\Lap trinh\UIA\UiaCompiler\uia_compiler.cpp"

CMakeFiles/uia_compiler.dir/uia_compiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/uia_compiler.dir/uia_compiler.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Lap trinh\UIA\UiaCompiler\uia_compiler.cpp" > CMakeFiles\uia_compiler.dir\uia_compiler.cpp.i

CMakeFiles/uia_compiler.dir/uia_compiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/uia_compiler.dir/uia_compiler.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Lap trinh\UIA\UiaCompiler\uia_compiler.cpp" -o CMakeFiles\uia_compiler.dir\uia_compiler.cpp.s

# Object files for target uia_compiler
uia_compiler_OBJECTS = \
"CMakeFiles/uia_compiler.dir/uia_main.cpp.obj" \
"CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.obj" \
"CMakeFiles/uia_compiler.dir/uia_compiler.cpp.obj"

# External object files for target uia_compiler
uia_compiler_EXTERNAL_OBJECTS =

uia_compiler.exe: CMakeFiles/uia_compiler.dir/uia_main.cpp.obj
uia_compiler.exe: CMakeFiles/uia_compiler.dir/uia_preprocessor.cpp.obj
uia_compiler.exe: CMakeFiles/uia_compiler.dir/uia_compiler.cpp.obj
uia_compiler.exe: CMakeFiles/uia_compiler.dir/build.make
uia_compiler.exe: CMakeFiles/uia_compiler.dir/linkLibs.rsp
uia_compiler.exe: CMakeFiles/uia_compiler.dir/objects1.rsp
uia_compiler.exe: CMakeFiles/uia_compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\Lap trinh\UIA\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable uia_compiler.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\uia_compiler.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uia_compiler.dir/build: uia_compiler.exe
.PHONY : CMakeFiles/uia_compiler.dir/build

CMakeFiles/uia_compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\uia_compiler.dir\cmake_clean.cmake
.PHONY : CMakeFiles/uia_compiler.dir/clean

CMakeFiles/uia_compiler.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Lap trinh\UIA\UiaCompiler" "D:\Lap trinh\UIA\UiaCompiler" "D:\Lap trinh\UIA\build" "D:\Lap trinh\UIA\build" "D:\Lap trinh\UIA\build\CMakeFiles\uia_compiler.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/uia_compiler.dir/depend

