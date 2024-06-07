#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMAIL_LEN 100
#define NAME_LEN 30
/*
 * Volunteer Management System
 * ---------------------------
 * This program manages a list of high school volunteers using a dynamically allocated linked list.
 * Each volunteer's record includes their last name, first name, email address, and grade level.
 * The program allows users to add new volunteers to the list, search for volunteers by grade level,
 * print the entire list of volunteers, and exit the program while freeing allocated memory.
 * 
 * Operations include:
 * - Adding a volunteer to the list (checks for duplicates based on email and last name).
 * - Searching for volunteers by grade level and printing their details.
 * - Printing the details of all volunteers.
 * - Exiting the program and clearing the linked list from memory.
 * 
 * The program prompts the user to enter an operation code for the desired action, and it performs
 * input validation for each operation to ensure data integrity and to prevent duplication.
 * 
 * YUSRA RASOOL
 * 
 */

struct volunteer {
    char first[NAME_LEN+1];
    char last[NAME_LEN+1];
    char email[EMAIL_LEN+1];
    int grade_level;
    struct volunteer *next;
};

struct volunteer *add_to_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
int read_line(char str[], int n);

int main(void) {
    char code;
    struct volunteer *volunteer_list = NULL;
    printf("Operation Code: a for adding to the list, s for searching, p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); // skips to end of line
        switch (code) {
            case 'a':
                volunteer_list = add_to_list(volunteer_list);
                break;
            case 's':
                search_list(volunteer_list);
                break;
            case 'p':
                print_list(volunteer_list);
                break;
            case 'q':
                clear_list(volunteer_list);
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

struct volunteer *add_to_list(struct volunteer *list) {
    char last[NAME_LEN+1], first[NAME_LEN+1], email[EMAIL_LEN+1];
    int grade_level;
    printf("Enter last name: ");
    read_line(last, NAME_LEN);
    printf("Enter first name: ");
    read_line(first, NAME_LEN);
    printf("Enter email address: ");
    read_line(email, EMAIL_LEN);
    printf("Enter grade level: ");
    scanf("%d", &grade_level);

    // Check for existing volunteer
    for (struct volunteer *cur = list; cur != NULL; cur = cur->next) {
        if (strcmp(cur->email, email) == 0 && strcmp(cur->last, last) == 0) {
          printf("volunteer already exists.\n"); // Adjusted message to match expected output
          return list;
    }
}


    struct volunteer *new_vol = malloc(sizeof(struct volunteer));
    if (new_vol == NULL) {
        printf("Failed to allocate memory.\n");
        return list;
    }
    strcpy(new_vol->last, last);
    strcpy(new_vol->first, first);
    strcpy(new_vol->email, email);
    new_vol->grade_level = grade_level;
    new_vol->next = NULL;

    if (list == NULL) {
        return new_vol;
    } else {
        struct volunteer *cur = list;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_vol;
        return list;
    }
}

void search_list(struct volunteer *list) {
    int grade_level;
    printf("Enter grade level: ");
    scanf("%d", &grade_level);
    int found = 0;
    for (struct volunteer *cur = list; cur != NULL; cur = cur->next) {
        if (cur->grade_level == grade_level) {
            printf("%-12s%-12s%-30s\n", cur->last, cur->first, cur->email);
            found = 1;
        }
    }
    if (!found) {
        printf("not found\n");
    }
}

void print_list(struct volunteer *list) {
    for (struct volunteer *cur = list; cur != NULL; cur = cur->next) {
        printf("%-12s%-12s%-30s%5d\n", cur->last, cur->first, cur->email, cur->grade_level);
    }
}

void clear_list(struct volunteer *list) {
    while (list != NULL) {
        struct volunteer *tmp = list;
        list = list->next;
        free(tmp);
    }
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while (isspace(ch = getchar()));
    if (ch != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
