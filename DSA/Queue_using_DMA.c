#include <stdio.h>
#include<stdlib.h>
typedef struct QUEUE_USING_DMA
{
    int size;
    int *data;
    int front;
    int rare;
}queue;

queue*create(int size)
{   
    queue*q1=(queue*)malloc(sizeof(queue));
    q1->front=-1;
    q1->rare=-1;
    q1->size=size;
    q1->data=(int*)malloc(sizeof(int)*size);
    return q1;
}

void enqueue(queue*q1)
{
    int data;
    if(q1->rare==q1->size-1)
    {
        q1->data=(int*)realloc(q1->data,q1->size+5);
    }
    else
    {
        if(q1->front==-1)
        {
            q1->front=0;
        }
        printf("Enter the data to be entered\n");
        scanf("%d",&data);
        q1->data[++q1->rare]=data;

    }
    return;
}

void dequeue(queue*q1)
{
    if(q1->front==-1 || q1->front>q1->rare)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element is %d",q1->data[q1->front++]);
    }
}

void peek(queue*q1)
{
    if(q1->front==-1 || q1->front>q1->rare)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("1st elemet is %d",q1->data[q1->rare]);
    }
}

void display(queue*q1)
{
    if( q1->front>q1->rare)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=q1->front;i<=q1->rare;i++)
        {
            printf("%d ",q1->data[i]);
        }
    }
}

int main(){
    
    int n;
    printf("Enter the size of queue\n");
    scanf("%d",&n);
    queue *q1=create(n);
    int ch;
     while(1)
    {
        printf("Choices are:\n");
        printf("1-PUSH\n2-POP\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue(q1);
            break;

            case 2:dequeue(q1);
            q1->front++;
            break;

            case 3:peek(q1);
            break;

            case 4:display(q1);
            break;

            default:printf("Invalid choice\n");
            exit(0);
        }
    }
return 0;
}