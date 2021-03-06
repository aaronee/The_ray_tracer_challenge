# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/khoahuynh/Documents/Document/STM32F103CB-BluePill/RaceTracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/khoahuynh/Documents/Document/STM32F103CB-BluePill/RaceTracer

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/khoahuynh/Documents/Document/STM32F103CB-BluePill/RaceTracer/CMakeFiles /Users/khoahuynh/Documents/Document/STM32F103CB-BluePill/RaceTracer/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/khoahuynh/Documents/Document/STM32F103CB-BluePill/RaceTracer/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named RaceTracer

# Build rule for target.
RaceTracer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 RaceTracer
.PHONY : RaceTracer

# fast build rule for target.
RaceTracer/fast:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/build
.PHONY : RaceTracer/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) -f lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make lib/googletest/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) -f lib/googletest/googlemock/CMakeFiles/gmock_main.dir/build.make lib/googletest/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) -f lib/googletest/googletest/CMakeFiles/gtest_main.dir/build.make lib/googletest/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) -f lib/googletest/googletest/CMakeFiles/gtest.dir/build.make lib/googletest/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

Canvas/Canvas.o: Canvas/Canvas.cpp.o

.PHONY : Canvas/Canvas.o

# target to build an object file
Canvas/Canvas.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Canvas/Canvas.cpp.o
.PHONY : Canvas/Canvas.cpp.o

Canvas/Canvas.i: Canvas/Canvas.cpp.i

.PHONY : Canvas/Canvas.i

# target to preprocess a source file
Canvas/Canvas.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Canvas/Canvas.cpp.i
.PHONY : Canvas/Canvas.cpp.i

Canvas/Canvas.s: Canvas/Canvas.cpp.s

.PHONY : Canvas/Canvas.s

# target to generate assembly for a file
Canvas/Canvas.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Canvas/Canvas.cpp.s
.PHONY : Canvas/Canvas.cpp.s

Color/Color.o: Color/Color.cpp.o

.PHONY : Color/Color.o

# target to build an object file
Color/Color.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Color/Color.cpp.o
.PHONY : Color/Color.cpp.o

Color/Color.i: Color/Color.cpp.i

.PHONY : Color/Color.i

# target to preprocess a source file
Color/Color.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Color/Color.cpp.i
.PHONY : Color/Color.cpp.i

Color/Color.s: Color/Color.cpp.s

.PHONY : Color/Color.s

# target to generate assembly for a file
Color/Color.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Color/Color.cpp.s
.PHONY : Color/Color.cpp.s

Intersection/Intersection.o: Intersection/Intersection.cpp.o

.PHONY : Intersection/Intersection.o

# target to build an object file
Intersection/Intersection.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Intersection/Intersection.cpp.o
.PHONY : Intersection/Intersection.cpp.o

Intersection/Intersection.i: Intersection/Intersection.cpp.i

.PHONY : Intersection/Intersection.i

# target to preprocess a source file
Intersection/Intersection.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Intersection/Intersection.cpp.i
.PHONY : Intersection/Intersection.cpp.i

Intersection/Intersection.s: Intersection/Intersection.cpp.s

.PHONY : Intersection/Intersection.s

# target to generate assembly for a file
Intersection/Intersection.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Intersection/Intersection.cpp.s
.PHONY : Intersection/Intersection.cpp.s

Light/Light.o: Light/Light.cpp.o

.PHONY : Light/Light.o

# target to build an object file
Light/Light.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Light/Light.cpp.o
.PHONY : Light/Light.cpp.o

Light/Light.i: Light/Light.cpp.i

.PHONY : Light/Light.i

# target to preprocess a source file
Light/Light.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Light/Light.cpp.i
.PHONY : Light/Light.cpp.i

Light/Light.s: Light/Light.cpp.s

.PHONY : Light/Light.s

# target to generate assembly for a file
Light/Light.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Light/Light.cpp.s
.PHONY : Light/Light.cpp.s

Material/Material.o: Material/Material.cpp.o

.PHONY : Material/Material.o

# target to build an object file
Material/Material.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Material/Material.cpp.o
.PHONY : Material/Material.cpp.o

Material/Material.i: Material/Material.cpp.i

.PHONY : Material/Material.i

# target to preprocess a source file
Material/Material.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Material/Material.cpp.i
.PHONY : Material/Material.cpp.i

Material/Material.s: Material/Material.cpp.s

.PHONY : Material/Material.s

