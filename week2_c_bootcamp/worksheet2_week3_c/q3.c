#include <stdio.h>
int str_len(char str[])
{
    int length=0;
   while (str[length] != '\0') {
        length++;
   }
   return length;
}
int main()
{
    char str2[10];
    printf("enter the string");
    scanf("%s", str2);
    int result=str_len(str2);
    printf("the length is %d\t", result);
}
