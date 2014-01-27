##
# Author : Ben Blazak
# Date   : 2014-01-26
#
# This is a makefile.  It controls the behavior of a program called "make",
# which you can read about here: http://en.wikipedia.org/wiki/Make_(software).
#
# I've implemented the same functionality that is provided by this makefile in
# the shell scripts (the files ending in ".sh") in this directory.  The shell
# scripts will be much easier to understand for now, but I wanted to show
# everyone a makefile as well, since that is by far the more common way to do
# things (as well as being easier, once you learn how it works).  If you'd like
# to learn more about Make and makefiles, please see the documentation:
# http://www.gnu.org/software/make/manual/make.html.
#

TARGET := test.exe                      # the file we ultimately wish to create

SRC := $(TARGET:%.exe=%.cpp)            # all source (i.e. ".cpp") files

PRE := $(SRC:%.cpp=%.preprocessed.cpp)  # all preprocessed C++ files
ASM := $(SRC:%.cpp=%.s)                 # all assembly files
OBJ := $(SRC:%.cpp=%.o)                 # all object files

# Remove whitespace from the above variables
# - This whitespace wouldn't be there if we had commented a little differently.
#   But then, no other style of commenting looked quite as nice, in my opinion.
#   It's a judgement call.
TARGET := $(strip $(TARGET))
SRC    := $(strip $(SRC))
PRE    := $(strip $(PRE))
ASM    := $(strip $(ASM))
OBJ    := $(strip $(OBJ))

# -----------------------------------------------------------------------------

.PHONY: all clean run

# Generate all the files we know how to create
all: $(PRE) $(ASM) $(OBJ) $(TARGET)

# Remove all generated files
clean:
	-rm $(PRE) $(ASM) $(OBJ) $(TARGET)

# Run the generated executable (test.exe) and print out some useful information
run: all
	-@echo "--- running $(TARGET) ------------------------------------"; \
	  ./$(TARGET); \
	  echo "----------------------------------------------------------\n" \
	       "The return value of $(TARGET) was: $$?\n" \
	       "The shell command used to run the program was: ./$(TARGET)"; \
	  echo "----------------------------------------------------------"

# -----------------------------------------------------------------------------

# how to build preprocessed C++ files from C++ files
%.preprocessed.cpp: %.cpp
	clang++ -E $< -o $@

# how to build assembly files from C++ files
%.s: %.cpp
	clang++ -S $< -o $@

# how to build object (i.e. binary) files from C++ files
%.o: %.cpp
	clang++ -c $< -o $@

# how to build an executable from a C++ file (provided the whole program is
# written in a single file)
%.exe: %.cpp
	clang++ $< -o $@

