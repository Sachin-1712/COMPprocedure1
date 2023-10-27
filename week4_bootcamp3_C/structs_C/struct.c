#include <stdio.h>
#include <string.h>
struct student 
{
    char name [20];
    char student_id [11];
     // Assuming up to 10 digits.
     unsigned mark;
     };
     int main () 
    {
        struct student new_student = {"SACHIN S", "28932123", 85};
        printf("Student name: %s\n", new_student.name);
        strcpy(new_student.student_id, "77777");
        printf("Student ID: %s\n", new_student.student_id);
        printf("Final mark: %u\n", new_student.mark);
        return 0;
    }