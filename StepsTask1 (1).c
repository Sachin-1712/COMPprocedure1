// author: sc23sss@leeds.ac.uk or Sachin Sujay Sindhe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESSDATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function


int main()
    {
    FILE *fp = fopen("FitnessData_2023.csv", "r"); // open the csv file
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    FITNESSDATA records[1000];
    char line[1000];
    char date[11];
    char time[6];
    char steps[10];
    int recordCount = 0;

    // loop for populating the records array
    // I based this on an idea I found here: 
    // Prompt: what is fgets function
    // https://www.geeksforgeeks.org/convert-string-to-int-in-c/
    while (fgets(line, sizeof(line), fp) != NULL && recordCount < 1000) // reads lines from the file using the fgets()
    {
        tokeniseRecord(line, ",", date, time, steps);
        strcpy(records[recordCount].date, date);
        strcpy(records[recordCount].time, time);
        records[recordCount].steps = atoi(steps); // convert string to integer using atoi()
        recordCount++;
    }

    fclose(fp);

    // print the number of records
    printf("Number of records in file: %d\n",recordCount);

    // print the first three records without spaces
    // I based this on an idea I found here:
    // https://www.freecodecamp.org/news/format-specifiers-in-c/
    for (int i = 0; i < 3 && i < recordCount; i++) {
        printf("%s/%s/%d\n", records[i].date, records[i].time, records[i].steps);
    }

    return 0;
}
