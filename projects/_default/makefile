##########################
# Leka project makefile
#
# Author : mickael@leka
#
# This makefile must be in the folder : $(WORKSPACE_LOC)/projects/$(PROJECT_NAME)

# Load common variables such as $(WORKSPACE_LOC)
include ../config.mk

# The project name
PROJECT_NAME:=_default
# Type of the project, must be either :
#  - ex for an executable
#  - sl for a static library
#  - dl  for a dynamic library
PROJECT_TYPE:=ex

# The sources directory, default : $(WORKSPACE_LOC)/src/$(PROJECT_NAME)
SRC_DIR=$(WORKSPACE_LOC)/src/$(PROJECT_NAME)
# The sources to compile 
SRC:=$(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.cpp))
# The dir of objs files, default : $(WORKSPACE_LOC)/tmp/$(PROJECT_NAME)/$(CONFIGURATION)
OBJ_DIR=$(WORKSPACE_LOC)/tmp/$(PROJECT_NAME)/$(CONFIGURATION)
# The objs files
OBJ:=$(foreach source, $(SRC), $(subst $(SRC_DIR), $(OBJ_DIR), $(source:.cpp=.o)))

# Additional headers
HEADERS:=

# Used libraries, ex : `pkg-config --libs --cflags libusb-1.0`
LIBS:=

# The compiler of the project, default g++ for c++ project 
CC:=g++
# Compiler options in debug mode
ifeq ($(CONFIGURATION), debug)
	# Compiler flags
	C_FLAGS=-W -Wall -Wextra -g $(HEADERS)
	# Linker flags
	L_FLAGS=$(LIBS)
	# Configuration name
	CONFIGURATION=debug
	ERROR=
#Compiler options in release mode
else ifeq ($(CONFIGURATION), release)
	# Compiler flags
	C_FLAGS=-W -Wall -Wextra
	# Linker flags
	L_FLAGS=$(LIBS)
	#Configuration name
	CONFIGURATION=release
	ERROR=
else
	ERROR=$(error CONFIGURATION must either be "debug" or "release")
endif


.PHONY: all clean

# all recipe, start point of the makefile
all: $(ERROR) $(PROJECT_NAME)
	@echo "Generation of $(PROJECT_NAME) in $(CONFIGURATION) mode"

# Compile each .ccp into a .o
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) -o $@ -c $< $(C_FLAGS)

# Linking of the project, depends on the compilation of source files 
$(PROJECT_NAME): $(OBJ)
ifeq ($(PROJECT_TYPE), ex)
	@mkdir -p $(WORKSPACE_LOC)/bin/$(PROJECT_NAME)/$(CONFIGURATION)/
	@$(CC) -o $(WORKSPACE_LOC)/bin/$(PROJECT_NAME)/$(CONFIGURATION)/$@ $^ $(L_FLAGS)
else ifeq ($(PROJECT_TYPE), sl)
	@rm -f $(LIB_LOC)/$(CONFIGURATION)/$(PROJECT_NAME).a
	@ar crs $(LIB_LOC)/$(CONFIGURATION)/$(PROJECT_NAME).a $^
else ifeq ($(PROJECT_TYPE), dl)
	@rm -f $(LIB_LOC)/$(CONFIGURATION)/$(PROJECT_NAME).so
	@$(CC) -shared -o $(LIB_LOC)/$(CONFIGURATION)/$(PROJECT_NAME).so $^ $(L_FLAGS)
else
	$(error PROJECT_TYPE must either be "ex", "sl" or "dl")
endif

# Clean the project 
clean:
	@rm -f $(WORKSPACE_LOC)/bin/$(PROJECT_NAME)/$(CONFIGURATION)/$(PROJECT_NAME)
	@rm -f $(LIB_LOC)/$(CONFIGURATION)/$(PROJECT_NAME).a
	@rm -f $(LIB_LOC)/$(CONFIGURATION)/$(PROJECT_NAME).so
	@rm -rf $(WORKSPACE_LOC)/tmp/$(PROJECT_NAME)/$(CONFIGURATION)
	