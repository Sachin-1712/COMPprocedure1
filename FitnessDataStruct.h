
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) 
{
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
int count_data(FILE *fp)
{
	FITNESS_DATA records[1000];
    char line[1000];
    char date[11];
    char time[6];
    char steps[10];
    int recordCount = 0;

	while (fgets(line, sizeof(line), fp) != NULL && recordCount < 1000) // reads lines from the file using the fgets()
    {
        tokeniseRecord(line, ",", date, time, steps);
        strcpy(records[recordCount].date, date);
        strcpy(records[recordCount].time, time);
        records[recordCount].steps = atoi(steps); // convert string to integer using atoi()
        recordCount++;
    }
	return recordCount;
}


#endif // FITNESS_DATA_STRUCT_H
