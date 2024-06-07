#include "volunteer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {
    char code;
    Volunteer *head = NULL;  // Pointer to the head of the list of volunteers

    printf("Operation Code: a for adding to the list, s for searching, d for deleting from the list, p for printing the list; q for quit.\n");
    while (1) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');  // Clear the input buffer after reading the operation code

        switch (code) {
            case 'a': {
                char lastName[50], firstName[50], email[100];
                int grade;
                printf("Enter last name: ");
                scanf("%49s", lastName);
                printf("Enter first name: ");
                scanf("%49s", firstName);
                printf("Enter email address: ");
                scanf("%99s", email);
                printf("Enter grade level: ");
                scanf("%d", &grade);
                add_to_list(&head, lastName, firstName, email, grade);
                break;
            }
            case 'd': {
                char lastName[50], firstName[50], email[100];
                int grade;
                printf("Enter last name: ");
                scanf("%49s", lastName);
                printf("Enter first name: ");
                scanf("%49s", firstName);
                printf("Enter email address: ");
                scanf("%99s", email);
                printf("Enter grade level: ");
                scanf("%d", &grade);
                delete_from_list(&head, lastName, firstName, email, grade);
                break;
            }
            case 'p':
                print_list(head);
                break;
            case 'q':
                free_list(head);  // Free the entire list
                return 0;  // Exit the program
            default:
                printf("Illegal code\n");
        }
        if (code != 'q') {
            printf("\n");  // Ensure there is a newline after each operation
        }
    }
    return 0;
} 

