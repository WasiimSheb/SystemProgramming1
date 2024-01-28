CC = gcc
SRC = basicClassification.c advancedClassificationLoop.c advancedClassificationRecursion.c main.c 
OBJ1 = basicClassification.o
OBJ2 = advancedClassificationLoop.o
OBJ3 = advancedClassificationRecursion.o
TARGET1 = mains
TARGET2 = maindloop
TARGET3 = maindrec
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall
HEADER = NumClass.h
LIBRARY = libclassloops.a 
LIBRARY2 = libclassrec.a
DYNLIBRARY3 = libclassrec.so
DYNLIBRARY4 = libclassloops.so

all: $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1): $(LIBRARY2) $(HEADER) $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SRC) -L. -lclassrec

$(TARGET2):$(DYNLIBRARY4) $(HEADER) $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SRC) -L. -lclassloops

$(TARGET3):	$(DYNLIBRARY3) $(HEADER) $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET3) $(SRC) -L. -lclassrec

loops: $(LIBRARY)

$(LIBRARY): $(OBJ1) $(OBJ2) 
	ar rcs $(LIBRARY) $(OBJ1) $(OBJ2)

advancedClassificationLoop.o: advancedClassificationLoop.c $(HEADER)
	$(CC) $(CFLAGS) -c -o advancedClassificationLoop.o advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(HEADER)
	$(CC) $(CFLAGS) -c -o advancedClassificationRecursion.o advancedClassificationRecursion.c

basicClassification.o: basicClassification.c $(HEADER)
	$(CC) $(CFLAGS) -c -o basicClassification.o basicClassification.c

recursives: $(LIBRARY2)

$(LIBRARY2): $(OBJ3) $(OBJ1)
	ar rcs $(LIBRARY2) $(OBJ3) $(OBJ1)

recursived: $(DYNLIBRARY3)

$(DYNLIBRARY3): $(OBJ1) $(OBJ3)
	$(CC) -shared -o $(DYNLIBRARY3) $(OBJ1) $(OBJ3)

loopd: $(DYNLIBRARY4)

$(DYNLIBRARY4): $(OBJ1) $(OBJ2)
	$(CC) -shared -o $(DYNLIBRARY4) $(OBJ1) $(OBJ2)
	
.PHONY: all clean loopd loops recursived recursives

clean:
	rm -f $(LIBRARY) $(LIBRARY2) $(DYNLIBRARY3) $(DYNLIBRARY4) $(OBJ) $(TARGET1) $(TARGET2) $(TARGET3)