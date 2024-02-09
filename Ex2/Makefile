CC = gcc
CFLAGS = -Wall
SRC = my_graph.c
OBJ = my_graph.o my_mat.o
TARGET1 = connect
TARGET2 = connect2
HEADER = my_mat.h

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJ)

$(TARGET2): my_knapsack.o 
	$(CC) $(CFLAGS) -o $(TARGET2) my_knapsack.o

my_graph.o: my_graph.c $(HEADER)
	$(CC) $(CFLAGS) -c -o my_graph.o my_graph.c

my_mat.o: my_mat.c $(HEADER)
	$(CC) $(CFLAGS) -c -o my_mat.o my_mat.c

my_knapsack.o: my_knapsack.c
	$(CC) -c my_knapsack.c

.PHONY: all clean

clean: 
	rm -f $(OBJ) $(TARGET1) $(TARGET2) 
