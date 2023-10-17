#include <stdio.h>

int main() 
{
    int number;
    printf("enter a number")
    scanf("%d", &number);
    if(number>0)
    printf("number is +ve");
    else if (number==0)
    printf("number is zero");
    else 
    printf("number is -ve");

    return 0;
}