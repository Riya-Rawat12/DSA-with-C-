#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};

void createNode(struct Node*root,int data)
{
    root->data=data;
    root->left=NULL;
    root->right=NULL;
}

struct stack
{
    int size;
    int top;
    struct Node**stack;
};

void createStack(struct stack*s,int size)
{
    s->size=size;
    s->top=-1;
    s->stack=(struct Node**)malloc(sizeof(struct Node*));
}

struct Queue
{
    int front;
    int rear;
    int size;
    struct Node**Queue;
};

void createQueue(struct Queue*q,int size)
{
    q->size=size;
    q->front=0;
    q->rear=0;
    q->Queue=(struct Node**)malloc(sizeof(struct Node*));
}

void push(struct stack*s,struct Node*data)
{
    if(s->top==-s->size-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        s->stack[s->top++];
        s->stack[s->top]=data;
    }
}

struct Node*pop(struct stack*s)
{
    struct Node*x=NULL;
    if(s->top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        x=s->stack[s->top];
        s->stack[s->top--];
    }
    return x;
}

int isemptystack(struct stack s)
{
    return s.top==-1;
}

void enqueue(struct Queue*q,struct Node* data)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Queue[q->rear]=data;
    }
}

struct Node*dequeue(struct Queue*q)
{
    struct Node*x=NULL;
    if(q->rear==q->front)
    {
        printf("Queue is empty");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Queue[q->front];
    }
}

int isempty(struct Queue q)
{
    return q.front==q.rear;
}

void create(struct Node*root)
{
    struct Node*p,*t;
    int data;
    struct Queue q;
    createQueue(&q,100);
    printf("Enter the data of root ");
    scanf("%d",&data);
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    enqueue(&q,root);

    while(!isempty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d ",p->data);
        scanf("%d",&data);
        if(data!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=data;
            t->left=NULL;
            t->right=NULL;
            p->left=t;
            enqueue(&q,t);
        }
         printf("Enter right child of %d ",p->data);
        scanf("%d",&data);
        if(data!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=data;
            t->left=NULL;
            t->right=NULL;
            p->right=t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node*root)
{
    struct stack s;
    createStack(&s,100);
    while(root||!isemptystack(s))
    {
        if(root!=NULL)
        {
            printf("%d ",root->data);
            push(&s,root);
            root=root->left;
        }
        else
        {
            root=pop(&s);
            root=root->right;
        }
    }
}

void inorder(struct Node*root)
{
    struct stack s;
    createStack(&s,100);
    while(root||!isemptystack(s))
    {
        if(root!=NULL)
        {
            push(&s,root);
            root=root->left;
        }
        else
        {
            root=pop(&s);
            printf("%d ",root->data);
            root=root->right;
        }
    }
}

void postorder(struct Node*root)
{
    struct stack s;
    struct Node* temp;
    while(root || !isemptystack(s))
    {
        if(root!=NULL)
        {
            push(&s,root);
            root=root->left;
        }
        else
        temp=pop(&s);
        if(temp>0)
        {
            push(&s,temp);
            root=temp->right;
        }
        else
        {
            printf("%d ",temp->data);
            root=NULL;
        }
    }
}

int main()
{
    struct Node*root=(struct Node*)malloc(sizeof(struct Node));
    create(root);
    // printf("The preorder is\n");
    // preorder(root);
    printf("\nThe postorder is \n");
    postorder(root);
    // printf("\nThe inorder is\n");
    // inorder(root);
}