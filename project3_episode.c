/* 
 * YUSRA RASOOL
 U67661285
 * Description: This program determines which episode of a TV series has not been watched.
 * Yuka has watched all episodes of a season except for one. The program reads the total
 * number of episodes and the episodes Yuka has watched, then prints the one she hasn't.
 *
 * 
 */

#include <stdio.h>

int main() {
    int n; // Total number of episodes in the season
    int episode; // Variable to store episode number that Yuka has watched
    int total = 0; // Sum of all episode numbers
    int watched = 0; // Sum of watched episode numbers

    // Prompt user for the total number of episodes
    printf("Enter number of episodes: ");
    scanf("%d", &n);

    // Prompt user to enter the episodes that have been watched
    printf("Enter episodes watched: ");
    for(int i = 1; i < n; i++) {
        scanf("%d", &episode); // Read each watched episode number
        watched += episode; // Add to the sum of watched episodes
    }

    // Calculate the sum of all episode numbers using the formula for the sum of an arithmetic series
    total = (n * (n + 1)) / 2;

    // The missing episode is the difference between the total sum and the watched sum
    printf("Missing episode: %d\n", total - watched);

    return 0; // Return success
}
