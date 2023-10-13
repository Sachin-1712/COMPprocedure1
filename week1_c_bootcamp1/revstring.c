/**#include<stdio.h>
int main()
{
    char str[6]="hello", temp;
    int i;
    for (i=5;i>=0;i--)
    {
        printf("%c", str[i]);
    }
    printf("\tis the string in reverse\n");
printf("%d\n", str[6]);
return 0;
}
*/
#include <stdio.h>
int main(int argc, char **argv)
{
    char str[] = "hello";
    int length=0;
    while (str[length] != '\0')
    {
        length++;
    }
int i;
for(i = length;i>=0;i--)
{
    printf("%c", str[i]);

}
printf("\n");
return 0;
}
