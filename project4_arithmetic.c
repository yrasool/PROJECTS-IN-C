/*
 * This program checks if a given sequence of integers is an arithmetic sequence.
 * It reads the length of the sequence and the sequence elements from the user.
 * Then, it determines if the difference between consecutive elements is constant
 * throughout the sequence, indicating that it is an arithmetic sequence.
 * If the sequence is arithmetic, the program outputs "yes"; otherwise, it outputs "no".
 * 
 * 
 * Yusra rasool
 */

#include <stdio.h>

int is_arithmetic_sequence(int *sequence, int n) {
    int diff = *(sequence + 1) - *sequence;
    for (int *ptr = sequence + 1; ptr < sequence + n - 1; ++ptr) {
        if (*(ptr + 1) - *ptr != diff) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter length of the sequence: ");
    scanf("%d", &n);

    int sequence[n];

    printf("Enter numbers of the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    if (is_arithmetic_sequence(sequence, n)) printf("yes\n");
    else printf("no\n");

    return 0;
}
