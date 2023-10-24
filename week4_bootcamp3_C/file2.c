#include <stdio.h>
int main() 
{
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w");//file is a pointer variable used to work with the file (FILE)
    if (file == NULL) 
    {
        perror("");
        return 1;
    }
    int number, num_lines = 10;
    printf("Type %d numbers: ", num_lines);
    for (int i = 0; i < num_lines; i++) 
    {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);//fprintf is used to write something into the file
    }
    fclose(file);
    return 0;
}