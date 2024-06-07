/**
 * Input Validation Program
 *
 * This program reads a line of input from the user and checks if the input string adheres to a specific set of validation rules. 
 * The valid characters include lowercase letters (a-z), space (' '), certain punctuation marks ('!', '?', '.'), and digits from 0 to 8.
 * It reads characters until a newline ('\n') is encountered. 
 *
 * If the input string only contains valid characters, the program outputs "valid". If any character in the input string doesn't meet 
 * the criteria, the program outputs "invalid". This approach ensures that the entire input string is evaluated as a whole before 
 * determining its validity.
 *
 
 * YUSRA RASOOL
 * U67661285**/

#include <stdio.h>

int main() {
    char y;
    int isValid = 1; // Flag to track if the input is valid

    printf("Enter input:");
    while ((y = getchar()) != '\n' && isValid) { // Read characters until a newline is encountered
        // Check if the character is valid
        if (!((y >= 'a' && y <= 'z') || y == ' ' || y == '!' || y == '?' || y == '.' || (y >= '0' && y <= '8'))) {
            isValid = 0; // Mark as invalid if any character doesn't meet the criteria
        }
    }

    if (isValid) {
        printf("valid\n");
    } else {
        printf("invalid\n");
    }
    
    return 0;
}
