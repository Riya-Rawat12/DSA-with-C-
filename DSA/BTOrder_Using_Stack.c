#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node*left;
    struct Node*right;
};

struct Stack
{
    int size;
    int top;
    struct Node**data;
};

void createStack(struct Stack*arr,int size)
{
    arr->size=size;
    arr->top=-1;
    arr->data=(struct Node**)malloc(sizeof(struct Node*));
}

struct Node*createNode(int value)
{
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->value=value;
    temp->left=NULL;
    temp->right=NULL;
}

int IsEmpty(struct Stack arr)
{
    if(arr.top==-1)
    return 1;
}

int IsFull(struct Stack arr)
{
    return arr.top==arr.size-1;
}

void push(struct Stack*arr,struct Node*root)
{
    if(arr->top==arr->size-1)
    {
        printf("Stack is full");
    }
    else
    {
        arr->top++;
        arr->data[arr->top]=root;
    }
}

struct Node*pop(struct Stack*arr)
{
    struct Node*root;
    if(arr->top==-1)
    {
        printf("Stack is empty");
    }
    else{
        root=arr->data[arr->top--];
    }
    return root;
}

void preorder(struct Node*root)
{
    struct Stack stack;
    createStack(&stack,100);
    while(root || !IsEmpty(stack))
    {
        if(root)
        {
        printf("%d ",root->value);
        push(&stack,root);
        root=root->left;
        }
        else
        {
            root=pop(&stack);
            root=root->right;
        }
    }
}

int main(){
    struct Node*root=createNode(3);
    root->left=createNode(4);
    root->right=createNode(5);
    root->left->left=createNode(6);
    root->left->right=createNode(7);
    root->left->left->left=createNode(8);
    root->left->right->right=createNode(9);
    root->left->right->left=createNode(10);
    root->right->left=createNode(11);
    root->right->right=createNode(13);
    root->right->right->right=createNode(14);
    printf("The preorder is\n");
    preorder(root);
return 0;
}