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
void push(stack *s1,int data);
int pop(stack*s1);
void peek(stack*s1);
void display(stack*s1);

stack* create(int size)
{
    stack*s1=(stack*)malloc(sizeof(stack));
    s1->size=size;
    s1->data=(int*)malloc(sizeof(int)*size);
    s1->top=-1;
}

void push(stack *s1,int data)
{
    if(s1->top==s1->size-1)
    {
        s1->data=(int*)realloc(s1->data,s1->size+5);
        s1->size+=5;
    }

    s1->data[++s1->top]=data;
}

int pop(stack*s1)
{
    if(s1->top==-1)
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    printf("Deleted element is %d",s1->data[s1->top]);
    return s1->top--;
}

void peek(stack*s1)
{
    if(s1->top==-1)
    {
        printf("Stack is empty\n");
    }
    printf("Topmost element is-%d",s1->data[s1->top]);
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
            push(s1,data);
            break;

            case 2:pop(s1);
            break;

            case 3:peek(s1);
            break;

            case 4:display(s1);
            break;

            default:printf("Invalid choice\n");
            exit(0);
        }
    }
return 0;
}