#include <stdio.h> 
int main()
 {
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        perror("");
        return 1;
    }
    fclose(file);// VERY IMPORTANT CLOSE FILE 
    return 0;
 }