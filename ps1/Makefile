# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
OUTPUT=ps1

# targets
all: $(OUTPUT) clean

$(OUTPUT): playfair.o bmp.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	gcc $(CFLAGS) playfair.o bmp.o main.o $(LIDLIBS) -o $(OUTPUT)

main.o: main.c
	gcc $(CFLAGS) -c main.c $(LIDLIBS) -o main.o

playfair.o: playfair.c playfair.h
	gcc $(CFLAGS) -c playfair.c $(LIDLIBS) -o playfair.o

bmp.o: bmp.c bmp.h
	gcc $(CFLAGS) -c bmp.c $(LIDLIBS) -o bmp.o

# remove compiled files
#clean:
#	rm -f *.o $(OUTPUT)
