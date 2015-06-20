# Project: Project1
# Makefile created by Dev-C++ 5.9.2

CPP      = g++
CC       = gcc
WINDRES  = windres
OBJ      = treeSearch.cpp.o
LINKOBJ  = treeSearch.cpp.o
BIN      = treeSearch
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm. -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

treeSearch.cpp.o: treeSearch.cpp.cpp
	$(CPP) -c treeSearch.cpp.cpp -o treeSearch.cpp.o $(CXXFLAGS)
