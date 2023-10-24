#include <stdio.h> 
int main()
 {
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w");//FILE is a datatype
    if (file == NULL) 
    {
        perror("");
        return 1;
    }
    fclose(file);// VERY IMPORTANT CLOSE FILE (good practice)
    return 0;
 }