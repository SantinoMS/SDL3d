CC = g++

SRC = src/*.cpp

OBJ = main.o

CFLAGS = -Wall -std=c++17# None for now

LFLAGS = -lSDL2

all :
	# Compiling Program...
	$(CC) $(SRC) $(LFLAGS) $(CFLAGS) -o $(OBJ)
	# Done.

run :
	# Running Program...
	./$(OBJ)
	# Done.

clean :
	# Cleaning Up...
	rm -rf *.o
	# Done.
