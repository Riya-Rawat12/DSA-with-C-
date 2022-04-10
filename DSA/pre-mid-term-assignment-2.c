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

void display(Stack *s1)
{
    int i;
    if (s1->top == -1)
    {
        printf("\nQueue is empty!!\n");
    }
    else
    {
        for (i = s1->top; i >= 0; --i)
            printf("%d ", s1->data[i]);
        printf("\n");
    }
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

void Dequeue(Stack *s1, Stack *s2)
{
    if (s1->top == -1 && s2->top == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    pop(s1);
    return;
}

void Enqueue(int data, Stack *s1, Stack *s2)
{
    if (s1->top == s1->size - 1)
    {
        s1->data = (int *)realloc(s1->data, s1->size + 5);
        s1->size = s1->size + 5;
        s2->data = (int *)realloc(s2->data, s2->size + 5);
        s2->size = s2->size + 5;
    }

    if (s1->top == -1)
        s1->data[++s1->top] = data;

    else
    {
        while (s1->top != -1)
        {
            s2->data[++s2->top] = peek(s1);
            pop(s1);
        }

        s1->data[++s1->top] = data;

        while (s2->top != -1)
        {
            s1->data[++s1->top] = peek(s2);
            pop(s2);
        }
    }
    return;
}

int main()
{
    Stack *s1 = create(5);
    Stack *s2 = create(5);

    while (1)
    {
        printf("Enter your Choice : 1.Enqueue\n2.Dequeue\n3.Front\n 4.Display\n.Exit\n");
        int choice, value;
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter data : ");
            scanf("%d", &value);
            Enqueue(value, s1, s2);
            break;

        case 2:
            Dequeue(s1, s2);
            break;

        case 3:
            value = peek(s1);
            printf("%d\n", value);
            break;

        case 4:
            display(s1);
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}