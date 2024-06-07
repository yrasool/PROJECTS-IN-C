/**
 * Program to decrypt a message encrypted by repeating characters.
 * Each character in the position 'n' is repeated 'n' times.
 * The program reverses this encryption to get the original message.
 * 
 * YUSRA RASOOL
 * 
 */

#include <stdio.h>

void decrypt(char *input, char *output) {
    char *in_ptr = input; // Pointer to traverse the input
    char *out_ptr = output; // Pointer to build the output
    int count = 1; // Variable to keep track of the number of characters to skip

    while (*in_ptr) { // Continue until the null terminator
        *out_ptr = *in_ptr; // Copy character to output
        in_ptr += count; // Move to the next character block
        out_ptr++; // Move to the next position in the output
        count++; // Increase the count for the next character block
    }
    *out_ptr = '\0'; // Null-terminate the output string
}

int main() {
    char encrypted_message[1001]; // Buffer for the encrypted message
    char decrypted_message[1001]; // Buffer for the decrypted message

    printf("Enter message: ");
    scanf("%1000s", encrypted_message); // Read encrypted message

    decrypt(encrypted_message, decrypted_message); // Decrypt the message

    printf("Output: %s\n", decrypted_message); // Print the decrypted message
    return 0; // Return success
}
