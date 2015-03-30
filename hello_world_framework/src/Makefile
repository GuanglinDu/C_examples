# Makefile for C examples in Introduction-to-C-using-lcc-with-index-V20120415.pdf by Jacob Navia.
# Note: This Makefile is being maintained in Geany and the folder structures
# conform to Code::Blocks conventions (cbp = Code::Blocks Project).
# This is a smart and  generic one, working as a template.
#
# References: 
# (1) A Simple Makefile Tutorial(http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
# (2) GNU `make': http://www.gnu.org/software/make/manual/make.html
#
# Authour: Guanglin Du (dglqxq@163.com)
# Date: 2013/02/11 Mon.
# Upated: 2013/09/01 08:58:52 -- Added some prompts to the tasks.

# !!!Note: On Windows, you'd better use mingw32-make.exe which can be downloaded from http://mingw.org/
# or is bundled with Code::Blocks(http://www.codeblocks.org) or Dev-C++(http://sourceforge.net/projects/dev-cpp/).

# !!!!Attentions: OS ID(Either Windows or Linux at present, automatically detect)
# OS = Linux
# OS = Windows
# Note: $(shell uname) returns null on Windows, Linux on GNU/Linux
OS := $(shell uname)
ifneq ($(OS), Linux)
	OS = Windows
endif

# Using variables to switch the Current Compiler (CC)
CC = gcc
#CC = g++

# Base dir, include(I) dir, lib(L) dir and compiling(C) flags
BASE_DIR = ..
SRC_DIR = .
IDIR = .
IFLAGS = -I$(IDIR) 
LDIR = .
CFLAGS = -Wall -g
# Puts shared libraries in folder $(BIN_DIR)
LD_LIBRARY_PATH=$(BIN_DIR)
	
# Object and bin file dirs(compatible with Code::Blocks)
# Linux/Unix
ifeq ($(OS), Linux)
	OBJ_DIR = $(BASE_DIR)/obj/Debug
	BIN_DIR = $(BASE_DIR)/bin/Debug
	API_DOC_DIR = $(BASE_DIR)/doc/api-doc
# Windows only
else
	OBJ_DIR = $(BASE_DIR)\obj\Debug
	BIN_DIR = $(BASE_DIR)\bin\Debug
	API_DOC_DIR = $(BASE_DIR)\doc\api-doc
endif

# Source file names(implementation & main, naming convention over new rules) .
# \ (backslash), for continuation lines. Specify all *.h & *.o here. No *.c files needed.
# DEPS: Dependecies
DEPS = hello_world_framework.h \
	pointer_examples.h
# Variable for all the objects	
_OBJ = hello_world_framework_main.o \
	hello_world_framework.o \
	pointer_examples.o
	
# Modified variable references using pattern substitution provided in GNU make by the patsubst function
# Linux/Unix/Windows
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(_OBJ))
	
# Conventionally, the executable on Linux/Unix is a.out. Modify this as you like.
# Linux/Unix/Windows
BIN = $(BIN_DIR)/a.out
# Use the exe extension on Windows if you like
#BIN = $(BIN_DIR)\a.exe

.PHONY: all mkdir compile build rebuild run

# Attentions: The 1st target is the default one
all: run

# !!!A rule that applies to all files ending in the .o suffix. IMPORTANT!!!
# The rule says that the .o file depends upon the .c version of the file and the .h files included in the DEPS macro. The rule then says that to generate the .o file, make needs to compile the .c file using the compiler defined in the CC macro. The -c flag says to generate the object file, the -o $@ says to put the output of the compilation in the file named on the left side of the :, the $< is the first item in the dependencies list, and the CFLAGS macro is defined as above.	
# Note: | order-only-prerequisites
# Linux/Unix/Windows
$(OBJ_DIR)/%.o: %.c $(DEPS) | mkdir
	@echo "--- Compiling *.c to *.o files ..."
	$(CC) -o $@ -c $(CFLAGS) $< $(IFLAGS)

# As a final simplification, let's use the special macros $@ and $^, which are the left and right sides of the :, respectively, to make the overall compilation rule more general. In the example below, all of the include files should be listed as part of the macro DEPS, and all of the object files should be listed as part of the macro OBJ.
$(BIN): $(OBJ)
	@echo "--- Linking *.o files to an executable ..."
	$(CC) -o $@ $^ $(IFLAGS)

