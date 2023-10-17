#include <stdio.h>

int main() 
{
    int number;
    printf("enter a number\n");
    scanf("%d", &number);
    if(number%4==0 && number%5==0)
    printf("%d\tis divisible by 4 and 5", number);
    else 
    printf("the entered number is not divisible by 4 & 5");

    return 0;
}
