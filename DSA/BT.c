#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};

void preorder(struct Node*root);

struct Node*createNode(int data)
{
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
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
    printf("\nThe postorder is \n");
    postorder(root);
    printf("\nThe inorder is\n");
    inorder(root);
    
return 0;
}