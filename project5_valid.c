/**
 * Command-Line Arguments Validation Program
 *
 * This program checks if the command-line arguments contain only valid characters, 
 * which include lowercase letters (a-z), space (' '), punctuation marks ('!', '?', '.'), 
 * and digits from 0 to 8. If all arguments are valid, it prints "valid"; otherwise, it prints "invalid".
 *
Yusra Rasool
 * U67661285
 */

#include <stdio.h>
#include <ctype.h>

int isValidCharacter(char ch) {
    // Check if the character is a lowercase letter, space, allowed punctuation, or digit from 0 to 8
    return (islower(ch) || ch == ' ' || ch == '!' || ch == '?' || ch == '.' || (ch >= '0' && ch <= '8'));
}

int main(int argc, char *argv[]) {
    // Check if there is at least one command-line argument besides the program name
    if (argc < 2) {
        printf("invalid number of arguments\n");
        return 1;
    }

    // Iterate over each argument passed to the program
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        // Check each character in the argument
        while (*arg) {
            if (!isValidCharacter(*arg)) {
                printf("invalid\n");
                return 0;
            }
            arg++;
        }
    }

    // If the program reaches this point, all characters in all arguments are valid
    printf("valid\n");
    return 0;
}
