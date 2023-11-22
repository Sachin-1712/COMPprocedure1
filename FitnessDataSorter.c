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
void tokeniseRecord(char *record, char *date, char *time, int *steps) {
    char *ptr = strtok(record, ",\t");
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, ",\t");
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, ",\t");
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


// Function to compare two FitnessData records for sorting
int compareRecords(const void *a, const void *b) {
    return ((FitnessData*)b)->steps - ((FitnessData*)a)->steps;
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
        tokeniseRecord(line, data[count].date, data[count].time, &data[count].steps);
        count++;
    }

    fclose(file);

    // Sort the data
    qsort(data, count, sizeof(FitnessData), compareRecords);

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
