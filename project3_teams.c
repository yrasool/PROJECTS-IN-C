/*
 * Program Description: This program has been updated to utilize pointer arithmetic for array processing,
 * replacing array subscripting with pointer operations. It assigns students to teams (beginner, honor, and excellence)
 * based on their accumulated points. The program first reads the number of students and then their points, determining
 * the team assignment based on the proximity of their points to predefined thresholds. The use of pointer arithmetic
 * enhances the efficiency and readability of the code in the context of C programming practices.
 *
 *  Yusra Rasool
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// Modified assign function using pointer arithmetic
void assign(int *points, int *team_assignment, int n) {
    const int BEGINNER = 25;
    const int HONOR = 70;
    const int EXCELLENCE = 125;

    for (int *ptr = points, *ta_ptr = team_assignment; ptr < points + n; ptr++, ta_ptr++) {
        int diff1 = abs(*ptr - BEGINNER);
        int diff2 = abs(*ptr - HONOR);
        int diff3 = abs(*ptr - EXCELLENCE);

        if (diff1 <= diff2 && diff1 <= diff3) {
            *ta_ptr = BEGINNER;
        } else if (diff2 < diff1 && diff2 <= diff3) {
            *ta_ptr = HONOR;
        } else {
            *ta_ptr = EXCELLENCE;
        }
    }
}

int main() {
    int n; // Number of students

    // Prompt user for the total number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    int *points = malloc(n * sizeof(int)); // Dynamically allocate memory for points
    int *team_assignment = malloc(n * sizeof(int)); // Dynamically allocate memory for team assignments

    // Check for memory allocation failure
    if (points == NULL || team_assignment == NULL) {
        printf("Memory allocation failed!\n");
        return -1; // Indicate failure
    }

    // Prompt user for points of each student
    printf("Enter points for each student: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", points + i);
    }

    // Assign students to teams based on their points
    assign(points, team_assignment, n);

    // Output the team assignments
    printf("Beginner team: student");
    for (int i = 0; i < n; i++) {
        if (*(team_assignment + i) == 25) {
            printf(" %d", i + 1); // Print student numbers separated by spaces
        }
    }

    printf("\nHonor team: student");
    for (int i = 0; i < n; i++) {
        if (*(team_assignment + i) == 70) {
            printf(" %d", i + 1); // Print student numbers separated by spaces
        }
    }

    printf("\nExcellence team: student");
    for (int i = 0; i < n; i++) {
        if (*(team_assignment + i) == 125) {
            printf(" %d", i + 1); // Print student numbers separated by spaces
        }
    }
    printf("\n");

    // Free the allocated memory
    free(points);
    free(team_assignment);

    return 0; // Indicate successful completion
}
