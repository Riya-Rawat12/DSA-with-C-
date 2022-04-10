#include <stdio.h>
#include<stdlib.h>
#define N 100
int enqueue(int rare,int front,int Q[N],int Pr[N],int data,int prior);
int dequeue(int rare,int front,int Q[N],int Pr[N],int data,int prior);
int display(int rare,int front,int Q[N],int Pr[N],int data,int prior);

int enqueue(int rare,int front,int Q[N],int Pr[N],int data,int prior)
{
    if(front==0 && rare==N-1)
    {
        printf("queue is full\n");
    }
    else if(front==rare==-1)
    {
        front=0;
        rare=0;
        Q[rare]=data;
        Pr[rare]=prior;
        return rare;
    }
    else if(rare==N-1)
    {
        for(int i=front;i<=rare;i++)
        {
            Q[i-front]=Q[i];
            Pr[i-front]=Pr[i];
            rare=rare-front;
            front=0;
            return front;
        }
        for(int i=rare;i>front;i--)
        {
            if(prior>Pr[i])
            {
                Q[i+1]=Q[i];
                Pr[i+1]=Pr[i];
            }
            else
            break;
            Q[i+1]=data;
            Pr[i+1]=prior;
            rare++;
            return rare;
        }
    }
    else
    {
        for(int i=rare;i>front;i--)
        {
            if(prior>Pr[i])
            {
                Q[i+1]=Q[i];
                Pr[i+1]=Pr[i];
            }
            else
            break;
            Q[i+1]=data;
            Pr[i+1]=prior;
            rare++;
            return rare;
        }
    }
}

int dequeue(int rare,int front,int Q[N],int Pr[N],int data,int prior)
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element %d ,it's priority %d\n",Q[front],Pr[front]);
        if (front==rare);
        front=rare=-1;
        front++;
        return front;
    }
}

int display(int rare,int front,int Q[N],int Pr[N],int data,int prior)
{
    for(int i=front;i<=rare;i++)
    {
        printf("Element is %d ,priority is %d\n",Q[i],Pr[i]);
    }
}

int main(){
    int data,prior;
    int rare=-1;
    int front=-1;
    int Q[N],Pr[N];
    int choice;
    while(1)
    {
        printf("Choices are\n");
        printf("1-Insert\n2-Delete\n3-Display\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the data to be inserted\n");
            scanf("%d",&data);
            printf("Enter its priority\n");
            scanf("%d",&prior);
            enqueue(rare,front,Q,Pr,data,prior);
            rare++;
            if(front=rare=-1)
            {
                front=rare=0;
                rare++;
            }
            break;
            case 2:dequeue(rare,front,Q,Pr,data,prior);
            front++;
            break;
            case 3:display(rare,front,Q,Pr,data,prior);
            break;
            case 4:printf("Exit\n");
            exit(0);
            default:printf("Wrong choice");
            break;
        }
    }
return 0;
}