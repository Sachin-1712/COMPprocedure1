#include <stdio.h>
int main()
{
    int arr[]={10,20,30,40,50};
    printf("original array \n");
    for(int i=0;i<5;i++)
    {
        printf("%d\n", arr[i]);
    }
printf("array in reverse order\n");
for(int i=4;i>=0;i--)
{
    printf("%d\n", arr[i]);
}
return 0;
}
