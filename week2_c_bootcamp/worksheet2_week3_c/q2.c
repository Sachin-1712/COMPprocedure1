#include <stdio.h>


float sphereVolume(float radius)
{
    float volume;
    volume = (3.14 * radius * radius * radius)*4/3;
    return volume; 
}

int main()
{
    float r,result;
    printf("enter the raidus\n");
    scanf("%f", &r);
    result = sphereVolume(r);
    printf("the volume of the sphere is %f\t", result);
}