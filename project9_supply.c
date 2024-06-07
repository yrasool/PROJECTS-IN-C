/**
 * School Supply Sorting System
 * 
 * This program reads school supply data from a CSV file named 'supply.csv'. Each entry in the CSV file
 * contains the name, color, and quantity of a school supply. The program is designed to handle up to
 * 200 supply entries, adhering to the defined maximum limits.
 * 
 * Once the data is read into an array of structures, the program utilizes the C standard library's
 * quicksort function (qsort) to sort the supplies. The sorting criteria are primarily by the supply
 * name and, secondarily, by color if the names are identical. This dual-level sorting ensures a 
 * consistent and logical ordering of supplies, useful for inventory management or catalog display.
 * 
 * After sorting, the program writes the organized list of supplies back to a new CSV file named 
 * 'result.csv'. This file will have the same format as the input file but with the entries ordered
 * as per the specified sorting criteria.
 * 
 * The program performs no user interaction via the keyboard and does not output any information to
 * the screen, focusing solely on file-based input and output for integration into larger systems or
 * batch processing tasks.
YUSRA RASOOL
U67661285

 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUPPLIES 200
#define MAX_STRING_SIZE 100

// Structure to store supply information
typedef struct {
    char name[MAX_STRING_SIZE];
    char color[MAX_STRING_SIZE];
    int quantity;
} supply;

// Comparison function for qsort
int compare_supplies(const void *a, const void *b) {
    supply *supplyA = (supply *)a;
    supply *supplyB = (supply *)b;
    int nameComp = strcmp(supplyA->name, supplyB->name);
    if (nameComp == 0) {
        return strcmp(supplyA->color, supplyB->color);  // Sort by color if names are the same
    }
    return nameComp;  // Sort by name otherwise
}

// Main function
int main() {
    supply list[MAX_SUPPLIES];     // Array to store all supplies from the file
    int n = 0;  // Number of supplies read from the file

    // Open the input file
    FILE *file = fopen("supply.csv", "r");
    if (file == NULL) {
        printf("Could not open file supply.csv\n");
        return 1;
    }

    // Read supplies from the file and store them in the list array
    while (fscanf(file, " %[^,], %[^,], %d\n", list[n].name, list[n].color, &list[n].quantity) == 3 && n < MAX_SUPPLIES) {
        n++;
    }
    fclose(file); // Close the input file

    // Sort the supplies using qsort
    qsort(list, n, sizeof(supply), compare_supplies);

    // Open the output file
    FILE *output = fopen("result.csv", "w");
    if (output == NULL) {
        printf("Could not open file result.csv\n");
        return 1;
    }

    // Write the sorted supplies to the output file
    for (int i = 0; i < n; i++) {
        fprintf(output, "%s, %s, %d\n", list[i].name, list[i].color, list[i].quantity);
    }
    fclose(output); // Close the output file

    return 0;
}
