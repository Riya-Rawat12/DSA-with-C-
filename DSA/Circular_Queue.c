#include <stdio.h>
#include<stdlib.h>
#define MAX 4

void enqueue(int arr[],int front,int rare,int data);
void dequeue(int arr[],int front,int rare);
void peek(int arr[],int front,int rare);
void display(int arr[],int front,int rare);

void enqueue(int arr[],int front,int rare,int data)
{
    if(front==-1)
    {
        front=0;
        rare=0;
        arr[rare]=data;
    }
    else if((rare==MAX-1&&front==0)|| front==rare+1)
    {
        printf("Queue is full\n");
    }
    else if(rare==MAX-1&&front!=0)
    {
        rare=(rare+1)%MAX;
        arr[rare]=data;
    }
    else
    {
        arr[++rare]=data;
    }
    
}

void dequeue(int arr[],int front,int rare)
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element is %d\n",arr[front]);
        front++;
    }
    
}

void peek(int arr[],int front,int rare)
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Topmost element is %d\n",arr[rare]);
    }
}

void display(int arr[],int front,int rare)
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    for(int i=front;i<=rare;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main(){
    int front,rare;
    front=rare=-1;
    int arr[MAX];
    int ch;
    int data;
    while(1)
    {
        printf("1-ENQUEUE\n2-DEQUEUE\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the data to be entered\n");
            scanf("%d",&data);
            enqueue(arr,front,rare,data);
            rare=(rare+1)%MAX;
            if(front==-1)
            {
                front=0;
            }
            break;
            case 2: dequeue(arr,front,rare);
            front=(front+1)%MAX;
            break;
            case 3: peek(arr,front,rare);
            break;
            case 4: display(arr,front,rare);
            break;
            default: printf("Wrong choice\n");
            exit(0);
        }
    }
return 0;
}