#include <stdio.h>

int main() {
    int arr[6];
    int i, j;

    // Input
    printf("Enter 6 integers:\n");
    for (i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }

    // Check for duplicates
    printf("Duplicate elements found:\n");
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 6; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d\n", arr[i]);
            }
        }
    }

    return 0;
}
