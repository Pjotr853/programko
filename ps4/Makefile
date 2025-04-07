# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
OUTPUT=bmp

# targets
all: $(OUTPUT) clean

$(OUTPUT): transformations.o bmp.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	gcc $(CFLAGS) transformations.o bmp.o main.o $(LIDLIBS) -o $(OUTPUT)

main.o: main.c
	gcc $(CFLAGS) -c main.c $(LIDLIBS) -o main.o

transformations.o: transformations.c transformations.h 
	gcc $(CFLAGS) -c transformations.c $(LIDLIBS) -o transformations.o

bmp.o: bmp.c bmp.h
	gcc $(CFLAGS) -c bmp.c $(LIDLIBS) -o bmp.o

# remove compiled files
clean:
	rm -rf $(OUTPUT) *.o 
