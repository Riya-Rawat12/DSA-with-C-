#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
stack[++top] = x;
}

char pop()
{
if(top == -1)
return -1;
else
return stack[top--];
}

int pri(char x)
{
if(x == '(')
return 0;

if(x == '+' || x == '-')
return 1;

if(x == '*' || x == '/')
return 2;

return 0;
}

int main()
{
    printf("Riya Rawat\nSec-E\nStudent ID-20012105\n");
char in[100];
char *e, x;
printf("Enter the infix expression : ");
scanf("%s",in);

e = in;
while(*e != '\0') 
{
    if(isalnum(*e))
    printf("%c ",*e); 
    else if(*e == '(')
   {   
     while((x = pop()) != '(')
     printf("%c ", x);
   }
   else
  {
    while(pri(stack[top]) >= pri(*e))
    printf("%c ",pop());
    push(*e);
  }
   e++;
}
  while(top != -1)
 {
  printf("%c ",pop());
 }
return 0;
}