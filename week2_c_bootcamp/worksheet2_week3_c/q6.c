#include <stdio.h>

float calcNum(float a, float b, char op)
{
    switch(op)
    {
        case'+': return a + b;
        case'-': return a - b;
        case'*': return a * b;
        case'/': 
            if(b!=0.0)
             {
                 return a/b;
             }
            else
             {
                 printf("braindead input");
                return 0.0;
             }
        
    }

}


int main()
{
    float num1,num2,result;
    char operation;

    printf("enter a number:\t");
    scanf("%f", &num1);
    printf("enter a number:\t");
    scanf("%f", &num2);

    printf("enter operation: \t");
    scanf(" %c", &operation);//************VERY IMPORTANT SPACE BEFORE %c

    result=calcNum(num1,num2,operation);
    printf("result:%f\n", result);
    return 0;

}