#include <stdio.h>

int main() 
{
    int mark;
    printf("enter the mark\n");
    scanf("%d", &mark);
    if(mark>=70)
    printf("distinction");
    else if(mark>=50)
    printf("pass");
    else
    printf("fail");
 

    return 0;
}
