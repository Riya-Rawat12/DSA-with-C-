#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void push_front(int *arr,int *f,int *s,int item)
{
    if(*s==MAX-1)
    {
        printf("queue overflow from front");
        return;
    }
    if(*s==-1)
        *f=0;
    *s+=1;
    arr[*s]=item;
}
void push_back(int *arr,int *f,int *s,int item)
{
    if(*f<=0)
    {
        printf("queue overflow from back\n");
        return;
    }
    *f-=1;
    arr[*f]=item;
}
void pop_front(int *arr,int *f,int *s)
{
    if(*s==MAX-1)
    {
        printf("queue overflow from front\n");
        return;
    }
    int item=arr[*s];
    *s-=1;
    if(*s==*f-1)
    {
        *f=-1;
        *s=-1;
    }
    printf("element poped at front - %d\n",item);
}
void pop_back(int *arr,int *f,int *s)
{
    if(*f==-1)
    {
        printf("queue underflow from back\n");
        return;
    }
    int item=arr[*f];
    *f+=1;
    if(*f==*s+1)
    {
        *f=-1;
        *s=-1;
    }
    printf("element poped at back - %d\n",item);
}

void top_back(int *arr,int *f,int *s)
{
    if(*f==-1 || *s==-1)
    {
        printf("queue underflow from back\n");
        return;
    }
    printf("top at back - %d\n",arr[*f]);
}
void top_front(int *arr,int *f,int *s)
{
    if(*s==MAX-1 || *f==*s)
    {
        printf("queue overflow from front\n");
        return;
    }
    printf("top at front - %d\n",arr[*s]);
}
int main()
{
    printf("Riya Rawat\nSec-E\nStudent ID-20012105");
    int arr1[MAX],arr[MAX];
    char in;
    int f=-1,s=-1;
    int choice=0,item;
    printf("press A for input restricted queue\nPress B for optput restricted queue\n");

    while(1)
    {
        in=getchar();
        if(in=='A' || in=='B' || in=='a' || in=='b'){
            printf("good to go - \n");
            break;
        }
        else
            printf("Enter from A or B\n");
    }
    int s1=0,s2=0;
    while(choice!=6)
    {
        if(in=='A' || in=='a')
        {
            printf("Choose -\n1. push\n2. pop_front\n3. pop_back\n4. top_front\n5. top_back\n6. exit\n");
            s1=1;
        }
        else
        {
            printf("Choose -\n1. push_front\n2. push_back\n3. pop\n4. top_front\n5. top_back\n6. exit\n");
            s2=1;
        }
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item\n");
            scanf("%d",&item);
            if(s1)
                push_front(arr,&f,&s,item);
            if(s2)
                push_front(arr1,&f,&s,item);
            break;
        case 2:
            if(s1)
                pop_front(arr,&f,&s);
            if(s2)
            {
                printf("Enter the item\n");
                scanf("%d",&item);
                push_back(arr1,&f,&s,item);
            }
            break;
        case 3:
            if(s1)
                pop_front(arr,&f,&s);
            if(s2)
                pop_back(arr1,&f,&s);
            break;
        case 4:
            if(s1)
                top_front(arr,&f,&s);
            if(s2)
                top_front(arr1,&f,&s);
            break;
        case 5:
            if(s1)
                top_back(arr,&f,&s);
            if(s2)
                top_back(arr1,&f,&s);
            break;
        case 6:
            printf("Thank you!");
            return 1;
        default:
            printf("Invalid choice\n");
        }
    }
}