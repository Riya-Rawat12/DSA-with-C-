#include<stdio.h>

void towerOfHanoi(int n,int s,int h,int d);
int main()
{
    int n,s,h,d;
    s=1,h=2,d=3;
    printf("Enter the no. of disk\n");
    scanf("%d",&n);
    towerOfHanoi(n,s,h,d);
}

void towerOfHanoi(int n,int s,int h, int d)
{
    if(n==1)
    {
        printf("Moving %d disk with the help of %d pole to %d pole\n",n,s,d);
        return;
    }

    towerOfHanoi(n-1,s,d,h);
        printf("Moving %d disk with the help of %d pole to %d pole\n",n,s,h);
    towerOfHanoi(n-1,h,s,d);
        printf("Moving %d disk with the help of %d pole to %d pole\n",n,h,d);
}