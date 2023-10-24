#include <stdio.h>
int main()
{
    char filename[]="squares.dat";
    FILE *fptr=fopen(filename,"w");
    if (fptr == NULL) 
    {
        perror("");
        return 1;
    }
    int number, n;
    printf("enter the value of n where n is the last integer:\n");
    scanf("%d", &n);
    if(n>0)
    {
        int i,j,s;
        printf("Type %d numbers: ", num_lines);
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &number);
            fprintf(fptr, "%d\n", number);//fprintf is used to write something into the file
        }
        for (j = 0;j < n;j++)
        {
            s=number*number;
            printf("%d", &s);
        }
    
        
    
    }
    fclose(fptr);
    return 0;
}