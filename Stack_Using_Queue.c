#include <stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct Stack_Using_DMA
{
    int size;
    int top;
    int *data;
}stack;

stack* create(int size);
int enqueue(stack *s1,stack*s2,int data);
int pop(stack*s1);
int dequeue(stack*s1,stack*s2);
int peek(stack*s1);
void display(stack*s1);

stack* create(int size)
{
    stack*s1=(stack*)malloc(sizeof(stack));
    s1->size=size;
    s1->data=(int*)malloc(sizeof(int)*size);
    s1->top=-1;
}

int enqueue(stack *s1,stack*s2,int data)
{
    if(s1->top==s1->size-1)
    {
        s1->data=(int*)realloc(s1->data,s1->size+5);
        s1->size+=5;
        s2->data=(int*)realloc(s2->data,s2->size+5);
        s2->size+=5;
    }
    if(s1->top==-1)
    {
        s1->data[++s1->top]=data;
    }
    else
    {
        while(s1->top!=-1)
        {
            s2->data[++s2->top]=peek(s1);
            pop(s1);
        }
        s1->data[++s1->top]=data;
        while(s2->top!=-1)
        {
            s1->data[++s1->top]=peek(s2);
            pop(s2);
        }
    }
    
}

int dequeue(stack*s1,stack*s2)
{
    if(s1->top==-1&&s2->top==-1)
    {
        printf("Queue is empty\n");
    }
    printf("Deleted element is %d\n",pop(s1));
}

int pop(stack*s1)
{
    if(s1->top==-1)
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return s1->data[s1->top--];
}

int peek(stack*s1)
{
    if(s1->top==-1)
    {
        printf("Stack is empty\n");
    }
    return s1->data[s1->top];
}

void display(stack*s1)
{
    if(s1->top==-1)
    {
        printf("Stack is empty\n");
    }
    for(int i=s1->top;i>=0;i--)
    {
        printf("%d",s1->data[i]);
    }
}



int main(){
    stack*s1 = create(4);
    stack*s2 = create(4);
    int ch,data;
    while(1)
    {
        printf("Choices are:\n");
        printf("1-PUSH\n2-POP\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data to be entered\n");
            scanf("%d",&data);
            enqueue(s1,s2,data);
            break;

            case 2:dequeue(s1,s2);
            break;

            case 3:data=peek(s1);
            printf("%d",data);
            break;

            case 4:display(s1);
            break;

            default:printf("Invalid choice\n");
            exit(0);
        }
    }
return 0;
}
