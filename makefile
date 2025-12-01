
# Makefile for compiling and running single C++ files on Windows
# Set C++ compiler
CXX = g++

# Define compilation flags. 
# C++ standard, -Wall and -Wextra show all useful warnings.
CXXFLAGS = -std=c++17 -Wall -Wextra

# Define the directory where executables will be stored
BUILD_DIR = build

# Define the shell command to remove a directory recursively
RM_DIR = rd /s /q

# Phony targets are special targets that don't represent actual files.
# This prevents 'make' from getting confused if a file named 'clean' exists.
.PHONY: clean

# -----------------------------------------------------------------------------
# To compile and run "my_program.cpp", you would just type:
# make my_program
# -----------------------------------------------------------------------------
% : %.cpp
	@echo.
	@echo [33m[COMPILING]: [0m$<
	
	@REM Create the build directory if it doesn't already exist
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	
	@REM Compile the source file ($<) and create the executable ($@.exe)
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/$@.exe
	
	@echo [32m[RUNNING]: [0m$(BUILD_DIR)\$@.exe
	@echo [32m------------------------------------[0m
	
	@REM Run the newly created executable
	@$(BUILD_DIR)\$@.exe
	
	@echo [32m------------------------------------[0m
	@echo [32m[DONE][0m


# -----------------------------------------------------------------------------
# The 'clean' rule removes the entire build directory and all its contents.
# Usage: make clean
# -----------------------------------------------------------------------------
clean:
	@echo [CLEANING]: Removing build directory...
	@if exist "$(BUILD_DIR)" $(RM_DIR) "$(BUILD_DIR)"
	@echo [CLEANING]: Done.

