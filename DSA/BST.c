#include<stdio.h>
#include<malloc.h>
typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
}node;
void insert(node **root,int val)
{
    if(*root==NULL)
    {
        *root=(node*)malloc(sizeof(node));
        (*root)->data=val;
        (*root)->right=NULL;
        (*root)->left=NULL;
    }
    else
    {
        if(val<((*root)->data))
        {
            insert(&(*root)->left,val);
        }
        else
        {
            insert(&(*root)->right,val);
        }
    }
}

void preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

node *search_element(node *root,int val,node **parent)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->data==val)
    {
        return root;
    }
    else if((root->data)>val)
    {
        *parent=root;
        return search_element(root->left,val,parent);
    }
    else
    { 
        *parent=root;
        return search_element(root->right,val,parent);
    }
}


int main()
{
    int c,val;
    node *root=NULL,*res,node,*parent;
    printf("1-insert\n2-preoder\n3-search\n4-exit\n");
    do
    {
       scanf("%d",&c);
       switch(c)
       {
           case 1:printf("enter the data: ");
           scanf("%d",&val);
           insert(&root,val);
           break;
           case 3:printf("enter the element that you want to search : ");
                  scanf("%d",&val);
                 res=search_element(root,val,&parent);
                 if(res==NULL)
                 {
                     printf("element %d is not found in the tree\n",res->data);
                 }
                 else
                 {
                     printf("element %d is found in the tree\n",res->data);
                     printf("%d parent node is : %d\n",res->data,parent->data);
                 }
            break;
            case 2:preorder(root);
                  printf("\n");
                  break;
                  
            case 4:break;
           default :printf("invalid choice\n");
       }
    }while(c!=4);
}
