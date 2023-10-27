#include <stdio.h>

// Define the point structure with two double members
typedef struct {
    double x;
    double y;
} point;

// Function to initialize the array of points using user input
void initializePoints(point pts[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter x and y coordinates for point %d (separated by space): ", i+1);
        scanf("%lf %lf", &pts[i].x, &pts[i].y);
    }
}

int main() {
    point points[10];  // Declare an array of 10 points

    // Initialize the points
    initializePoints(points, 10);

    // Print the points
    printf("\nEntered Points:\n");
    for (int i = 0; i < 10; i++) {
        printf("(%0.2f, %0.2f)\n", points[i].x, points[i].y);
    }

    return 0;
}
