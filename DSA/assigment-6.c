#include<stdio.h>
#include<ctype.h>

int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{ 
    printf("Riya Rawat\nSec-E\nStudent ID-20012105\n");
    char post[20];
    char *e;
    int a,b,c,n;
    printf("Enter the expression :: ");
    fgets(post,20,stdin);
    e = post;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            n = *e - 48;
            push(n);
        }
        else
        {
            a= pop();
            b= pop();
            switch(*e)
            {
            case '+':
            {
                c= a + b;
                break;
            }
            case '-':
            {
                c= b - a;
                break;
            }
            case '*':
            {
                c= a * b;
                break;
            }
            case '/':
            {
                c= b / a;
                break;
            }
            }
            push(c);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n",post,pop());
    return 0;
}