# target to generate assembly for a file
Material/Material.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Material/Material.cpp.s
.PHONY : Material/Material.cpp.s

Matrix/Matrix.o: Matrix/Matrix.cpp.o

.PHONY : Matrix/Matrix.o

# target to build an object file
Matrix/Matrix.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Matrix/Matrix.cpp.o
.PHONY : Matrix/Matrix.cpp.o

Matrix/Matrix.i: Matrix/Matrix.cpp.i

.PHONY : Matrix/Matrix.i

# target to preprocess a source file
Matrix/Matrix.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Matrix/Matrix.cpp.i
.PHONY : Matrix/Matrix.cpp.i

Matrix/Matrix.s: Matrix/Matrix.cpp.s

.PHONY : Matrix/Matrix.s

# target to generate assembly for a file
Matrix/Matrix.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Matrix/Matrix.cpp.s
.PHONY : Matrix/Matrix.cpp.s

Matrix/MatrixTransform.o: Matrix/MatrixTransform.cpp.o

.PHONY : Matrix/MatrixTransform.o

# target to build an object file
Matrix/MatrixTransform.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Matrix/MatrixTransform.cpp.o
.PHONY : Matrix/MatrixTransform.cpp.o

Matrix/MatrixTransform.i: Matrix/MatrixTransform.cpp.i

.PHONY : Matrix/MatrixTransform.i

# target to preprocess a source file
Matrix/MatrixTransform.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Matrix/MatrixTransform.cpp.i
.PHONY : Matrix/MatrixTransform.cpp.i

Matrix/MatrixTransform.s: Matrix/MatrixTransform.cpp.s

.PHONY : Matrix/MatrixTransform.s

# target to generate assembly for a file
Matrix/MatrixTransform.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Matrix/MatrixTransform.cpp.s
.PHONY : Matrix/MatrixTransform.cpp.s

Point/Point.o: Point/Point.cpp.o

.PHONY : Point/Point.o

# target to build an object file
Point/Point.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Point/Point.cpp.o
.PHONY : Point/Point.cpp.o

Point/Point.i: Point/Point.cpp.i

.PHONY : Point/Point.i

# target to preprocess a source file
Point/Point.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Point/Point.cpp.i
.PHONY : Point/Point.cpp.i

Point/Point.s: Point/Point.cpp.s

.PHONY : Point/Point.s

# target to generate assembly for a file
Point/Point.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Point/Point.cpp.s
.PHONY : Point/Point.cpp.s

Ray/Ray.o: Ray/Ray.cpp.o

.PHONY : Ray/Ray.o

# target to build an object file
Ray/Ray.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Ray/Ray.cpp.o
.PHONY : Ray/Ray.cpp.o

Ray/Ray.i: Ray/Ray.cpp.i

.PHONY : Ray/Ray.i

# target to preprocess a source file
Ray/Ray.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Ray/Ray.cpp.i
.PHONY : Ray/Ray.cpp.i

Ray/Ray.s: Ray/Ray.cpp.s

.PHONY : Ray/Ray.s

# target to generate assembly for a file
Ray/Ray.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Ray/Ray.cpp.s
.PHONY : Ray/Ray.cpp.s

Sphere/Sphere.o: Sphere/Sphere.cpp.o

.PHONY : Sphere/Sphere.o

# target to build an object file
Sphere/Sphere.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Sphere/Sphere.cpp.o
.PHONY : Sphere/Sphere.cpp.o

Sphere/Sphere.i: Sphere/Sphere.cpp.i

.PHONY : Sphere/Sphere.i

# target to preprocess a source file
Sphere/Sphere.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Sphere/Sphere.cpp.i
.PHONY : Sphere/Sphere.cpp.i

Sphere/Sphere.s: Sphere/Sphere.cpp.s

.PHONY : Sphere/Sphere.s

# target to generate assembly for a file
Sphere/Sphere.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Sphere/Sphere.cpp.s
.PHONY : Sphere/Sphere.cpp.s

Test/Test.o: Test/Test.cpp.o

.PHONY : Test/Test.o

# target to build an object file
Test/Test.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Test/Test.cpp.o
.PHONY : Test/Test.cpp.o

Test/Test.i: Test/Test.cpp.i

.PHONY : Test/Test.i

# target to preprocess a source file
Test/Test.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Test/Test.cpp.i
.PHONY : Test/Test.cpp.i

Test/Test.s: Test/Test.cpp.s

.PHONY : Test/Test.s

