#include <stdio.h>


float circleArea(float radius)
{
    float area;
    area = 3.14 * radius * radius;
    return area;
}

int main()
{
    float r,result;
    printf("enter the radius\n");
    scanf("%f", &r);
    result = circleArea(r);
    printf("the area of the circle is %f\t", result);
}