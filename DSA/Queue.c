#include <stdio.h>
#include<stdlib.h>
#define MAX 100

int enqueue(int queue[],int rare,int front);
int dequeue(int queue[],int rare,int front);
void peek(int queue[],int rare,int front);
void display(int queue[],int rare,int front);

int enqueue(int queue[],int rare,int front)
{
    int value;
    if(rare==MAX-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
    printf("Enter the data to be entered\n");
    scanf("%d",&value);
    queue[++rare]=value;
    return rare;
    }
}

int dequeue(int queue[],int rare,int front)
{
    if(front==-1 || front>rare)
    {
        printf("Queue is empty\n");
    }
    else
    {
    printf("Deleted element is %d",queue[front]);
    front++;
    }
    return front;
}

void peek(int queue[],int rare,int front)
{
    if(front==-1 || front>rare)
    {
        printf("Queue is empty\n");
    }
    else
    {
    printf("Topmost element is %d",queue[rare]);
    }
}

void display(int queue[],int rare,int front)
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=front;i<=rare;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}


int main(){

    int queue[MAX];
    int rare=-1;
    int front=-1;
    int ch;
     while(1)
    {
        printf("Choices are:\n");
        printf("1-PUSH\n2-POP\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue(queue,rare,front);
            rare++;
            if(front==-1)
            {
                front=0;
            }
            break;

            case 2:dequeue(queue,rare,front);
            front++;
            break;

            case 3:peek(queue,rare,front);
            break;

            case 4:display(queue,rare,front);
            break;

            default:printf("Invalid choice\n");
            exit(0);
        }
    }
return 0;
}