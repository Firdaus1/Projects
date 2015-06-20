# Project: Project1
# Makefile created by Dev-C++ 5.9.2
#Modified by Firdaus Botirzoda

CPP      = g++
 
OBJ      = equation_test.o
LINKOBJ  = equation_test.o
 
BIN      = equation_test
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before equation_test all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

equation_test.o: equation_test.cpp
	$(CPP) -c equation_test.cpp -o equation_test.o $(CXXFLAGS)
