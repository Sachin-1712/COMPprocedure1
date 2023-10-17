#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,5};
    int length=5;
    int n=1;
    //n is the number of times the array should be rotated
      printf("Original array: \n");    
    for (int i = 0; i < length; i++)
    {     
        printf("%d ", arr[i]);     
    }     
    for(int i=0;i<n;i++)
    {
        int j,temp;
        temp=arr[length-1];
        for(j=length-1;j>0;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
    }
    printf("\n");
    printf("Array after right rotation: \n");    
    for(int i = 0; i< length; i++)
    {    
        printf("%d ", arr[i]);    
    }    
    return 0;    
}    
