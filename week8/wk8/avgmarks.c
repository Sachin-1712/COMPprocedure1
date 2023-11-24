#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void summarks(int a[4][5])
{
    for (int i = 0; i < 4; i++) 
    {
        int rsum = 0;
        for (int j = 0; j < 5; j++) 
        {
            rsum = rsum + a[i][j];
        }
        printf("\nSum of all the elements in row %d is %d\n",i,rsum);
    }
}
void printArray(int a[4][5]) 
{
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            printf("%d\t\t", a[i][j]);
        }
        printf("\n");
    }
}
// Function to initialize an array with random values
void initializeArrayRandom(int a[4][5]) 
{
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            a[i][j] = rand() % 26; // Generates random values between 0 and 10
        }
    }
}
int main() 
{
int A[4][5];
int B[3][4];
int C[3][4];

srand(time(NULL));
initializeArrayRandom(A);
summarks(A);

// Print arrays A, B, and C
printf("Array A:\n"); printArray(A);

return 0;
}