## We now only support Linux and Windows. Note: if...fi block is shell scripting.
mkdir:
	@echo "--- Checking whether the dirs exist. Otherwise, create them ..."
#Linux/Unix only
ifeq ($(OS), Linux)
#	mkdir -p $(OBJ_DIR)
#	mkdir -p $(BIN_DIR)
#	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
#	test -d $(BIN_DIR) || mkdir -p $(BIN_DIR)
	@if test -d $(OBJ_DIR); then echo "$(OBJ_DIR) exists! OK!"; else mkdir -p $(OBJ_DIR); fi
	@if test -d $(BIN_DIR); then echo "$(BIN_DIR) exists! OK!"; else mkdir -p $(BIN_DIR); fi
	@if test -d $(API_DOC_DIR); then echo "$(API_DOC_DIR) exists! OK!"; else mkdir -p $(API_DOC_DIR); fi
# Windows only
else
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	@if not exist $(API_DOC_DIR) mkdir $(API_DOC_DIR)
endif

# Compile only
compile: $(OBJ)

build: $(BIN)

rebuild: clean build

run: build
	@echo "--- Runing the executable ..."
	$(BIN)

# Targets that do not refer to files but are just actions are called phony targets.
.PHONY: static_lib test_static_lib shared_lib test_shared_lib \
	clean api-doc clean-api-doc detect-os

# Create a static library libpointer_examples.a based on pointer_examples.c
# See http://www.adp-gmbh.ch/cpp/gcc/create_lib.html
static_lib: compile
	ar rcs $(BIN_DIR)/libpointer_examples.a $(OBJ_DIR)/pointer_examples.o
	
# Links against the static library
test_static_lib: static_lib
	$(CC) -static link_lib_main.c -L. -L$(BIN_DIR) -lpointer_examples -o $(BIN_DIR)/statically_linked
	$(BIN_DIR)/statically_linked

# See also http://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
shared_lib:
	$(CC) -c -fPIC $(SRC_DIR)/pointer_examples.c -o $(OBJ_DIR)/pointer_examples.o 
	$(CC) -shared -Wl,-soname,$(BIN_DIR)/libpointer_examples.so.1 \
		-o $(BIN_DIR)/libpointer_examples.so.1.0.1  $(OBJ_DIR)/pointer_examples.o

# Links against the shared library
test_shared_lib: shared_lib
	$(CC) link_lib_main.c -L. -L$(BIN_DIR) -lpointer_examples -o $(BIN_DIR)/dynamically_linked
	$(BIN_DIR)/dynamically_linked
	
clean:
	@echo "--- Cleaning all *.o/*.exe files ..."
# Linux/Unix
ifeq ($(OS), Linux)
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*.exe $(BIN_DIR)/*.out $(SRC_DIR)/*.o $(BIN_DIR)/*.a $(BIN_DIR)/*.so.1
# Windows
else
	del $(OBJ_DIR)\*.o $(BIN_DIR)\*.exe $(BIN_DIR)\*.out $(SRC_DIR)\*.o $(BIN_DIR)/*.a $(BIN_DIR)/*.so.1
endif
	
# Generates the API doc
# http://www.stack.nl/~dimitri/doxygen/index.html
# http://www.ibm.com/developerworks/aix/library/au-learningdoxygen/
# http://www.cs.cmu.edu/~410/doc/doxygen.html
api-doc: mkdir
	@echo "--- Generating API doc with doxygen ..."
	doxygen Doxyfile

clean-api-doc:
	@echo "--- Cleaning all API doc files ..."
# Linux/Unix
ifeq ($(OS), Linux)
	rm -f $(API_DOC_DIR)/html/*.* $(API_DOC_DIR)/html/search/*.* $(API_DOC_DIR)/latex/*.* $(API_DOC_DIR)/latex/Makefile
# Windows
else
	del /Q $(API_DOC_DIR)\html\*.* $(API_DOC_DIR)\html\search\*.* $(API_DOC_DIR)\latex\*.* $(API_DOC_DIR)\latex\Makefile
endif

# @ avoids the command to echo in the console.
detect-os:
	@echo Your OS is ${OS}
