#include <stdio.h>
int main()
{
int a = 20;
while (a>=0)
{
    if(a%2==0)
    printf ("%d\n", a);
    a--;
}
printf ("I've finished the loop and a is equal to %d\n", a);
return (0);
}