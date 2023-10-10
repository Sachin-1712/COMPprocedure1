#include <stdio.h>

int main() {

    float length, width;
    float area;

    


    printf("Please enter side length:");

    scanf("%f", &length);

    printf("Please enter side width:");

    scanf("%f", &width);

    area= length * width;

    printf("area is %lf\n", area);



 return 0;

}