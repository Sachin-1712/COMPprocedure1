#include <stdio.h>

#define MAX_ITEMS 2
#define NUM_PEOPLE 4

// Structure to represent an item
struct GroceryItem {
    char name[50];
    int quantity;
    float price;
    int sharedWith[NUM_PEOPLE];
};

// Function to calculate the total amount for each person
void calculateTotalAmount(struct GroceryItem items[], float totalAmounts[]) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        for (int j = 0; j < NUM_PEOPLE; ++j) {
            if (items[i].sharedWith[j]) {
                totalAmounts[j] += items[i].quantity * items[i].price / NUM_PEOPLE;
                break; // Break once the item is marked as shared with this person
            }
        }
    }
}

int main() {
    struct GroceryItem items[MAX_ITEMS];
    float totalAmounts[NUM_PEOPLE] = {0};

    // Input information for each item
    printf("Enter information for each item:\n");
    for (int i = 0; i < MAX_ITEMS; ++i) {
        printf("\nItem %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", items[i].name);

        printf("Quantity: ");
        scanf("%d", &items[i].quantity);

        printf("Price per unit: ");
        scanf("%f", &items[i].price);

        // Initialize sharedWith array to 0 for each item
        for (int j = 0; j < NUM_PEOPLE; ++j) {
            items[i].sharedWith[j] = 0;
        }

        // Ask whether the item is shared with anyone
        for (int j = 0; j < NUM_PEOPLE; ++j) {
            printf("Is shared with person %d? (1 for yes, 0 for no): ", j + 1);
            scanf("%d", &items[i].sharedWith[j]);
        }
    }

    // Calculate the total amount for each person
    calculateTotalAmount(items, totalAmounts);

    // Display the total amount for each person
    printf("\nTotal Amounts:\n");

    for (int i = 0; i < NUM_PEOPLE; ++i) {
        printf("Person %d: %.2f\n", i + 1, totalAmounts[i]);
    }

    return 0;
}
