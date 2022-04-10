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
    if(root==NULL)
    return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node*root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void inorder(struct Node*root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void levelorder(struct Node*root)
{
    struct Queue q;
    createQueue(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);
    while(!isempty(q))
    {
        root=dequeue(&q);
        if(root->left)
        {
            printf("%d ",root->left->data);
            enqueue(&q,root->left);
        }
        if(root->right)
        {
            printf("%d ",root->right->data);
            enqueue(&q,root->right);
        }
    }
}

int main()
{
    struct Node*root=(struct Node*)malloc(sizeof(struct Node));
    create(root);
    printf("The preorder is\n");
    preorder(root);
    printf("\nThe postorder is \n");
    postorder(root);
    printf("\nThe inorder is\n");
    inorder(root);
    printf("\nThe level order is\n");
    levelorder(root);
}