CC = g++

SRC = $(wildcard src/%.cpp)
SRC_OLD = src/*.cpp

OBJ = main.o

CFLAGS = -Wall -std=c++17

LFLAGS = -lSDL2

.PHONY : all old clean vClean

all : clean old run

# Doesn't actually work yet, use old until fixed
%.o : src/%.cpp src/%.h
	# Compiling Program...
	$(CC) $< $(LFLAGS) $(CFLAGS) -o $@
	# Done.

old :
	$(CC) $(SRC_OLD) $(LFLAGS) $(CFLAGS) -o $(OBJ)

run :
	# Running Program...
	./$(OBJ)
	# Done.

vClean :
	# Cleaning Up...
	rm -rf *.swp
	rm -rf src/.swp
	# Done.

clean :
	# Cleaning Up...
	rm -rf *.o
	# Done.

