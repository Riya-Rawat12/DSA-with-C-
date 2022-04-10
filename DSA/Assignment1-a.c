#include <stdio.h>
int main(){
    int arr[100];
    printf("Enter the elements of array\n");
    for(int i=0;i<6;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max,smax,min,smin;
    max=smax=0;
    min=smin=arr[3];
    for(int i=0;i<6;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    printf("%d",max);
    for(int i=0;i<6;i++)
    {
        if(smax<arr[i] && arr[i]!=max)
        {
            smax=arr[i];
        }
    }
    printf("%d",smax);
    for(int i=0;i<6;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
        }
    }
    printf("%d",min);
    for(int i=0;i<6;i++)
    {
        if(smin>arr[i] && arr[i]!=min)
        {
            smin=arr[i];
        }
    }
    printf("%d",smin);
return 0;
}