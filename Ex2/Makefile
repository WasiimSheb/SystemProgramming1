CC = gcc
CFLAGS = -Wall
SRC = my_graph.c
OBJ = my_graph.o my_mat.o
TARGET = mains
HEADER = my_mat.h

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

my_graph.o: my_graph.c $(HEADER)
	$(CC) $(CFLAGS) -c -o my_graph.o my_graph.c

my_mat.o: my_mat.c $(HEADER)
	$(CC) $(CFLAGS) -c -o my_mat.o my_mat.c

.PHONY: all clean

clean: 
	rm -f $(OBJ) $(TARGET)
