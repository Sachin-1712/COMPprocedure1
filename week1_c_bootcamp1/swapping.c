#include <stdio.h>

int main() {

    float x, y;
    

    


    printf("Please enter 1st number:");

    scanf("%f", &x);

    printf("Please enter 2nd number:");

    scanf("%f", &y);

    printf("numbers before swapping: %f\t%f\t", x, y);

    x=x+y;
    y=x-y;
    x=x-y;

    printf("numbers after swapping: %lf\t%f\t", x, y);



 return 0;

}