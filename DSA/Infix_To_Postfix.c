#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct Stack
{
    int size;
    int top;
    char *arr;
};

int peek(struct Stack*stack)
{
    return stack->arr[stack->top];
}

int isEmpty(struct Stack*stack)
{
    if(stack->top==-1)
    {
        return 1;
    }
    else
     return 0;
}

int isFull(struct Stack*stack)
{
    if(stack->top==stack->size-1)
    {
        return 1;
    }
    else
     return 0;
}

void push(struct Stack*stack,char data)
{
    if(isFull(stack))
    {
        printf("stack is full\n");
    }
    else
    {
        stack->arr[++stack->top]=data;
    }
}

char pop(struct Stack*stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty\n");
    }
    else{
        char data=stack->arr[stack->top];
        stack->top--;
        return data;
    }
}

int isOperator(char ch)
{
    if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
    return 1;
    else
    return 0;
}

int precedence(char ch)
{
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*'||ch=='/')
    {
        return 2;
    }
    else if(ch=='+'||ch=='-')
    return 1;
    else
    return 0;
}

char *InfixToPostfix(char *infix)
{
    struct Stack*stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->size=MAX;
    stack->top=-1;
    stack->arr=(char*)malloc(stack->size*sizeof(char));
    char*postfix=(char*)malloc(strlen(infix)+1*sizeof(char));
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            j++,i++;
        }
        else
        { 
        if(precedence(infix[i])>precedence(peek(stack)))
        {
            push(stack,infix[i]);
            i++;
        }
        if(precedence(infix[i])<precedence(peek(stack)))
        {
            postfix[j]=pop(stack);
            j++;
        }
        }
    }
    while(!isEmpty)
    {
        postfix[j]=pop(stack);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

void reverse(char*infix)
{
    int length=strlen(infix);
    int i=0;
    int j=length-1;

    while(i<j)
    {
        char temp;
        if(infix[i]=')')
        temp='(';
        else if(infix[i]='(')
        temp=')';
        else
        temp=infix[i];
        if(infix[j]=')')
        infix[i]='(';
        else if(infix[j]='(')
        infix[i]=')';
        else
        infix[i]=infix[j];
        infix[j]=temp;
        i++;
        j--;
    }
    return;
}
int main()
{
    char infix[50];
    printf("Enter the infix expression\n");
    scanf("%s",&infix);
    reverse(infix);
    InfixToPostfix(infix);
    reverse(infix);
    printf("%s",infix);

    // printf("Postfix expression is %s",InfixToPostfix(infix));
    // return 0;
}