#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct Stacks_Using_DMA
{
    int *data;
    int top;
    int size;
} Stack;

void push(Stack *s1, int data);
int pop(Stack *s1);
int peek(Stack *s1);
Stack *create(int size);

Stack *create(int size)
{
    Stack *s1 = (Stack *)malloc(sizeof(Stack));
    s1->size = size;
    s1->data = (int *)malloc(sizeof(int) * size);
    s1->top = -1;
    return s1;
}

void push(Stack *s1, int data)
{
    if (s1->top == s1->size - 1)
    {
        s1->data = (int *)realloc(s1->data, s1->size + 5);
        s1->size = s1->size + 5;
    }
    s1->data[++s1->top] = data;
}

void insert(Stack *s1, int data)
{
    int ind = s1->top;
    while (ind != -1 && data < s1->data[ind])
    {
        s1->data[ind + 1] = s1->data[ind];
        ind--;
    }

    s1->data[ind + 1] = data;
    s1->top++;
    return;
}

int peek(Stack *s1)
{
    if (s1->top == -1)
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return s1->data[s1->top];
}

int pop(Stack *s1)
{
    if (s1->top == -1)
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return s1->data[s1->top--];
}


void sort(Stack *s1)
{
    if (s1->top == 0)
        return;
    int data = peek(s1);
    pop(s1);
    sort(s1);
    insert(s1, data);
    return;
}

void display(Stack *s1)
{
    int i;
    if (s1->top == -1)
        printf("\nStack is empty!!");
    else
    {
        printf("\nStack is...\n");
        for (i = s1->top; i >= 0; --i)
            printf("%d ", s1->data[i]);
        printf("\n");
    }
}

int main()
{
    Stack *s1 = create(5);

    while (1)
    {
        printf("1. Push\n2. Pop\n3. Peek\n4. Sort\n5. Display\n6. Exit\n");
        int choice, value;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element To push : ");
            scanf("%d", &value);
            push(s1, value);
            break;
        case 2:
            value = pop(s1);
            printf("%d is the popped element \n", value);
            break;
        case 3:
            value = peek(s1);
            printf("%d is the top element\n", value);
            break;
        case 4:
            sort(s1);
            break;
        case 5:
            display(s1);
            break;
        case 6:
            return 0;
        default:
            printf("Enter valid choice \n");
            break;
        }
    }
    return 0;
}
