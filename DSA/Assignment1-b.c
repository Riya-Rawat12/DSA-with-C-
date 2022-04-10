#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of the array\n");
    for(int i=0;i<6;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<6;i++)
    {
        if(i%2==0 &&i!=0)
        {
            arr[i/2]=arr[i];
        }
    }
    if(n%2==0)
    {
        n=n-1;
    }

    for(int i=0;i<=n/2;i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}