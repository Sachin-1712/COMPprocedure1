#include <stdio.h>
int main() 
{
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "a");//file is a pointer variable used to work with the file (FILE)
    if (file == NULL) 
    {
        perror("");
        return 1;
    }
    fprintf(file, "\nhi everybody");

    fclose(file);
    return 0;
}