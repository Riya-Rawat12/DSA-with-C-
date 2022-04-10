#include <stdio.h>
#include<stdlib.h>
#define MAX 100
int push(int *arr,int top);
int pop(int *arr,int top);
int peek(int *arr,int top);
void display(int *arr,int top);

int main(){
    int stack[MAX];
    int n,ch;
    int top=-1;
    
    while(1)
    {
        printf("****************MENU*************\n");
        printf("1-PUSH\n2-POP\n3-PEEK\n4-DISPLAY\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1:top=push(stack,top);
            break;
            case 2:top=pop(stack,top);
            break;
            case 3:top=peek(stack,top);
            break;
            case 4:display(stack,top);
            break;
            default:printf("Wrong choice");
            exit(0);
        }
    }
return 0;
}

int push(int*arr,int top)
{
    int data;
    if(top==MAX-1)
    {
        printf("Stack is full\n");
    }

    printf("Enter the data:");
    scanf("%d",&data);
    top++;
    arr[top]=data;
    return top;
}

int pop(int *arr,int top)
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }

    printf("Deleted element is %d",arr[top]);
    top-=1;
    return top;
}

int peek(int *arr,int top)
{
    printf("Topmost element is %d",arr[top]);
    return top;
}

void display(int *arr,int top)
{
    for(int i=top;i>=0;i--)
    {
        printf("%d",arr[i]);
    }
}