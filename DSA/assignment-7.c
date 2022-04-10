#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
    
void push(char ch)
{
    if(top==MAX-1)
    printf("Stack is full\n");
    else
    stack[++top]=ch;
}
char pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
int priority(char ch)
{
    if(ch=='(')
    return 0;
    if(ch=='+'||ch=='-')
    return 1;
    if(ch=='*'||ch=='/')
    return 2;
    if(ch=='^')
    return 3;
    
    return 0;
}
int main()
{  
 
    char ex[MAX],ex1[MAX],ex2[MAX],*temp,ch;
    printf("Enter the expression:  ");
    scanf("%s",ex);
    int i=0,l,j=0;
    l=strlen(ex)-1;
    while(l>=0)
    {
        if(ex[l]=='(')
        ex1[i]=')';
        else if(ex[l]==')')
        ex1[i]='(';
        else
        ex1[i]=ex[l];
        i++;
        l--;
    }
    ex1[i]='\0';
    printf("%s",ex1);
    temp=ex1;
    printf("The Prefix expression:  ");
    while(*temp!='\0')
    {
        if(isalnum(*temp))
        {
             ex2[j]=*temp;
             j++;
        }
        else if(*temp=='(')
        push(*temp);
        else if(*temp==')')
        {
            while((ch=pop())!='(')
            {
                ex2[j]=ch;
                j++;
            }
        }
        else
        {
            while(priority(stack[top])>=priority(*temp))
            {
                ex2[j]=pop();
                j++;
            }
            push(*temp);
        }
        temp++;
    }
    while(top!=-1)
    {
        ex2[j]=pop();
        j++;
    }
    ex2[j]='\0';
    i=0,l=strlen(ex2)-1;
    while(i<l)
    {
        char t=ex2[i];
        ex2[i]=ex2[l];
        ex2[l]=t;
        l--;
        i++;
    } 
    printf("%s",ex2);
    return 0;
}