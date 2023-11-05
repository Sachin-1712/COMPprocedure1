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
    scanf("%u", &n);
    for (int i = 1; i <= n; i++) 
    {
        fprintf(fptr, "%d\n", i*i);//fprintf is used to write something into the file
    }
    fclose(fptr);
    return 0;
}