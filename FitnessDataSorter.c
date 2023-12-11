// author: sc23sss@leeds.ac.uk
// Task 3 Procedural Programming
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenise a record
int tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
                return 1;
            }
        }
    }
    printf("Bad data format ");
    exit(1);
}

// Function to compare FitnessData records for sorting
int compareRecords(const void *a, const void *b) {
    return ((FitnessData *)b)->steps - ((FitnessData *)a)->steps;
}
// I based this on an idea I found here:
// https://www.geeksforgeeks.org/bubble-sort/
// Function to perform bubble sort on FitnessData records
void bubbleSort(FitnessData *data, int recordCount) 
{
    for (int i = 0; i < recordCount - 1; i++) 
    {
        for (int j = 0; j < recordCount - i - 1; j++) 
        {
            if (data[j].steps < data[j + 1].steps) 
            {
                // Swap the records
                FitnessData temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    char filename[100];
    
    // Provide a menu option to specify a filename
    printf("Enter Filename: ");
    scanf("%s", filename);

    // Process the data file (read in and sort)
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Check if the file has a .csv extension by using strrchr to find last occurence of '.'
    // I based this on an idea I found here:
    // https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-strrchr-find-last-occurrence-character-in-string
    char *dot = strrchr(filename, '.');
    if (dot == NULL || strcmp(dot, ".csv") != 0) // to check if filename has a '.' and ".csv"
    {
        printf("Invalid file format. Please provide a CSV file.\n");
        fclose(file);
        return 1;
    }

    char line[100];
    FitnessData data[100];
    int recordCount = 0;

    // Read data from the file
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (!tokeniseRecord(line, ',', data[recordCount].date, data[recordCount].time, &data[recordCount].steps)) {
            printf("Invalid data format in file %s\n", filename);
            fclose(file);
            return 1;
    }
        // Check for missing steps, date or time
    if (data[recordCount].steps == '\0' || strlen(data[recordCount].date) == 0 || strlen(data[recordCount].time) == 0) 
    {
        printf("Missing data\n");
        fclose(file);
        return 1;
    }

        recordCount++;
    }

    // Close the file
    fclose(file);

    // Sort the data using bubble sort
    bubbleSort(data, recordCount);

    // Change the file extension to .csv.tsv
    strcpy(dot, ".csv.tsv");

    // Write sorted data to the new file
    FILE *outputFile = fopen(filename, "w");
    if (outputFile == NULL) {
        printf("Error creating output file %s\n", filename);
        return 1;
    }

    // Write the sorted data to the output file in tab-separated format (TSV)
    for (int i = 0; i < recordCount; i++) {
        fprintf(outputFile, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }

    // Close the output file
    fclose(outputFile);

    printf("Data sorted and written to %s\n", filename);

    return 0;
}
