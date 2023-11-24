
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

int total = 0;

char choice;
char filename[100];

// Complete the main function
int main()
{
    while (1)
    {
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported - you need to check that the file opened correctly\n"); // BRONZE
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");



        // get the next character typed in and store in the 'choice'
        scanf(" %c", &choice);


        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            printf("Input filename: ");
            scanf("%s", filename);
            FILE *fp = fopen(filename, "r"); // open the csv file
            if (fp == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }
            total = count_data(fp);
            fclose(fp);
            break;
        case 'B':
        case 'b':

            printf("Total records: %d\n", total);
            break;

        case 'C':
        case 'c': 
            find_FewestSteps();
            break;

        case 'D':
        case 'd':
            find_LargestSteps();
            break;

        case 'E':
        case 'e':
            find_meanStepCount();
            break;

        case 'F':
        case 'f':
            findLongestContinuousPeriod();
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if user inputs anything else:
        default:
            printf("Invalid choice, Try again\n");
            break;
        }
    }
}
