#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

struct Node*enqueue(struct Node*head,struct Node*front,struct Node*rear)
{
    int data;
    head=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data to be inserted\n");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    if(front==NULL)
    {
        front=rear=head;
        return front;
    }
    else
    {
        rear->next=head;
        rear=head;
        return rear;
    }
}

struct Node*dequeue(struct Node*head,struct Node*front,struct Node*rear)
{
    if(front==NULL)
    {
        printf("Queue is empty we cannot delete element\n");
    }
    else
    {
        struct Node*temp=front;
        printf("Deleted element is %d",front->data);
        front=front->next;
        free(temp);
        return front;
    }
}

struct Node*peek(struct Node*head,struct Node*front,struct Node*rear)
{
    if(front==NULL)
    {
        printf("Queue is empty");
    }
    printf("The topmost element is %d",rear->data);
}

struct Node*display(struct Node*head,struct Node*front,struct Node*rear)
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    while(front!=NULL)
    {
        printf("%d ",front->data);
        front=front->next;
    }
}

int main(){

    struct Node*head;
    struct Node*front=NULL;
    struct Node*rear=NULL;
    int ch;
     while(1)
    {
        printf("Choices are:\n");
        printf("1-ENQUEUE\n2-DEQUEUE\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=enqueue(head,front,rear);
            break;

            case 2:head=dequeue(head,front,rear);
            break;

            case 3:peek(head,front,rear);
            break;

            case 4:display(head,front,rear);
            break;

            default:printf("Invalid choice\n");
            exit(0);
        }
    }
    
return 0;
}