# Project: Project1
# Makefile created by Dev-C++ 5.9.2
# Modified by Firdaus Botirzoda

CPP      = g++
OBJ      = flood_fill.o
LINKOBJ  = flood_fill.o

BIN      = Flood_fill
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before Flood_fill all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

driver.o: driver.cpp
	$(CPP) -c flood_fill.cpp -o driver.o $(CXXFLAGS)
