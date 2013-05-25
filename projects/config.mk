###########################################
# Leka project makefile configuration file
#
# Author : mickael@leka
#
# This makefile must be in the folder : $(WORKSPACE_LOC)/projects
#
# It defines some common variables for project's makefile

# Define the workspace location
WORKSPACE_LOC:=/data/cpp/balle

#Define the libraries location
LIB_LOC:=$(WORKSPACE_LOC)/lib

# Define default configuration
CONFIGURATION:=debug

# Define default compiler
CC:=g++
