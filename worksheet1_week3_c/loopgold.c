#include <stdio.h>

int main()
{
    int option;
    int i=0;
    while (i!=-1)
    {
        printf("enter a number\n");
         scanf("%d", &i);
         if(i>=0 && i<=100)
         {
             printf("entered number is in the range of 0 to 100\n");
         }
         else if(i==-1)
         {
             printf("end of the program\n");
         }
         else
         {
             printf("entered number is out of range\n");
         }
    }
    printf("program terminated");
    return 0;
}
