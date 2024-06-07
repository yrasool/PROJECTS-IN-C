

#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIES 200
#define MAX_STRING_SIZE 100

// Structure to store supply information
typedef struct {
    char name[MAX_STRING_SIZE];
    char color[MAX_STRING_SIZE];
    int quantity;
} supply;

// Function prototype for search
int search(supply list[], int n, supply result[], char *search_name);

// Main function
int main() {
    supply list[MAX_SUPPLIES];     // Array to store all supplies from the file
    supply result[MAX_SUPPLIES];   // Array to store search results
    char search_name[MAX_STRING_SIZE]; // User input for the supply name
    int n = 0;  // Number of supplies read from the file

    // Open the input file
    FILE *file = fopen("supply.csv", "r");
    if (file == NULL) {
        printf("Could not open file supply.csv\n");
        return 1;
    }

    // Read supplies from the file and store them in the list array
    while (fscanf(file, " %[^,], %[^,], %d\n", list[n].name, list[n].color, &list[n].quantity) == 3) {
        n++;
    }
    fclose(file); // Close the input file

    // Prompt the user to enter the supply name
    printf("Enter supply: ");
    fgets(search_name, MAX_STRING_SIZE, stdin);
    // Remove newline character from input if present
    search_name[strcspn(search_name, "\n")] = 0;

    // Search for the supply in the list array and store results in the result array
    int count = search(list, n, result, search_name);

    // Open the output file
    FILE *output = fopen("result.csv", "w");
    if (output == NULL) {
        printf("Could not open file result.csv\n");
        return 1;
    }

    // Write search results to the output file
    for (int i = 0; i < count; i++) {
        fprintf(output, "%s, %s, %d\n", result[i].name, result[i].color, result[i].quantity);
    }
    fclose(output); // Close the output file

    return 0;
}

// Function to search for supplies matching the search_name in the list array
int search(supply list[], int n, supply result[], char *search_name) {
    int count = 0; // Count of matching supplies
    // Iterate over all supplies and check for a match
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].name, search_name) == 0) {
            result[count++] = list[i]; // Add matching supply to result array
        }
    }
    return count; // Return the number of matching supplies
}

