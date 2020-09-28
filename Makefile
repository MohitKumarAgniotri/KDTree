#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gcc
CFLAGS  = -g3 -Wall -Werror -Wpedantic -O0 
LFLAGS  = -lm

default : dict

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
dict:  data.o  linkedlist.o  main.o
	$(CC) $(CFLAGS) -o map1 data.o  linkedlist.o  main.o $(LFLAGS)

# To create the object file counter.o, we need the source files
# counter.c and counter.h:
#
data.o:  data.c data.h  linkedlist.h
	$(CC) $(CFLAGS) -c data.c

# To create the object file scanner.o, we need the source files
# scanner.c and scanner.h:
#
linkedlist.o:  linkedlist.c data.h  linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

# To create the object file scanner.o, we need the source files
# scanner.c and scanner.h:
#
main.o:  main.c data.h  linkedlist.h
	$(CC) $(CFLAGS) -c main.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) map1 map2 *.o *~
