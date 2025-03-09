# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
OUTPUT=ps2

# targets
all: $(OUTPUT) clean

$(OUTPUT): hof.o k.o ui.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	gcc $(CFLAGS) hof.o k.o ui.o main.o $(LIDLIBS) -o $(OUTPUT)

main.o: main.c
	gcc $(CFLAGS) -c main.c $(LIDLIBS) -o main.o

hof.o: hof.c hof.h
	gcc $(CFLAGS) -c hof.c $(LIDLIBS) -o hof.o

k.o: k.c k.h
	gcc $(CFLAGS) -c k.c $(LIDLIBS) -o k.o
ui.o: ui.c ui.h
	gcc $(CFLAGS) -c ui.c $(LIDLIBS) -o ui.o
# remove compiled files
clean:
	rm -f *.o $(OUTPUT)
