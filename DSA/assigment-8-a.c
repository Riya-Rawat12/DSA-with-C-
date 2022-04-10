#include<stdio.h>
void toh(int n,char S,char D,char A)
{
       if(n==1)
       {
              printf("\nMove Disk %d from %c to %c",n,S,D);
              return;
        }
        toh(n-1,S,A,D);
        printf("\nMove disk %d from %c to %c",n,S,D);
        toh(n-1,A,D,S);
}
int main()
{
    printf("Riya Rawat\nSec-E\nStudent ID-20012105\n");
       int n;
       printf("Enter number of disk:");
       scanf("%d",&n);
       toh(n,'S','D','A');
       return 0;
}       