# target to generate assembly for a file
Test/Test.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Test/Test.cpp.s
.PHONY : Test/Test.cpp.s

Test/Test2.o: Test/Test2.cpp.o

.PHONY : Test/Test2.o

# target to build an object file
Test/Test2.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Test/Test2.cpp.o
.PHONY : Test/Test2.cpp.o

Test/Test2.i: Test/Test2.cpp.i

.PHONY : Test/Test2.i

# target to preprocess a source file
Test/Test2.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Test/Test2.cpp.i
.PHONY : Test/Test2.cpp.i

Test/Test2.s: Test/Test2.cpp.s

.PHONY : Test/Test2.s

# target to generate assembly for a file
Test/Test2.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Test/Test2.cpp.s
.PHONY : Test/Test2.cpp.s

Tuple/Tuple.o: Tuple/Tuple.cpp.o

.PHONY : Tuple/Tuple.o

# target to build an object file
Tuple/Tuple.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Tuple/Tuple.cpp.o
.PHONY : Tuple/Tuple.cpp.o

Tuple/Tuple.i: Tuple/Tuple.cpp.i

.PHONY : Tuple/Tuple.i

# target to preprocess a source file
Tuple/Tuple.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Tuple/Tuple.cpp.i
.PHONY : Tuple/Tuple.cpp.i

Tuple/Tuple.s: Tuple/Tuple.cpp.s

.PHONY : Tuple/Tuple.s

# target to generate assembly for a file
Tuple/Tuple.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Tuple/Tuple.cpp.s
.PHONY : Tuple/Tuple.cpp.s

Vector/Vector.o: Vector/Vector.cpp.o

.PHONY : Vector/Vector.o

# target to build an object file
Vector/Vector.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Vector/Vector.cpp.o
.PHONY : Vector/Vector.cpp.o

Vector/Vector.i: Vector/Vector.cpp.i

.PHONY : Vector/Vector.i

# target to preprocess a source file
Vector/Vector.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Vector/Vector.cpp.i
.PHONY : Vector/Vector.cpp.i

Vector/Vector.s: Vector/Vector.cpp.s

.PHONY : Vector/Vector.s

# target to generate assembly for a file
Vector/Vector.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/Vector/Vector.cpp.s
.PHONY : Vector/Vector.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/RaceTracer.dir/build.make CMakeFiles/RaceTracer.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/local"
	@echo "... rebuild_cache"
	@echo "... RaceTracer"
	@echo "... edit_cache"
	@echo "... install/strip"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... gmock"
	@echo "... gmock_main"
	@echo "... gtest_main"
	@echo "... gtest"
	@echo "... Canvas/Canvas.o"
	@echo "... Canvas/Canvas.i"
	@echo "... Canvas/Canvas.s"
	@echo "... Color/Color.o"
	@echo "... Color/Color.i"
	@echo "... Color/Color.s"
	@echo "... Intersection/Intersection.o"
	@echo "... Intersection/Intersection.i"
	@echo "... Intersection/Intersection.s"
	@echo "... Light/Light.o"
	@echo "... Light/Light.i"
	@echo "... Light/Light.s"
	@echo "... Material/Material.o"
	@echo "... Material/Material.i"
	@echo "... Material/Material.s"
	@echo "... Matrix/Matrix.o"
	@echo "... Matrix/Matrix.i"
	@echo "... Matrix/Matrix.s"
	@echo "... Matrix/MatrixTransform.o"
	@echo "... Matrix/MatrixTransform.i"
	@echo "... Matrix/MatrixTransform.s"
	@echo "... Point/Point.o"
	@echo "... Point/Point.i"
	@echo "... Point/Point.s"
	@echo "... Ray/Ray.o"
	@echo "... Ray/Ray.i"
	@echo "... Ray/Ray.s"
	@echo "... Sphere/Sphere.o"
	@echo "... Sphere/Sphere.i"
	@echo "... Sphere/Sphere.s"
	@echo "... Test/Test.o"
	@echo "... Test/Test.i"
	@echo "... Test/Test.s"
	@echo "... Test/Test2.o"
	@echo "... Test/Test2.i"
	@echo "... Test/Test2.s"
	@echo "... Tuple/Tuple.o"
	@echo "... Tuple/Tuple.i"
	@echo "... Tuple/Tuple.s"
	@echo "... Vector/Vector.o"
	@echo "... Vector/Vector.i"
	@echo "... Vector/Vector.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

