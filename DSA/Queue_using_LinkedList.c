#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

struct Node* enqueue(struct Node*front,struct Node*rear)
{
    struct Node*temp=malloc(sizeof(struct Node));
    int data;
    printf("Enter the data to be entered\n");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    if(front=NULL)
    {
        front=rear=temp;
    }
    rear->next=temp;
    rear=temp;
}

struct Node* dequeue(struct Node*front,struct Node*rear)
{
    struct Node*temp=front;
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    printf("The deleted element is %d",front->data);
    front=front->next;
    free(temp);
}

struct Node*peek(struct Node*front,struct Node*rear)
{
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    printf("Topmost element is %d",front->data);
}

struct Node*display(struct Node*front,struct Node*rear)
{
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    while(front!=NULL)
    {
        printf("%d",front->data);
        front=front->next;
    }
}

int main(){

    struct Node*front;
    struct Node*rear;
    int ch;
     while(1)
    {
        printf("Choices are:\n");
        printf("1-ENQUEUE\n2-DEQUEUE\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue(front,rear);
            break;

            case 2:dequeue(front,rear);
            break;

            case 3:peek(front,rear);
            break;

            case 4:display(front,rear);
            break;

            default:printf("Invalid choice\n");
            exit(0);
        }
    }
    
return 0;
}