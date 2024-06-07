/*
 
 *YUSRA RASOOL
 

 * This program reads words from a file specified by the user, checks each word to determine
 * if it is composed of a substring repeated twice (a "square" word), and writes these square
 * words to an output file named "output.txt". It utilizes the is_square function to assess
 * each word's structure.
 */


#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100
#define MAX_FILENAME_LENGTH 100

// Function prototype declaration
int is_square(char *word);

int main() {
    char fileName[MAX_FILENAME_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *inputFile, *outputFile;

    // Prompt the user for the file name
    printf("Enter file name: ");
    scanf("%s", fileName);

    // Open the input file for reading
    inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Could not open file %s for reading.\n", fileName);
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Could not open file output.txt for writing.\n");
        fclose(inputFile);
        return 1;
    }

    // Read words from the input file and check if they are square words
    while (fscanf(inputFile, "%s", word) != EOF) {
        if (is_square(word)) {
            fprintf(outputFile, "%s\n", word);
        }
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

// Function to check if the word is a square word
int is_square(char *word) {
    int len = strlen(word);
    // A word can only be square if its length is even
    if (len % 2 != 0) {
        return 0;
    }

    int halfLen = len / 2;
    for (int i = 0; i < halfLen; ++i) {
        if (word[i] != word[i + halfLen]) {
            return 0;
        }
    }
    return 1;
}
