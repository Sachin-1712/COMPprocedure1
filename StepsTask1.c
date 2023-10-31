#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

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
    FILE *fp = fopen("FitnessData_2023.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    FITNESS_DATA records[1000];
    char line[1000];
    char date[11];
    char time[6];
    char steps[10];
    int recordCount = 0;

    // Read lines and populate the records array
    while (fgets(line, sizeof(line), fp) != NULL && recordCount < 1000) {
        tokeniseRecord(line, ",", date, time, steps);
        strcpy(records[recordCount].date, date);
        strcpy(records[recordCount].time, time);
        records[recordCount].steps = atoi(steps);
        recordCount++;
    }

    fclose(fp);

    // Print the number of records
    printf("Number of records in file: %d\n",recordCount);

    // Print the first three records
    for (int i = 0; i < 3 && i < recordCount; i++) {
        printf("%s/%s/%d\n", records[i].date, records[i].time, records[i].steps);
    }

    return 0;
}


