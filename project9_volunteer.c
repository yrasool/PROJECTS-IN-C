/**
 * Volunteer Management System
 * 
 * This program manages a list of volunteers using a singly linked list. Each volunteer is represented
 * as a node in the linked list containing their last name, first name, email address, and grade level.
 * The program supports adding volunteers to the end of the list, deleting volunteers from the list,
 * and printing all volunteer information. It operates through a simple command line interface that
 * prompts the user to enter an operation code to add, delete, or print volunteer data, or to quit the program.
 * 
 * Operations:
 * - 'a': Add a new volunteer to the end of the list.
 * - 'd': Delete a specified volunteer from the list.
 * - 'p': Print the list of all volunteers.
 * - 'q': Quit the program.
 *
 * This implementation ensures basic memory management, such as freeing nodes when volunteers are deleted,
 * and provides simple error handling for operations like adding new volunteers and attempting to delete
 * non-existent volunteers.

YUSRA RASOOL
U67661285 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Volunteer {
    char lastName[30];
    char firstName[30];
    char email[50];
    int grade;
    struct Volunteer *next;
} Volunteer;

// Function prototypes
void add_to_list(Volunteer **head, char *lastName, char *firstName, char *email, int grade);
void delete_from_list(Volunteer **head, char *lastName, char *firstName, char *email, int grade);
void print_list(Volunteer *head);

int main() {
    Volunteer *head = NULL;
    char operation;
    char lastName[30], firstName[30], email[50];
    int grade;

    printf("Operation Code: a for adding to the list, s for searching, d for deleting from the list, p for printing the list; q for quit.\n");
    
    while(1) {
        printf("Enter operation code: ");
        scanf(" %c", &operation);

        switch(operation) {
            case 'a':
                printf("Enter last name: ");
                scanf("%s", lastName);
                printf("Enter first name: ");
                scanf("%s", firstName);
                printf("Enter email address: ");
                scanf("%s", email);
                printf("Enter grade level: ");
                scanf("%d", &grade);
                add_to_list(&head, lastName, firstName, email, grade);
                printf("\n"); // Ensure each command ends with a new line
                break;
            case 'd':
                printf("Enter last name: ");
                scanf("%s", lastName);
                printf("Enter first name: ");
                scanf("%s", firstName);
                printf("Enter email address: ");
                scanf("%s", email);
                printf("Enter grade level: ");
                scanf("%d", &grade);
                delete_from_list(&head, lastName, firstName, email, grade);
                printf("\n"); // Ensure each command ends with a new line
                break;
            case 'p':
                print_list(head);
                printf("\n"); // Ensure each command ends with a new line
                break;
            case 'q':
                return 0; // Exit without adding a new line
            default:
                printf("Invalid operation code.\n");
        }
    }
}

void add_to_list(Volunteer **head, char *lastName, char *firstName, char *email, int grade) {
    Volunteer *newNode = (Volunteer *)malloc(sizeof(Volunteer));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->lastName, lastName);
    strcpy(newNode->firstName, firstName);
    strcpy(newNode->email, email);
    newNode->grade = grade;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Volunteer *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete_from_list(Volunteer **head, char *lastName, char *firstName, char *email, int grade) {
    Volunteer *current = *head;
    Volunteer *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->lastName, lastName) == 0 &&
            strcmp(current->firstName, firstName) == 0 &&
            strcmp(current->email, email) == 0 &&
            current->grade == grade) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_list(Volunteer *head) {
    // Check if the list is empty and return without printing anything
    if (head == NULL) {
        return; // No output when list is empty to match the test case
    }
    while (head != NULL) {
        printf("%-10s %-10s %-30s %d\n", head->lastName, head->firstName, head->email, head->grade);
        head = head->next;
    }
}


