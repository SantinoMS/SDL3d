CC = g++

# SRC = $(wildcard src/%.cpp)
SRC = $(shell find src -name "*.cpp")
SRC_OLD = src/*.cpp
OBJ = $(SRC:.cpp=.o)
BIN = bin

CFLAGS = -Wall -std=c++17 
FFLAGS = -fdiagnostics-color -fno-stack-protector
LFLAGS = -lSDL2

FLAGS = $(CFLAGS)
FLAGS += $(FFLAGS)
FLAGS += $(LFLAGS)

.PHONY : all old clean 

all : dirs build

dirs :
	mkdir -p ./$(BIN)

run : build
	# Running Program...
	$(BIN)/game
	# Done.

build : dirs $(OBJ)
	$(CC) -o $(BIN)/game $(filter %.o,$^) $(FLAGS)

%.o : %.cpp
	# Compiling Program...
	$(CC) -o $@ -c $< $(FLAGS)
	# Done.

old :
	$(CC) $(SRC_OLD) $(FLAGS) -o $(OBJ)

clean :
	# Cleaning Up...
	rm -rf *.o
	rm -rf $(BIN) $(OBJ)
	# Done.

# credits: https://github.com/jdah/minecraft-again/blob/master/Makefile

