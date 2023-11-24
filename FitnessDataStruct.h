
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
FITNESS_DATA records[1000];
    char line[1000];
    char date[11];
    char time[60];
    char steps[10];
    int recordCount = 0;

int count_data(FILE *fp)
{

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

void printDateTime(const char* date, const char* time) 
{
    printf("%s %s\n", date, time);
}
void find_FewestSteps() 
{
    if (recordCount == 0) 
    {
        printf("No records available. Import a file first.\n");
        return;
    }

    int minSteps = 99999999; // Initialize with a large value
    int minIndex = -1; // Index of the record with the fewest steps

    for (int i = 0; i < recordCount; i++) 
    {
        if (records[i].steps < minSteps) 
        {
            minSteps = records[i].steps;
            minIndex = i;
        }
    }

    if (minIndex != -1) 
    {
        // Print the result
        printf("Fewest steps: ");
        printDateTime(records[minIndex].date, records[minIndex].time);
    } 
    else 
    {
        printf("Error finding the record with the fewest steps.\n");
    }
}
void find_LargestSteps()
{
    if (recordCount == 0) 
    {
        printf("No records available. Import a file first.\n");
        return;
    }
    int maxSteps = 0;
    int maxIndex = 100;
    for(int i = 0; i < recordCount; i++)
    {
        if(records[i].steps > maxSteps)
        {
            maxSteps = records[i].steps;
            maxIndex = i;
        }
    }
     if (maxIndex != -1) 
    {
        // Print the result
        printf("Largest steps: ");
        printDateTime(records[maxIndex].date, records[maxIndex].time);
    } 
    else 
    {
        printf("Error finding the record with the fewest steps.\n");
    }
}
void find_meanStepCount()
{
    if (recordCount == 0) 
    {
        printf("No records available. Import a file first.\n");
        return;
    }
    float totalSteps = 0;
    float unroundedMean = 0;
    // Calculate the total steps
    for (int i = 0; i < recordCount; i++) 
    {
        totalSteps += records[i].steps;
    }
    unroundedMean = totalSteps / recordCount;
    // Calculate and print the mean step count
    int meanSteps = unroundedMean;
    if (unroundedMean - (float)meanSteps >= 0.5)
    {
        meanSteps++;
    }

    printf("Mean step count: %d\n", meanSteps);
}
void findLongestContinuousPeriod() 
{
    if (recordCount == 0) 
    {
        printf("No records available. Import a file first.\n");
        return;
    }

    int startIndex = -1;  // Index of the start of the current continuous period
    int endIndex = -1;    // Index of the end of the current continuous period
    int currentStart = -1;
    int currentEnd = -1;
    int currentLength = 0;  // Length of the current continuous period
    int maxLength = 0;  // Length of the longest continuous period

    for (int i = 0; i < recordCount; i++) 
    {
        if (records[i].steps > 500) 
        {
           if (currentStart == -1) {
                currentStart = i;
            }
            currentEnd = i;
            currentLength = currentEnd - currentStart + 1;

            if (currentLength > maxLength) {
                maxLength = currentLength;
                startIndex = currentStart;
                endIndex = currentEnd;
            }
        } 
        else 
        {
            currentStart = -1;
            currentEnd = -1;
            currentLength = 0;
        }
    }

    if (startIndex != -1 && endIndex != -1) 
    {
        // Print the result
        printf("Longest period start: %s %s\n", records[startIndex].date, records[startIndex].time);
        printf("Longest period end: %s %s\n", records[endIndex].date, records[endIndex].time );
    } 
    else 
    {
        printf("No continuous period above 500 steps found.\n");
    }
}

#endif // FITNESS_DATA_STRUCT_H
