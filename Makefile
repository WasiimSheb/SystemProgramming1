CC = gcc
SRC = main.c 
SRC1 = basicClassification.c
SRC2 = advancedClassificationLoop.c
SRC3 = advancedClassificationRecursion.c
OBJ1 = basicClassification.o
OBJ2 = advancedClassificationLoop.o
OBJ3 = advancedClassificationRecursion.o
OBJ = main.o
TARGET1 = mains
TARGET2 = maindloop
TARGET3 = maindrec
CFLAGS = -Wall
HEADER = NumClass.h
LIBRARY = libclassloops.a 
LIBRARY2 = libclassrec.a
DYNLIBRARY3 = libclassrec.so
DYNLIBRARY4 = libclassloops.so

all: $(TARGET1) $(TARGET2) $(TARGET3) loops recursives

$(TARGET1): $(LIBRARY2) $(HEADER) $(SRC) $(SRC1) $(SRC3)
	$(CC) $(CFLAGS) -fPIC -o $(TARGET1) $(SRC) $(SRC1) $(SRC3) -L. -lclassrec

$(TARGET2):$(DYNLIBRARY4) $(HEADER) $(SRC) $(SRC1) $(SRC2)
	$(CC) $(CFLAGS) -fPIC -o $(TARGET2) $(SRC) $(SRC1) $(SRC2) -L. -lclassloops

$(TARGET3):	$(DYNLIBRARY3) $(HEADER) $(SRC) $(SRC1) $(SRC3)
	$(CC) $(CFLAGS) -fPIC -o $(TARGET3) $(SRC) $(SRC1) $(SRC3) -L. -lclassrec

loops: $(LIBRARY)

$(LIBRARY): $(OBJ1) $(OBJ2) 
	ar rcs $(LIBRARY) $(OBJ1) $(OBJ2)

advancedClassificationLoop.o: advancedClassificationLoop.c $(HEADER)
	$(CC) $(CFLAGS) -fPIC -c -o advancedClassificationLoop.o advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(HEADER)
	$(CC) $(CFLAGS) -fPIC -c -o advancedClassificationRecursion.o advancedClassificationRecursion.c

basicClassification.o: basicClassification.c $(HEADER)
	$(CC) $(CFLAGS) -fPIC -c -o basicClassification.o basicClassification.c

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
	rm -f $(LIBRARY) $(LIBRARY2) $(DYNLIBRARY3) $(DYNLIBRARY4) $(OBJ) $(TARGET1) $(TARGET2) $(TARGET3) $(OBJ1) $(OBJ2) $(OBJ3)
