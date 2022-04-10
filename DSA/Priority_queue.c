#include<stdio.h>
#include<stdlib.h>

struct priorityqueue
{
    int element;
    int priority;
}pq[5];

int enqueue(int element,int priority,int rear);
int getpriority(int rear);
int deletepriorityelement(int rear);
void display();

int enqueue(int element,int priority,int rear)
{
    rear=rear+1;
    pq[rear].element=element;
    pq[rear].priority=priority;
}

int getpriority(int rear)
{
    int p=-1;
    if(rear==-1)
    {
        printf("Queue is empty\n");
    }
        for(int i=0;i<=rear;i++)
        {
        if(pq[i].priority>p)
        {
            p=pq[i].priority;
        }
        }
    return p;
}

int deletepriorityelement(int rear)
{
    int p,element;
    int i,j;
    p=getpriority(rear);
    for(i=0;i<=rear;i++)
    {
        if(pq[i].priority=p)
        {
            element=pq[i].element;
            break;
        }
    }
    if(i<rear)
    {
        for(j=i;j<rear;j++)
        {
            pq[j].element=pq[j+1].element;
            pq[j].priority=pq[j+1].priority;
        }
    }
    rear=rear-1;
    return element;
}

void display(int rear)
{
    if(rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=0;i<rear;i++)
        {
            printf("priority=%d, element=%d",pq[i].element,pq[i].priority);
        }
    }
}

int main()
{
    int rear=-1;
    int element,priority;
    int ch;
     while(1)
    {
        printf("Choices are:\n");
        printf("1-PUSH\n2-POP\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(rear==5-1)
            {
                printf("Queue is full\n");
            }
            printf("enter the element and priority\n");
            scanf("%d,%d",&element,&priority);
            rear=enqueue(rear,element,priority);
            rear=rear+1;
            break;

            case 2:if(rear==-1)
            {
                printf("Queue is empty\n");
            }
            element=deletepriorityelement(rear);
            rear=rear-1;
            break;

            case 3:priority=getpriority(rear);
            break;

            case 4:display(rear);
            break;

            default:printf("Invalid choice\n");
            exit(0);
        }
    }
return 0;
}