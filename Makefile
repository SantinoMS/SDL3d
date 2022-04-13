CC = g++

# SRC = $(wildcard src/%.cpp)
#SRC_OLD = src/*.cpp
E_SRC = src/Engine3d.cpp
I_SRC = $(shell find src -name "*.cpp")
SRC = $(filter-out $(E_SRC), $(I_SRC))
OBJ = $(SRC:.cpp=.o)
BIN = bin

CFLAGS = -Wall -std=c++17 
FFLAGS = -fdiagnostics-color -fno-stack-protector
LFLAGS = -lSDL2

FLAGS = $(CFLAGS)
FLAGS += $(FFLAGS)
FLAGS += $(LFLAGS)

.PHONY : all clean 

all : dirs build

dirs :
	mkdir -p ./$(BIN)

run : build
	@ echo Running Program...
	$(BIN)/game
	@ echo Done.

build : dirs $(OBJ)
	@ echo Compiling Program...
	$(CC) -o $(BIN)/game $(filter %.o,$^) $(FLAGS)
	@ echo Done.

%.o : %.cpp %.h
	@ echo Updating Binaries...
	$(CC) -o $@ -c $< $(FLAGS)
	@ echo Done.

#old :
#	$(CC) $(SRC_OLD) $(FLAGS) -o $(OBJ)

clean :
	@ echo Cleaning Up...
	rm -rf *.o
	rm -rf $(BIN) $(OBJ)
	@ echo Done.

# credits: https://github.com/jdah/minecraft-again/blob/master/Makefile

