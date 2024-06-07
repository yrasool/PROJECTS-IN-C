
/**
 * Vending Machine Program
 * 
 * This program simulates a vending machine that accepts coin inputs and allows the user to select a candy. 
 * The available candies are Hershey's kisses, Reese's Peanut Butter Cups, and Snickers, priced at 15, 25, 
 * and 50 cents respectively. The user inserts coins until they choose to stop (by entering 0). After coin 
 * insertion, the program displays the candy choices with their prices. The user then selects a candy. The 
 * program checks if the user has inserted enough money for the selected candy. If yes, it dispenses the candy 
 * and returns the change. If the inserted amount is insufficient, the machine returns all the inserted money. 
 * If an invalid selection is made, the machine also returns all the inserted money.
 *
 
 Yusra Rasool
 U67661285
 */
#include <stdio.h>

#define HERSHEY 15
#define BUTTER 25
#define SNEAKERS 50

int main() {
    int x;
    int y;
    int z = 0;

    printf("Insert coins: ");
    scanf("%d", &x);

    while (x != 0) {
        z += x;
        printf("Insert coins: "); // Prompt for the next input
        scanf("%d", &x); // Update x for the next iteration
    }

    // Display candy choices after coin insertion is complete
    printf("1 - Hershey's kisses (%d cents), 2 - Reese's Peanut Butter Cups (%d cents), 3 - Snickers (%d cents)\n", HERSHEY, BUTTER, SNEAKERS);
    printf("Enter your choice: ");
    scanf("%d", &y);

    // Process the candy selection and calculate the change
    switch (y) {
        case 1:
            if (z >= HERSHEY)
                printf("Your change is %d cents\n", z - HERSHEY);
            else
                printf("Insufficient amount, %d cents returned\n", z);
            break;
        case 2:
            if (z >= BUTTER)
                printf("Your change is %d cents\n", z - BUTTER);
            else
                printf("Insufficient amount, %d cents returned\n", z);
            break;
        case 3:
            if (z >= SNEAKERS)
                printf("Your change is %d cents\n", z - SNEAKERS);
            else
                printf("Insufficient amount, %d cents returned\n", z);
            break;
        default:
            printf("Invalid selection, %d cents returned\n", z);
    }

    return 0;
}





