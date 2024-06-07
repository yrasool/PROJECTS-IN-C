
/* yusra rasool
u67661285
 * Event Package Cost Calculator
 * This program calculates the cost of an event based on the selected package,
 * rental hours, and number of guests. It ensures that all inputs are valid,
 * applies package-specific calculations, and enforces maximum cost constraints.
 */

#include <stdio.h>

int main() {
    // Variables for user input and final charge calculation
    int package, hours, guests;
    int charge = 0;
    // Maximum allowed charges for each package
    const int maxChargePackage1 = 595;
    const int maxChargePackage2 = 850;
    const int maxChargePackage3 = 1050;

    // Prompt the user for package selection
    printf("Please select from three packages: 1, 2, and 3\n");

    // Take user input for package selection
    printf("Enter package selection:");
    scanf("%d", &package);

    // Validate the package selection input
    if (package < 1 || package > 3) {
        printf("Invalid selection.");
        return 0; // Exit the program if the selection is invalid
    }

    // Take user input for rental hours
    printf("Enter hours:");
    scanf("%d", &hours);

    // Validate the rental hours input
    if (hours < 1 || hours > 4) {
        printf("Invalid hours.");
        return 0; // Exit the program if the hours are invalid
    }

    // Take user input for the number of guests
    printf("Enter the number of guests:");
    scanf("%d", &guests);

    // Calculate the charge based on user input and package constraints
    switch (package) {
        case 1:
            if (guests < 5 || guests > 20) {
                printf("Invalid number of guests.");
                return 0; // Exit the program if the number of guests is invalid
            }
            charge = 150 + (hours - 1) * 100 + guests * 25;
            charge = (charge > maxChargePackage1) ? maxChargePackage1 : charge;
            break;
        case 2:
            if (guests < 8 || guests > 30) {
                printf("Invalid number of guests.");
                return 0; // Exit the program if the number of guests is invalid
            }
            charge = 180 + (hours - 1) * 120 + guests * 22;
            charge = (charge > maxChargePackage2) ? maxChargePackage2 : charge;
            break;
        case 3:
            if (guests < 10 || guests > 40) {
                printf("Invalid number of guests.");
                return 0; // Exit the program if the number of guests is invalid
            }
            charge = 200 + (hours - 1) * 150 + guests * 20;
            charge = (charge > maxChargePackage3) ? maxChargePackage3 : charge;
            break;
        default:
            printf("Invalid selection.");
            return 0; // This case should never be reached due to earlier validation
    }

    // Output the final calculated charge
    printf("Charge($):%d", charge);
    return 0;
}
