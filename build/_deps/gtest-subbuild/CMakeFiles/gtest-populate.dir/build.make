# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild

# Utility rule file for gtest-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/gtest-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest-populate.dir/progress.make

CMakeFiles/gtest-populate: CMakeFiles/gtest-populate-complete

CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-install
CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-mkdir
CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-download
CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-update
CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-patch
CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-configure
CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-build
CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-install
CMakeFiles/gtest-populate-complete: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'gtest-populate'"
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E make_directory /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles/gtest-populate-complete
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-done

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-update:
.PHONY : gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-update

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-build: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'gtest-populate'"
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E echo_append
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-build

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-configure: gtest-populate-prefix/tmp/gtest-populate-cfgcmd.txt
gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-configure: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'gtest-populate'"
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E echo_append
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-configure

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-download: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-gitinfo.txt
gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-download: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'gtest-populate'"
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -P /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/tmp/gtest-populate-gitclone.cmake
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-download

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-install: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'gtest-populate'"
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E echo_append
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-install

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'gtest-populate'"
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -Dcfgdir= -P /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/tmp/gtest-populate-mkdirs.cmake
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-mkdir

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-patch: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'gtest-populate'"
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E echo_append
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-patch

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-update:
.PHONY : gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-update

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-test: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'gtest-populate'"
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E echo_append
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-build && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E touch /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-test

gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-update: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'gtest-populate'"
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-src && /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -P /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/gtest-populate-prefix/tmp/gtest-populate-gitupdate.cmake

gtest-populate: CMakeFiles/gtest-populate
gtest-populate: CMakeFiles/gtest-populate-complete
gtest-populate: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-build
gtest-populate: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-configure
gtest-populate: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-download
gtest-populate: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-install
gtest-populate: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-mkdir
gtest-populate: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-patch
gtest-populate: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-test
gtest-populate: gtest-populate-prefix/src/gtest-populate-stamp/gtest-populate-update
gtest-populate: CMakeFiles/gtest-populate.dir/build.make
.PHONY : gtest-populate

# Rule to build all files generated by this target.
CMakeFiles/gtest-populate.dir/build: gtest-populate
.PHONY : CMakeFiles/gtest-populate.dir/build

CMakeFiles/gtest-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest-populate.dir/clean

CMakeFiles/gtest-populate.dir/depend:
	cd /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild /Users/colintaylortaylor/Documents/splineForOptions/build/_deps/gtest-subbuild/CMakeFiles/gtest-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest-populate.dir/depend

