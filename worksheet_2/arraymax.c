#include <stdio.h>

int main() 
{

int size=4,i,max;

int a[size];

printf("enter the element of array\n");

for(i=0;i<=size;i++)

{
    scanf("%d",&a[i]);
}

printf("max element of array:");

max=a[0];

for(i=0;i<=size;i++)

{
    if(a[i]>max)
    max=a[i];

}

printf("%d\n", max);

return 0;
}
