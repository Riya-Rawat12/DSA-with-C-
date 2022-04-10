#include <stdio.h>
int main(){
    int arr[6],n,a;
    printf("Enter the elements of array\n");
    for(int i=0;i<6;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<6;i++)
    {
        n=arr[i];
        for(a=2;a<=n/2;a++)
        {
            if(n%a==0)
            printf("%d is not a prime no.",arr[i]);
        }
        if(a==n/2+1)
        {
            printf("%d is prime no.",arr[i]);
        }
        
    }
return 0;
}