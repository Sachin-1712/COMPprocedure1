#include <stdio.h>
#include <string.h>

int isPrime(int num)
{
    int p;
    p=0;
    for (int i=1;i<=num;i++)
    {
        if(num%i==0)
        p++;

        else if(num==1 || num==0)
        {
        printf(" entered number is not prime number");
        break;
        }

    }
    if(p==2)
    return 1;
else 
return 0;
}


int main()
{
int num1;
printf("enter a number: \t");
scanf("%d", &num1);
int result;
result=isPrime(num1);
if(result==1)
printf("entered number is a prime number");
else
printf("entered number is not a prime number");

}