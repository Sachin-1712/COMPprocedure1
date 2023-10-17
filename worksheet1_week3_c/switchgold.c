#include <stdio.h>

int main()
{
    int option;
    
    printf("enter an input between 1 and 5\n");
    scanf("%d", &option);
    
    switch(option)
    {
        case 1:printf("you chose option 1");
        break;
        case 2:printf("you chose option 2");
        break;
        case 3:printf("you chose option 3");
        break;
        case 4:printf("you chose option 4");
        break;
        case 5:printf("you chose option 5");
        break;
        default:printf("invalid input");
    }
}