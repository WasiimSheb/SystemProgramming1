CC = gcc
Cflags = -Wall
all: StrList

StrList: StrList.o main.o
    gcc -Wall main.o StrList.o -o StrList

StrList.o: StrList.c StrList.h
    $(CC) $(Cflags) -c StrList.c

main.o: main.c
    $(CC) $(Cflags) -c main.c

.Phony: clean all

clean: rm -f main.o StrList.o
