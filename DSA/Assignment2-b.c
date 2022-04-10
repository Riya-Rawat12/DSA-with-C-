#include <stdio.h>
int main(){
    int a,b,c;
    int arr[5];
    printf("Enter the elements of array\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++)
    {
        c=arr[i];
        while(arr[i]!=0)
        {
            a=c%10;
            b=b*10+a;
            c=c/10;
        }
        if(c==b)
        {
            printf("%d is palindrome",arr[i]);
        }
    }
return 0;
}