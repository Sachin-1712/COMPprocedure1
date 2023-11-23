#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
int tokeniseRecord(char *record, char *date, char *time, int *steps) {
    // Check for an empty line
    if (record[0] == '\0' || record[0] == '\n') {
        printf("Error: Empty line found. Skipping.\n");
        return 1;  // Empty line
    }

    // Check for the number of tokens
    int tokenCount = 0;
    char *ptr = record;
    while (*ptr != '\0') {
        if (*ptr == ',' || *ptr == '\t') {
            tokenCount++;
        }
        ptr++;
    }

    if (tokenCount != 2) {
        printf("Error: Incorrect number of tokens in line. Skipping.\n");
        return 1;  // Incorrect number of tokens
    }

    // Tokenize the record
    ptr = strtok(record, ",\t");
    if (ptr == NULL) {
        printf("Error: Missing date in line. Skipping.\n");
        return 1;  // Missing date
    }
    strcpy(date, ptr);

    ptr = strtok(NULL, ",\t");
    if (ptr == NULL) {
        printf("Error: Missing time in line. Skipping.\n");
        return 1;  // Missing time
    }
    strcpy(time, ptr);

    ptr = strtok(NULL, ",\t");
    if (ptr == NULL) {
        printf("Error: Missing steps in line. Skipping.\n");
        return 1;  // Missing steps
    }

    // Check if steps conversion is successful
    char *endptr;
    *steps = strtol(ptr, &endptr, 10);

    if (*endptr != '\0' && *endptr != '\n') {
        printf("Error: Invalid steps format in line. Skipping.\n");
        return 1;  // Invalid steps format
    }

    return 0;  // Successful tokenization
}

// Function to perform bubble sort on FitnessData array
void bubbleSort(FitnessData *data, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j].steps < data[j + 1].steps) {
                // Swap data[j] and data[j+1]
                FitnessData temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    char filename[100];
    printf("Enter Filename: ");
    scanf("%s", filename);

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read data from the file
    FitnessData data[100];  // Assuming a maximum of 100 records, adjust as needed
    int count = 0;
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        // Check for errors during tokenization
        if (tokeniseRecord(line, data[count].date, data[count].time, &data[count].steps) == 0) {
            count++;
        }
    }

    fclose(file);

    // Sort the data using bubble sort
    bubbleSort(data, count);

    // Create and write to the output file
    char outputFilename[100];
    strcpy(outputFilename, filename);
    strcat(outputFilename, ".tsv");

    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }

    fclose(outputFile);

    printf("Data sorted and written to %s\n", outputFilename);

    return 0;
}
