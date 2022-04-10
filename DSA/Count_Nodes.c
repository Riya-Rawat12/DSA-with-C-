#include <stdio.h>
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
    int size;
    int front;
    int rear;
    struct Node**queue;
};

void createQueue(struct Queue*q,int size)
{
    q->size=size;
    q->front=-1;
    q->rear=-1;
    q->queue=(struct Node**)malloc(sizeof(struct Node*));
}

void enqueue(struct Queue*q,struct Node*root)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->queue[q->rear]=root;
    }
}

struct Node*dequeue(struct Queue*q)
{
    struct Node*x=NULL;
    if(q->rear==q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->queue[q->front];
    }
}

int isempty(struct Queue q)
{
    return q.rear==q.front;
}

void create(struct Node*root)
{
    struct Node*p,*t;
    struct Queue q;
    createQueue(&q,100);
    int data;
    printf("Enter the data of the root ");
    scanf("%d",&data);
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    enqueue(&q,root);
    while(!isempty(q))
    {
        p=dequeue(&q);
        printf("Enter the left child data of %d ",p->data);
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
        printf("Enter the right child data of %d ",p->data);
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

int count(struct Node*root)
{
    int x,y;
    if(root!=NULL)
    {
        x=count(root->left);
        y=count(root->right);
        return x+y+1;
    }
    return 0;
}
int main(){
    struct Node*root;
    create(root);
    count(root);
return 0;
}