#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

struct Node*push(struct Node*head)
{
    int data;
    printf("Enter the data to be inserted\n");
    scanf("%d",&data);
    if(head==NULL)
    {
        head=(struct Node*)malloc(sizeof(struct Node));
        head->data=data;
        head->next=NULL;
        return head;
    }
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=head;
    return temp;
}

struct Node*pop(struct Node*head)
{
    if(head==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
    struct Node*temp=head->next;
    free(head);
    head=temp;
    }
    return head;
}

struct Node*peek(struct Node*head)
{
    printf("The topmost element is %d",head->data);
}

struct Node*display(struct Node*head)
{
    if(head==NULL)
    {
        printf("Stack is empty\n");
    }
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}

int main(){

    struct Node*head=NULL;
    struct Node*temp=NULL;
    int ch;
     while(1)
    {
        printf("Choices are:\n");
        printf("1-PUSH\n2-POP\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=push(head);
            break;

            case 2:head=pop(head);
            break;

            case 3:peek(head);
            break;

            case 4:display(head);
            break;

            default:printf("Invalid choice\n");
            exit(0);
        }
    }
return 0;
}
