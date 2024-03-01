#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    int number;
    const char *binaryRepresentation;

    // Check if the correct number of arguments is provided
    if (argc != 3) {
        printf("Usage: %s <-c/-d> <filename>\n", argv[0]);
        return 1;
    }

    // Determine the operation based on the flag
    if (strcmp(argv[1], "-c") == 0) {
        // Compressing from text file to binary file
        inputFile = fopen(argv[2], "r");
        if (inputFile == NULL) {
            perror("Error opening input file");
            return 1;
        }

        sprintf(outputFileName, "%s.bin", argv[2]); // Output binary file name
        outputFile = fopen(outputFileName, "wb");
        if (outputFile == NULL) {
            perror("Error opening output file");
            fclose(inputFile);
            return 1;
        }

        printf("Compressing file %s to %s\n", argv[2], outputFileName);

        // Read decimal numbers from the input file, compress them, and write to the output binary file
        while (fscanf(inputFile, "%d", &number) != EOF) {
            binaryRepresentation = compressDigit(number);
            if (binaryRepresentation == NULL) {
                printf("Error: Invalid digit %d\n", number);
                fclose(inputFile);
                fclose(outputFile);
                return 1;
            }
            fwrite(binaryRepresentation, sizeof(char), strlen(binaryRepresentation), outputFile);
        }

        printf("Compression completed.\n");
        fclose(inputFile);
        fclose(outputFile);
    } else if (strcmp(argv[1], "-d") == 0) {
        // Decompressing from binary file to stdout
        inputFile = fopen(argv[2], "rb");
        if (inputFile == NULL) {
            perror("Error opening input file");
            return 1;
        }

        printf("Decompressing file %s to stdout\n", argv[2]);

        // Read binary data from the input file, decompress and print to stdout
        while (fread(&number, sizeof(int), 1, inputFile) == 1) {
            printf("%d ", number);
        }

        printf("\nDecompression completed.\n");
        fclose(inputFile);
    } else {
        printf("Invalid flag. Usage: %s <-c/-d> <filename>\n", argv[0]);
        return 1;
    }

    return 0;
}
